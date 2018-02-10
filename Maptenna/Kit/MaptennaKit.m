//
//  MaptennaKit.m
//  Maptenna
//
//  Created by Ryan Cohen on 4/29/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

#import "MaptennaKit.h"
#import "MTNodeRequest.h"

#define MIN_TLV 2

const NSString *kMaptennaLocationRequestKey = @"kMaptennaLocationRequest";

@interface MaptennaKit () <CLLocationManagerDelegate>

@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic, strong) NSTimer *timer;

@end

@implementation MaptennaKit

# pragma mark - Init

+ (instancetype)shared {
    static MaptennaKit *kit = nil;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        kit = [self new];
    });
    
    return kit;
}

- (instancetype)init {
    self = [super init];
    
    if (self) {
        dispatch_async(dispatch_get_main_queue(), ^{
            self.locationManager = [CLLocationManager new];
            self.locationManager.delegate = self;
            self.locationManager.desiredAccuracy = kCLLocationAccuracyBest;
            [self.locationManager startUpdatingLocation];
        });
        
        __weak typeof(self) weakSelf = self;
        
        [[GTCommandCenter shared] setOnIncomingMessage:^(GTMessageData *response) {
            if ([response isKindOfClass:[GTMessageData class]]) {
                /* Node update request */
                if ([response.addressedGID isEqualToNumber:[GIDManager shoutGID]]) {
                    [weakSelf parseIncomingMessage:response block:^(MTNodeRequest *request) {
                        if ([weakSelf.delegate respondsToSelector:@selector(maptenna:didReceiveNodeUpdateRequest:)]) {
                            [weakSelf.delegate maptenna:weakSelf didReceiveNodeUpdateRequest:request];
                        }
                    }];
                } else {
                    /* Node update */
                    [weakSelf parseIncomingMessage:response block:^(MTNode *node) {
                        if ([weakSelf.delegate respondsToSelector:@selector(maptenna:didReceiveNodeUpdate:)]) {
                            [weakSelf.delegate maptenna:weakSelf didReceiveNodeUpdate:node];
                        }
                    }];
                }
            }
        }];
    }
    
    return self;
}

# pragma mark - User

- (void)updateUserWithGID:(NSNumber *)gid name:(NSString *)name block:(MaptennaUserUpdateBlock)block {
    [[GTCommandCenter shared] setgoTennaGID:gid withUsername:name onError:^(NSError *error) {
        block(nil, nil, error);
    }];
    
    MTUser *user = [[MTUser currentUser] initWithGID:gid name:name];
    MTNode *node = [[MTNode currentNode] initWithOwner:user location:nil];
    
    block(user, node, nil);
}

# pragma mark - Location

- (void)updateDeviceLocationForGID:(nonnull NSNumber *)gid block:(nullable MaptennaErrorBlock)block {
    // TODO: Validate GID
    if (!gid) return;
    
    CLLocation *location = [self.locationManager location];
    NSNumber *latitude = @(location.coordinate.latitude);
    NSNumber *longitude = @(location.coordinate.longitude);
    
    NSLog(@"**** SENDING FROM (%@, %@)", latitude, location);
    
    GTLocationMessageData *locationData = [[GTLocationMessageData alloc] initWithLocationType:@3
                                                                                  andLatitude:latitude
                                                                                 andLongitude:longitude
                                                                                      andName:[[MTNode currentNode] displayName]
                                                                                      onError:nil];
    
    GTLocationOnlyMessageData *messageData = [[GTLocationOnlyMessageData alloc] initOutgoingWithLocation:locationData onError:nil];
    
    [[GTCommandCenter shared] sendMessage:[messageData serializeToBytes] encrypt:NO toGID:gid fromGID:[[MTNode currentNode] owner].gid onResponse:^(GTResponse *response) {
        NSLog(@"%@ %@", NSStringFromSelector(_cmd), response.responseCode == GTResponsePositive ? @"Positive" : @"Negative");
        [[MTNode currentNode] updateNodeLocation:[[CLLocation alloc] initWithLatitude:latitude.floatValue longitude:longitude.floatValue]];
        
        block(nil);
    } onError:^(NSError *error) {
        NSLog(@"Error: %@", error);
        block(error);
    }];
}

- (void)requestNearbyNodesUpdate:(nullable MaptennaErrorBlock)block {
    if (![MTUser currentUser] || ![MTNode currentNode]) return;
    
    MTNodeRequest *request = [[MTNodeRequest alloc] initWithHashedIdentifier:[MTNode currentNode].identifier];
    
    NSLog(@"*** Making node request ***");
    
    [[GTCommandCenter shared] sendBroadcast:[request serializeToBytes] toGID:[GIDManager shoutGID] onResponse:^(GTResponse *response) {
        NSLog(@"%@ %@", NSStringFromSelector(_cmd), response.responseCode == GTResponsePositive ? @"Positive" : @"Negative");
        if (block) block(nil);
    } onError:^(NSError *error) {
        NSLog(@"Error: %@", error);
        block(error);
    }];
}

# pragma mark - Helpers

