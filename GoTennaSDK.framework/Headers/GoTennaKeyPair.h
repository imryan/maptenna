//
//  GoTennaKeyPair.h
//  GoTenna
//
//  Created by Julietta Yaunches on 5/18/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GoTennaKeyPair : NSObject
@property(nonatomic, strong, readonly) NSData *privateKey;
@property(nonatomic, strong, readonly) NSData *publicKey;
- (id)initWithPublicKey:(NSData *)data andPrivateKey:(NSData *)key;
@end
