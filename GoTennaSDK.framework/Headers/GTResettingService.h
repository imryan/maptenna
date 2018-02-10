//
// Created by Julietta Yaunches on 2/2/15.
// Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GTCommandCenter;


@interface GTResettingService : NSObject
+ (GTResettingService *)shared;
- (void)resetTheGotenna;
@end