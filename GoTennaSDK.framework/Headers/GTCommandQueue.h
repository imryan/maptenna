//
// Created by Julietta Yaunches on 5/06/2014.
// Copyright (c) 2014 goTenna. All rights reserved.
//


#import <Foundation/Foundation.h>

@class GTPacketPreparer;
@class GTPacket;
@class GTCommand;
@class GTCommandArray;

@interface GTCommandQueue : NSObject
@property(nonatomic, strong) GTCommand *currentCommand;

- (void)queueGTCommand:(GTCommand *)command;
- (void)queueGTCommands:(GTCommandArray *)incomingCommands;
//- (void)queueGTCommand:(GTCommand *)command;
- (void)nudgeToNextCommand;
- (void)empty;
- (NSArray *)remainingCommands;
//- (void)queuePriorityGTCommand:(GTCommand *)command;
- (void)pauseQueue;
//- (void)queuePriorityGTCommands:(GTCommandArray *)incomingCommands;

- (void)executeUpcomingCommand;

@end