//
// Created by Julietta Yaunches on 21/10/2014.
// Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface GTConfig : NSObject

//INSIDE SDK
+ (BOOL)connectionNotRequired;
+ (NSInteger)maxGIDlength;
+ (NSUInteger)privateGIDByteLength;
+ (NSUInteger)broadcastGIDByteLength;
+ (NSInteger)maxDataPayloadLength;
+ (NSInteger)firmwareUpdateCommandTimeoutAmount;
+ (NSInteger)normalUpdateCommandTimeoutAmount;
+ (NSString *)retrieveCurrentVersion;
+ (NSString *)retrieveVersionDescription;
+ (NSTimeInterval)finalizeFirmwareCommandTimeout;
+ (NSInteger)resetCommandTimeoutAmount;
+ (BOOL)shouldLogPackets;
+ (NSInteger)packetDataPayloadLimit;
+ (NSInteger)systemInfoQueryInterval;
+ (NSInteger)initialConnectionScanTimeout;
@end