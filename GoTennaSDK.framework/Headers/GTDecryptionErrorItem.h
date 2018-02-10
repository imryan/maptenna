//
//  GTDecryptionErrorItem.h
//  GoTenna
//
//  Created by Thomas Colligan on 2/16/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTResponse.h"
#import "GTGroupCreationMessageData.h"

/**
 * A model that represent a GTResponse with callback blocks that we tried to decrypt, but were unsuccessful in decrypting.
 * We were most likely unsuccessful because we did not have one of the required public keys.
 */
@interface GTDecryptionErrorItem : NSObject

@property (nonatomic, strong) GTResponse *response;
@property(nonatomic, copy) void (^onIncomingMessage)(GTMessageData *);
@property(nonatomic, copy) void (^onGroupAdded)(GTGroupCreationMessageData *);
@property(nonatomic, copy) void (^onSuccessLastMessageDelete)();

- (instancetype)initWithResponse:(GTResponse *)response  onIncomingMessage:(void (^)(GTMessageData *))onIncomingMessage onGroupAdded:(void (^)(GTGroupCreationMessageData *))onGroupAdded onSuccessLastMessageDelete:(void (^)())onSuccessLastMessageDelete;

@end