- (void)parseIncomingMessage:(nonnull GTMessageData *)response block:(nonnull MaptennaParseIncomingBlock)block {
    NSArray<TLVSection *> *tlvSections = [TLVSection tlvSectionsFromData:response.commandData];
    
    if (tlvSections.count < MIN_TLV) {
        return;
    }
    
    GTBaseMessageData *messageData = [[GTBaseMessageData alloc] initIncoming:tlvSections withSenderGID:response.senderGID];
    
    GTBaseMessageData *(^buildResultBlock)(NSArray<TLVSection *> *, NSNumber *senderGID) = [self messageDeserializingDictionary][messageData.messageType];
    
    if (buildResultBlock) {
        GTBaseMessageData *baseMessageData = buildResultBlock(tlvSections, messageData.senderGID);
        baseMessageData.addresseeGID = response.addressedGID;
        baseMessageData.messageSentDate = response.messageSentDate;
        
        if ([baseMessageData isKindOfClass:[MTNodeRequest class]]) {
            MTNodeRequest *nodeRequest = (MTNodeRequest *)baseMessageData;
            
            if ([nodeRequest isValidRequest]) {
                block(nodeRequest);
            } else {
                block(nil);
            }
            
        } else if ([baseMessageData isKindOfClass:[GTLocationOnlyMessageData class]]) {
            // Node update being received
            
            // TODO: Build custom wrapper around node updates
            // so that they are easier to work with when updating
            // components for UI quickly.
            
            GTLocationOnlyMessageData *locationMessageData = (GTLocationOnlyMessageData *)baseMessageData;
            GTLocationMessageData *location = locationMessageData.locationMessageData;
            
            NSString *message = [NSString stringWithFormat:@"%@\n(%@, %@)", location.name, location.latitude, location.longitude];
            NSLog(@"Incoming node location update: %@", message);
            
            MTUser *user = [[MTUser alloc] initWithGID:baseMessageData.senderGID name:location.name];
            MTNode *node = [[MTNode alloc] initWithOwner:user location:[[CLLocation alloc] initWithLatitude:location.latitude.floatValue
                                                                                                  longitude:location.longitude.floatValue]];
            block(node);
        }
        
        if ([baseMessageData isKindOfClass:[GTPublicKeyFirmwareResponseMessageData class]]) {
            GTPublicKeyFirmwareResponseMessageData *publicKeyMessageData = (GTPublicKeyFirmwareResponseMessageData *)baseMessageData;
            PublicKeyManager *keyManager = [PublicKeyManager shared];
            
            NSLog(@"Received new firmware public key: [%@] from sender: [%@]", publicKeyMessageData.publicKey, publicKeyMessageData.senderGID);
            
            [keyManager addPublicKeyWithGID:publicKeyMessageData.senderGID publicKeyData:publicKeyMessageData.publicKey userHasMyPublicKey:YES];
            
            [[GTDecryptionErrorManager shared] attemptToDecryptMessagesAgain];
        }
        else if ([baseMessageData isKindOfClass:[GTPublicKeyUserResponseMessageData class]]) {
            GTPublicKeyUserResponseMessageData *publicKeyMessageData = (GTPublicKeyUserResponseMessageData *)baseMessageData;
            PublicKeyManager *keyManager = [PublicKeyManager shared];
            
            [keyManager addPublicKeyWithGID:publicKeyMessageData.senderGID publicKeyData:publicKeyMessageData.publicKey];
            
            [[GTDecryptionErrorManager shared] attemptToDecryptMessagesAgain];
        }
        else if ([baseMessageData isKindOfClass:[GTPublicKeyRequestMessageData class]]) {
            [[GTCommandCenter shared] sendPublicKeyResponseToGID:baseMessageData.senderGID];
        } else {
            return;
        }
    }
}

- (NSDictionary *)messageDeserializingDictionary {
    return @{
             // Node request
             kMessageTypeTextOnly : ^GTBaseMessageData *(NSArray<TLVSection *> *dataArray, NSNumber *senderGID) {
                 return [[MTNodeRequest alloc] initFromOrderedData:dataArray withSenderGID:senderGID];
             },
             
             // Location update
             kMessageTypeLocationOnly : ^GTBaseMessageData *(NSArray<TLVSection *> *dataArray, NSNumber *senderGID) {
                 return [[GTLocationOnlyMessageData alloc] initFromOrderedData:dataArray withSenderGID:senderGID];
             },
             
             kMessageTypeFirmwarePublicKeyResponse : ^GTBaseMessageData *(NSArray<TLVSection *> *dataArray, NSNumber *senderGID) {
                 return [[GTPublicKeyFirmwareResponseMessageData alloc] initFromOrderedData:dataArray withSenderGID:senderGID];
             },
             
             kMessageTypeUserPublicKeyResponse : ^GTBaseMessageData *(NSArray<TLVSection *> *dataArray, NSNumber *senderGID) {
                 return [[GTPublicKeyUserResponseMessageData alloc] initFromOrderedData:dataArray withSenderGID:senderGID];
             },
             
             kMessageTypePublicKeyRequest : ^GTBaseMessageData *(NSArray<TLVSection *> *dataArray, NSNumber *senderGID) {
                 return [[GTPublicKeyRequestMessageData alloc] initFromOrderedData:dataArray withSenderGID:senderGID];
             } };
}

@end
