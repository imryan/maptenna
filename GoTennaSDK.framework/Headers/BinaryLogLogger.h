//
//  BinaryLogLogger.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 7/6/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import "GTFileLogger.h"

@interface BinaryLogLogger : GTFileLogger

+ (BinaryLogLogger*)shared;

- (void)logRecievedBinaryLogs:(NSArray*)binaryArrays;

-(NSString *)directory;
-(NSString *)filename;
-(NSString *)subject;
@end
