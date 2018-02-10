//
// Created by Julietta Yaunches on 6/19/15.
// Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum{
    UnknownFrequencyMode,
    NormalFrequencyMode,
    HighFrequencyMode,
    LowFrequencyMode,
} GTFrequencyModes;

@interface FrequencyMode : NSObject
@property(nonatomic) void const *commandCode;
@property(nonatomic, copy) NSString *name;

- (id)initWithCode:(char *const)code andName:(NSString *)name;

- (id)initForCode:(GTFrequencyModes)mode;
@end