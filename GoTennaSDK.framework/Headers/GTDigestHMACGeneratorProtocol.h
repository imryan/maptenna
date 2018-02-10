//
//  GTDigestHMACGeneratorProtocol.h
//  EncryptionRewriting
//
//  Created by JOSHUA M MAKINDA on 12/23/15.
//  Copyright © 2015 JOSHUA M MAKINDA. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol GTDigestHMACGeneratorProtocol <NSObject>

//queries
- (NSData*)generateRandom32BytesUsingSharedSecret:(NSData*)sharedSecret
                                       andLongKey:(NSData*)longKey;
@end
