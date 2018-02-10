//
// Created by Julietta Yaunches on 11/18/14.
// Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    NormalMessage,
    LocationRequestMessage,
    LogOnMessage,
    PingMessage,
    NewPublicKey,
    FileTransferMessage,
    FileTransferMessageCancel,
} GTMessageType;

typedef enum{
    MessageOut,
    MessageReceived,
    MessageNotReceived,
    MessageNotReceivedTemperatureRange,
    MessageNotReceivedRSSICrossed,
    MessageNotReceivedTimeout,
} GTOutgoingMessageStatus;

typedef enum{
    GTBatteryEmpty,
    GTBatteryFull,
    GTBatteryThreeFourths,
    GTBatteryOneHalf,
    GTBatteryOneFourth
} GTBatteryStatus;

typedef enum{
    OneToOneGID,
    GroupGID,
    ShoutGID,
    EmergencyGID
} GTGIDType;

typedef enum{
    GTResponsePositive,
    GTResponseNegative,
    GTResponseError
} GTCommandResponseType;

@interface GTDataTypes : NSObject
+ (NSData*)getDataForGIDType:(GTGIDType)type;
+ (GTGIDType)getGIDTypeFromData:(NSData *)data;
@end