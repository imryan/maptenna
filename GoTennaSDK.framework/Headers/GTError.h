//
// Created by Julietta Yaunches on 12/2/14.
// Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GTError : NSObject

+ (NSError *)invalidAppToken;
+ (NSError *)invalidInputMessageData;
+ (NSError *)invalidIncomingMessageData;
+ (NSError *)goTennaFailedToProcessCommand;
+ (NSError *)hasNotSetupGotenna;
+ (NSError *)dataLengthExceedsLimits;
+ (NSError *)sendingMessageToReservedGID;
+ (NSError *)groupSecretNotFound;
+ (NSError *)goTennaTimedOutWithCommand;

@end