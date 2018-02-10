//
//  ChatViewController.m
//  Maptenna
//
//  Created by Ryan Cohen on 4/29/17.
//  Copyright © 2016 goTenna. All rights reserved.
//

@import GoTennaSDK;

#import "ChatViewController.h"

typedef void (^GTMessageResponseBlock)(BOOL success);

@interface ChatViewController ()

@property (nonatomic, weak) IBOutlet UITableView *tableView;

@property (nonatomic, strong) NSMutableArray *users;
@property (nonatomic, strong) NSMutableArray *messages;
@property (nonatomic, strong) NSDictionary *messageDeserializingDictionary;

@property (nonatomic, strong) NSNumber *privateChatGID;

@end

@implementation ChatViewController

#pragma mark - Table

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 3;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    NSUInteger rows = 0;
    
    if (section == 0) {
        rows = self.users.count;
    } else if (section == 1) {
        rows = (self.messages.count == 0) ? 1 : self.messages.count;
    } else {
        rows = 1;
    }
    
    return rows;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    if (section == 0) {
        return @"Recipients";
    }
    else if (section == 1) {
        return @"Conversation";
    }
    
    return nil;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *cellId = @"CellId";
    UITableViewCell *cell = (UITableViewCell *)[tableView dequeueReusableCellWithIdentifier:cellId forIndexPath:indexPath];
    
    if (indexPath.section == 0) {
        User *user = self.users[indexPath.row];
        cell.textLabel.text = user.name;
        cell.userInteractionEnabled = NO;
        
        if ([user.gId isEqualToNumber:[UserDataStore shared].currentUser.gId]) {
            cell.detailTextLabel.text = @"Me";
        } else {
            cell.detailTextLabel.text = @"Recipient";
            self.privateChatGID = user.gId;
        }
        
    } else if (indexPath.section == 1) {
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.accessoryType = UITableViewCellAccessoryNone;
        
        if (self.messages.count > 0) {
            GTBaseMessageData *message = self.messages[indexPath.row];
            
            if ([message.senderGID isEqualToNumber:[UserDataStore shared].currentUser.gId]) {
                cell.textLabel.text = @"Me";
            } else {
                cell.textLabel.text = message.senderInitials;
            }
            
            cell.detailTextLabel.text = message.text;
            cell.textLabel.enabled = NO;
        } else {
            cell.textLabel.enabled = NO;
            cell.textLabel.text = @"No messages";
            cell.detailTextLabel.text = nil;
        }
        
    } else {
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
        cell.textLabel.text = @"Send Message";
        cell.detailTextLabel.text = nil;
    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.section == 2) {
//        __weak typeof(self) weakSelf = self;
        
//        [[GTHelpers alloc] showAlertWithField:@"Send Message" message:@"Send a message" prompt:@"Hey there" block:^(NSString *text) {
//            [self sendMessage:text toGID:self.privateChatGID block:^(BOOL success) {
//                if (success) {
//                    [self reloadSections];
//                } else {
//                    [weakSelf showAlertWithTitle:@"Error" message:@"Couldn't deliver your message."];
//                }
//            }];
//        }];
    }
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

#pragma mark - SDK

- (void)sendMessage:(NSString *)message toGID:(NSNumber *)gid block:(GTMessageResponseBlock)block {
    NSError *error = nil;
    GTTextOnlyMessageData *messageData = [[GTTextOnlyMessageData alloc] initOutgoingWithText:message onError:&error];
    
    [[GTCommandCenter shared] sendMessage:messageData.serializeToBytes encrypt:YES toGID:gid fromGID:self.creatorGID onResponse:^(GTResponse *response) {
        BOOL success = (response.responseCode == GTResponsePositive) ? YES : NO;

        [self.messages addObject:messageData];
        block(success);
    } onError:^(NSError *error) {
        NSLog(@"Error: %@", error);
        block(NO);
    }];
}

