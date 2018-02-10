//
// Created by Julietta Yaunches on 4/7/15.
// Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableArray (GTHelpers)
- (void)safeRemove:(id)object;
- (id)safeShift;
@end