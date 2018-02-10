//
//  GTDecryptionErrorManager.h
//  GoTenna
//
//  Created by Thomas Colligan on 2/16/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTDecryptionErrorItem.h"

/**
 * When a decryption error occurs, we save the message info in here so that we can try to decrypt it later
 * when we receive a new public key from another user.
 */
@interface GTDecryptionErrorManager : NSObject

@property (nonatomic, strong) NSMutableSet *decryptionErrorItems;

+ (instancetype)shared;
- (void)addDecryptionErrorItem:(GTDecryptionErrorItem *)decryptionErrorItem;
- (void)attemptToDecryptMessagesAgain;

@end
