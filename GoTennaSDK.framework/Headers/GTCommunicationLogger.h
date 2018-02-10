//
// Created by Julietta Yaunches on 4/8/15.
// Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTFileLogger.h"

@class GTDocumentManager;
@class GTBaseMessageData;

@interface GTCommunicationLogger : GTFileLogger
+ (GTCommunicationLogger *)shared;

+ (NSDictionary *)messageContentTypes;
+ (NSDictionary *)messageTypes;

- (void)log:(NSString *)logText;

- (id)buildGoTennaCommunicationEvent:(GTBaseMessageData *)data;

@end