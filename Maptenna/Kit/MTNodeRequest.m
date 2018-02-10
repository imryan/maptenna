//
//  MTNodeRequest.m
//  Maptenna
//
//  Created by Ryan Cohen on 5/21/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

#import "MTNodeRequest.h"

@interface MTNodeRequest ()

@property (nonatomic, strong) NSString *hashedIdentifier;

@end

@implementation MTNodeRequest

# pragma mark - Init

- (nonnull instancetype)initWithHashedIdentifier:(nonnull NSString *)hashedIdentifier {
    NSError *error = nil;
    self = [super initOutgoingOnError:&error];
    
    if (self) {
        self.hashedIdentifier = hashedIdentifier;
        self.messageType = kMessageTypeTextOnly;
    }
    
    return self;
}

# pragma mark - Queries

- (BOOL)isValidRequest {
    // TODO: Fix this.
    // PublicKeyManager *keyManager = [PublicKeyManager shared];
    // [keyManager printOutPublicKeysAndGIDs];
    //
    // return (self.hashedIdentifier.length > 12 && [keyManager publicKeyEntryForGID:senderGID] != nil);
    
    return (self.hashedIdentifier.length > 12);
}

# pragma mark - GTMessageDataProtocol

- (instancetype)initFromOrderedData:(NSArray<TLVSection *> *)array withSenderGID:(NSNumber *)senderGID {
    self = [super initIncoming:array withSenderGID:senderGID];
    
    for (TLVSection *tlvSection in array) {
        if (tlvSection.type == TLV_TYPE_TEXT) {
            self.hashedIdentifier = [[NSString alloc] initWithData:tlvSection.value encoding:NSUTF8StringEncoding];
            break;
        }
    }
    
    return self;
}

- (NSArray<TLVSection *> *)buildTLVSections {
    NSMutableArray<TLVSection *> *tlvSections = [NSMutableArray arrayWithArray:[super buildTLVSections]];
    [tlvSections addObject:[[TLVSection alloc] initWithType:TLV_TYPE_TEXT value:[self.hashedIdentifier dataUsingEncoding:NSUTF8StringEncoding]]];
    
    return [tlvSections copy];
}


@end
