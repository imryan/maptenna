//
// Created by Julietta Yaunches on 9/09/2014.
// Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
@class GTResponse;
@class GTCommand;

@interface GTResponseDispatcher : NSObject
- (void)processResponse:(GTResponse *)response forCommand:(GTCommand *)command;
@end