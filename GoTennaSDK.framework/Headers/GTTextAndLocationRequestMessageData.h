//
// Created by Julietta Yaunches on 11/18/14.
// Copyright (c) 2014 goTenna-inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTMessageDataProtocol.h"
#import "GTTextOnlyMessageData.h"

@interface GTTextAndLocationRequestMessageData : GTTextOnlyMessageData<GTMessageDataProtocol>
- (id)initWithText:(NSString *)text andReceiverGID:(NSNumber *)receiverGID onError:(NSError **)error;
@end