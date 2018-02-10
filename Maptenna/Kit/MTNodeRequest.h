//
//  MTNodeRequest.h
//  Maptenna
//
//  Created by Ryan Cohen on 5/21/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

#import <GoTennaSDK/GoTennaSDK.h>

@interface MTNodeRequest : GTBaseMessageData <GTMessageDataProtocol>

/*
 Sends a publicly broadcasted request asking for nodes.
 */

- (nonnull instancetype)initWithHashedIdentifier:(nonnull NSString *)hashedIdentifier;

- (nonnull instancetype)initIncoming:(nonnull NSArray<TLVSection *> *)array withSenderGID:(nonnull NSNumber *)senderGID;

- (BOOL)isValidRequest;

@end
