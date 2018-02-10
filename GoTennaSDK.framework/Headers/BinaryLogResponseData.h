//
//  BinaryLogResponseData.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 7/2/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BinaryLogResponseData : NSObject

- (instancetype)initWithBinaryLogData:(NSData*)binaryLogData;

//queries
- (NSArray*)binaryLogs;
- (int)binaryLogCount;

@end
