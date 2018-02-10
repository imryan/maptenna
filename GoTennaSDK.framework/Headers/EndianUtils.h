//
//  EndianUtils.h
//  Test
//
//  Created by Thomas Colligan on 12/21/15.
//  Copyright (c) 2015 Thomas Colligan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EndianUtils : NSObject

+ (NSData *)longToBigEndianBytes:(unsigned long long)longValue;

+ (NSData *)integerToBigEndianBytes:(int)integer;

+ (NSData *)integer:(int)integer toBigEndianBytesWithLength:(int)byteCount;

+ (long long)bytesToLong:(NSData *)data;

+ (int)bytesToInt:(NSData *)data;

+ (double) bytesToDouble:(NSData *)data;

+ (NSData *)doubleToBigEndianBytes:(double )doubleValue;

@end
