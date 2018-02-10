//
//  GTSecurityService.h
//  GoTenna
//
//  Created by Julietta Yaunches on 5/18/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GoTennaKeyPair;

@interface GTSecurityService : NSObject

+ (instancetype)shared;

//commands
- (void)generatePersonalKeyPair;

//queries
- (GoTennaKeyPair *)keyPair;
- (NSData *)generateSharedSecretUsingRemotePublicKey:(NSData *)remotePublicKey;

@end
