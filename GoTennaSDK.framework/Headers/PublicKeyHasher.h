//
//  PublicKeyHasher.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 12/22/15.
//  Copyright © 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PublicKeyHasher : NSObject

- (NSData*)hashPublicKeyWithReceiverGID:(NSNumber*)receiverGID publicKey:(NSData*)publicKey;
- (NSData*)skipHash;
- (NSData*)emptyHash;
@end