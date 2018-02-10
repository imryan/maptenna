//
//  GTEncryptionGlobalCounter.h
//  EncryptionRewriting
//
//  Created by JOSHUA M MAKINDA on 12/23/15.
//  Copyright © 2015 JOSHUA M MAKINDA. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GTEncryptionGlobalCounter : NSObject

+ (instancetype)shared;

//commands
- (void)incrementEncryptionCounter;
- (void)incrementHashCounter;

- (void)decrementEncryptionCounter;
- (void)decrementHashCounter;

- (void)resetEncryptionCounter;
- (void)resetHashCounter;

//queries
- (int)valueEncryptionCounter;
- (int)valueHashCounter;

@end
