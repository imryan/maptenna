//
//  GTEncryptionKeyBuilder.h
//  EncryptionRewriting
//
//  Created by JOSHUA M MAKINDA on 12/23/15.
//  Copyright © 2015 JOSHUA M MAKINDA. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GTEncryptionKeyBuilder : NSObject

- (instancetype)initWithSharedSecret:(NSData *)sharedSecret senderGID:(NSNumber *)senderGID senderPublicKey:(NSData *)senderPublicKey;

@property (nonatomic, readonly) NSData *sharedSecret;
@property (nonatomic, readonly) NSData *senderPublicKey;
@property (nonatomic, readonly) NSData *dateData;
@property (nonatomic, readonly) NSData *senderGIDData;
@property (nonatomic, readonly) int globalCounter;

//queries
- (NSData*)buildLongKeyWithSubCounter:(int)subCounter globalCounter:(int)globalCounter;

@end
