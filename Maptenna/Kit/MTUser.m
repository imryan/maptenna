//
//  MTUser.m
//  Maptenna
//
//  Created by Ryan Cohen on 4/29/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

#import "MTUser.h"

@interface MTUser ()

@property (nonatomic, strong) NSNumber *gid;
@property (nonatomic, strong) NSString *name;

@end

@implementation MTUser

# pragma mark - Init

+ (instancetype)currentUser {
    static MTUser *user = nil;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        user = [MTUser new];
    });
    
    return user;
}

- (instancetype)initWithGID:(NSNumber *)gid name:(NSString *)name {
    self = [super init];
    
    if (self) {
        self.gid = gid;
        self.name = name;
    }
    
    return self;
}

@end
