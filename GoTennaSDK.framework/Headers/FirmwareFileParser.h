//
// Created by Julietta Yaunches on 1/13/15.
// Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GTFirmwareVersion;


@interface FirmwareFileParser : NSObject
- (NSData *)parseFileToDataForVersion:(GTFirmwareVersion *)filename;
@end