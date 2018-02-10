//
//  NSData+BytesToPrimitiveArray.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 7/6/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (BytesToPrimitiveArray)

//queries
- (NSArray*)array8BitIntegers;
- (NSArray*)array8BitAsciiTransform;
- (int)bytesToInt;

@end
