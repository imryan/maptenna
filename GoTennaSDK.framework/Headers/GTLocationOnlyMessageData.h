//
// Created by Julietta Yaunches on 11/18/14.
// Copyright (c) 2014 goTenna-inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTMessageDataProtocol.h"
#import "GTBaseMessageData.h"

@interface GTLocationOnlyMessageData : GTBaseMessageData<GTMessageDataProtocol>
- (id)initOutgoingWithLocation:(GTLocationMessageData *)data onError:(NSError **)error;
@end