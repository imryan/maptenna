//
//  NSData+ByteOperation.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 6/25/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (ByteOperation)

+ (NSData*)bytesFromZeroToNumber:(NSUInteger)maxBound;

- (unsigned char)byteAtIndex:(NSUInteger)index;

@end
