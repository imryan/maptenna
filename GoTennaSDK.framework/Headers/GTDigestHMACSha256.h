//
//  GTDigestHMAC.h
//  TestingThings
//
//  Created by JOSHUA M MAKINDA on 9/10/15.
//  Copyright (c) 2015 JOSHUA M MAKINDA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTDigestHMACGeneratorProtocol.h"

@interface GTDigestHMACSha256 : NSObject <GTDigestHMACGeneratorProtocol>

//queries
- (NSData *)generateRandom32BytesUsingSharedSecret:(NSData *)sharedSecret
                                        andLongKey:(NSData *)longKey;
@end
