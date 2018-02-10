//
// Created by Julietta Yaunches on 11/4/14.
// Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTResponse.h"

typedef enum : NSUInteger {
    GTCommandPriorityLow,
    GTCommandPriorityMedium,
    GTCommandPriorityHigh,
    GTCommandPriorityRequired,
} GTCommandPriority;

@interface GTCommand : NSObject
@property(nonatomic, strong) NSArray *packets;
@property(nonatomic) BOOL responseReceived;
@property(nonatomic) BOOL isPausable;
@property(nonatomic, copy) void (^processResponse)(GTResponse *);
@property(nonatomic, copy) void (^onError)(NSError *);
@property(nonatomic) char *commandCode;
@property(nonatomic, strong) NSData *rawData;
@property(nonatomic, strong) NSData *messageHeaderData;
@property(nonatomic, strong) NSData *pubKeyHash;
@property(nonatomic, strong) NSData *messageData;
@property(nonatomic) char *positiveResponse;
@property(nonatomic) char *negativeResponse;
@property(nonatomic, copy) NSString *log;
@property(nonatomic, copy) NSString *name;
@property(nonatomic) int sendAttempts;
@property(nonatomic) int timesToAttempt;
@property(nonatomic) NSTimeInterval commandTimeoutAmount;
@property(nonatomic) int seqNumber;
@property(nonatomic) GTCommandPriority priority;
@property(nonatomic, readonly) NSString *priorityPrintable;

- (BOOL)shouldRetry;
- (void)prepareForNextAttempt;
- (void)initiateWriteTimeoutOnTimeout:(void (^)())onTimeout;
- (void)invalidateTimeout;
@end