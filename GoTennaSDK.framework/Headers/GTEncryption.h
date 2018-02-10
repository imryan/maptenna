//
//  GTEncryption.h
//  EncryptionRewriting
//
//  Created by JOSHUA M MAKINDA on 12/23/15.
//  Copyright © 2015 JOSHUA M MAKINDA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTDigestHMACGeneratorProtocol.h"

@class GTEncryptionKeyBuilder;

@interface GTEncryption : NSObject

- (instancetype)initWithEncryptionKeyBuilder:(GTEncryptionKeyBuilder*)keyBuilder
                         digestHMACGenerator:(id<GTDigestHMACGeneratorProtocol>)digestHMACGenerator;

//queries
- (NSData*)encryptDecryptWithRawBytes:(NSData*)rawMessageBytes counter:(int)globalCounter;
@end
