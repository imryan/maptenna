//
//  GTSystemInfo.h
//  GoTenna
//
//  Created by Julietta Yaunches on 4/23/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SystemInfoResponseData;

typedef enum{
    BatteryGoodGreen,
    BatterySlightlyLowYellow,
    BatteryLowRed
} GTBatteryStatusLevel;

@interface GTSystemInfo : NSObject<NSCoding>
@property(nonatomic) double firmwareVersion;
@property(nonatomic) NSNumber *majorRevision;
@property(nonatomic) NSNumber *minorRevision;
@property(nonatomic) NSNumber *buildRevision;
@property(nonatomic) NSNumber *batteryLevel;
@property(nonatomic, copy) NSString *goTennaSerialNumber;

+ (id)initWithSystemInfo:(SystemInfoResponseData *)incomingData;
- (GTBatteryStatusLevel)currentBatteryStatus;

- (NSString *)printableVersion;
- (NSString *)printableRevisionVersion;
@end
