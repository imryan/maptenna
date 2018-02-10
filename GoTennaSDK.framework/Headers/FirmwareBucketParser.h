//
// Created by Julietta Yaunches on 5/27/15.
// Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface FirmwareBucketParser : NSObject
- (NSString *)determineVersionToDownload:(NSArray *)dictionary;
@end