//
// Created by Julietta Yaunches on 1/13/15.
// Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Holds the firmware information, often returned from classes
 */

@interface GTFirmwareVersion : NSObject<NSCoding>
+ (id)initWithFilename:(NSString *)filename andFirmwareVersion:(double)firmwareVersion;

@property(nonatomic, copy) NSString *filename;
@property(nonatomic) double firmwareVersion;
@property(nonatomic, strong) NSDate *installedDate;

- (NSData*)featureVersionData;
- (NSData*)producationVersionData;

- (NSString *)printableVersion;
@end