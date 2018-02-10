//
//  MTUser.h
//  Maptenna
//
//  Created by Ryan Cohen on 4/29/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MTUser : NSObject

@property (nonatomic, readonly) NSNumber *gid;
@property (nonatomic, readonly) NSString *name;

+ (instancetype)currentUser;

- (instancetype)initWithGID:(NSNumber *)gid name:(NSString *)name;

@end
