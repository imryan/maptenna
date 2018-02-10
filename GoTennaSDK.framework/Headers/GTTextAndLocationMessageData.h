//
// Created by Julietta Yaunches on 11/18/14.
// Copyright (c) 2014 goTenna-inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTMessageDataProtocol.h"
#import "GTBaseMessageData.h"
#import "GTTextOnlyMessageData.h"

@interface GTTextAndLocationMessageData : GTTextOnlyMessageData<GTMessageDataProtocol>
- (id)initOutgoingWithText:(NSString *)text andLocationData:(GTLocationMessageData *)data onError:(NSError **)error;
@end