- (void)listenForIncomingMessages {
    [[GTCommandCenter shared] setOnIncomingMessage:^(GTMessageData *response) {
        [self didReceiveMessage:response];
    }];
}

- (void)didReceiveMessage:(GTMessageData *)response {
    NSArray<TLVSection *> *tlvSections = [TLVSection tlvSectionsFromData:response.commandData];
    
    if (tlvSections.count < 2) {
        return;
    }
    
    GTBaseMessageData *messageData = [[GTBaseMessageData alloc] initIncoming:tlvSections withSenderGID:response.senderGID];
    GTBaseMessageData *(^buildResultBlock)(NSArray<TLVSection *> *, NSNumber *senderGID) = self.messageDeserializingDictionary[messageData.messageType];
    
    if (buildResultBlock) {
        GTBaseMessageData *baseMessageData = buildResultBlock(tlvSections, messageData.senderGID);
        baseMessageData.addresseeGID = response.addressedGID;
        baseMessageData.messageSentDate = response.messageSentDate;
        
        GTGIDType type = [GIDManager gidTypeForGID:baseMessageData.addresseeGID];
        BOOL isShoutGID = (type == ShoutGID);
        
        if (isShoutGID) {
            [self showAlertWithTitle:@"Shout" message:baseMessageData.text];
            return;
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
        }
        else {
            [self insertMessageIntoChat:baseMessageData];
            return;
        }
    }
}

- (void)insertMessageIntoChat:(GTBaseMessageData *)message {
    [self.messages addObject:message];
    [self reloadSections];
}

#pragma mark - Helpers

- (void)showAlertWithTitle:(NSString *)title message:(NSString *)message {
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"Dismiss" style:UIAlertActionStyleCancel handler:nil];
    [alertController addAction:cancel];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)fillDummyUsers {
    User *steve = [User initWithUsername:@"Steve" andGid:@8302384926];
    User *ryan = [User initWithUsername:@"Ryan" andGid:@92210536354021];
    
    self.users = [NSMutableArray array];
    [self.users addObjectsFromArray:@[steve, ryan]];
}

- (void)reloadSections {
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.tableView reloadData];
    });
}

#pragma mark - View

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.messages = [NSMutableArray array];
    
    self.messageDeserializingDictionary = @{
                    kMessageTypeTextOnly : ^GTBaseMessageData *(NSArray<TLVSection*> *dataArray, NSNumber *senderGID) {
                        return [[GTTextOnlyMessageData alloc] initFromOrderedData:dataArray withSenderGID:senderGID];
                    },
                    
                    kMessageTypeSetGroupGID : ^GTBaseMessageData *(NSArray<TLVSection*> *dataArray, NSNumber *senderGID) {
                        return [[GTGroupCreationMessageData alloc] initFromOrderedData:dataArray withSenderGID:senderGID];
                    },
                    
                    kMessageTypeFirmwarePublicKeyResponse : ^GTBaseMessageData *(NSArray<TLVSection*> *dataArray, NSNumber *senderGID) {
                        return [[GTPublicKeyFirmwareResponseMessageData alloc] initFromOrderedData:dataArray withSenderGID:senderGID];
                    },
                    
                    kMessageTypeUserPublicKeyResponse : ^GTBaseMessageData *(NSArray<TLVSection*> *dataArray, NSNumber *senderGID) {
                        return [[GTPublicKeyUserResponseMessageData alloc] initFromOrderedData:dataArray withSenderGID:senderGID];
                    },
                    
                    kMessageTypePublicKeyRequest : ^GTBaseMessageData *(NSArray<TLVSection*> *dataArray, NSNumber *senderGID) {
                        return [[GTPublicKeyRequestMessageData alloc] initFromOrderedData:dataArray withSenderGID:senderGID];
                    }
                  };
    
    [self listenForIncomingMessages];
    [self fillDummyUsers];
    [self reloadSections];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
