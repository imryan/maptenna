//
// Created by Julietta Yaunches on 11/14/14.
// Copyright (c) 2014 goTenna-inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTMessageDataProtocol.h"
#import "GTCommandCenter.h"
#import "GTBaseMessageData.h"

@class GTLocationMessageData;

@interface GTTextOnlyMessageData : GTBaseMessageData<GTMessageDataProtocol>
- (id)initOutgoingWithText:(NSString *)text onError:(NSError **)error;
@end