//
// Created by Julietta Yaunches on 3/17/15.
// Copyright (c) 2015 gotenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (GTHelpers)
- (NSString *)safeGet:(NSUInteger)index;
- (NSArray *)safeSubArrayWithRange:(NSRange)range;
@end