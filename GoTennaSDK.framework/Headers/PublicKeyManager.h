//
//  PublicKeyManager.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 12/29/15.
//  Copyright © 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PublicKeyEntry;

@interface PublicKeyManager : NSObject

+ (instancetype)shared;

//commands
- (void)addPublicKeyWithGID:(NSNumber*)gid publicKeyData:(NSData*)publicKey;
- (void)addPublicKeyWithGID:(NSNumber*)gid publicKeyData:(NSData*)publicKey userHasMyPublicKey:(BOOL)hasPublicKey;
- (void)setPublicKeyStateWithGID:(NSNumber*)gid userHasMyPublicKey:(BOOL)userHasPublicKey;
- (void)didResetMyPublicKey;

//queries
- (PublicKeyEntry*)publicKeyEntryForGID:(NSNumber*)gid;

//debug
- (void)printOutPublicKeysAndGIDs;

@end
