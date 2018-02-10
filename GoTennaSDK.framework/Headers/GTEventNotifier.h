//
//  GTLogger.h
//  GoTenna
//
//  Created by Julietta Yaunches on 10/17/14.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GTCommand;
@class GTBaseMessageData;

@interface GTEventNotifier : NSObject
@property(nonatomic) BOOL rssiLoggingTurnedOn;

+ (GTEventNotifier *)shared;

- (void)userDisconnectInitiated;
- (void)nonUserDisconnectionOccurred:(NSError *)error;
- (void)writeError:(NSError *)error;
- (void)RSSIReceived:(NSNumber *)number;
- (void)logGoTennaCommunicationEvent:(NSString *)logDetail;

@end
