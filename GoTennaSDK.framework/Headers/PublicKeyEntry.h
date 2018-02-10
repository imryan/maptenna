//
//  PublicKeyEntry.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 12/29/15.
//  Copyright © 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PublicKeyEntry : NSObject <NSCoding>

- (instancetype)initWithPublicKey:(NSData*)publicKey userHasMyPublicKey:(BOOL)userHasMyPublicKey;

@property (nonatomic, strong) NSData *publicKey;
@property (nonatomic) BOOL userHasMyPublicKey;

@end
