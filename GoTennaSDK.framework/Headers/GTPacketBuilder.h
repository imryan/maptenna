//
// Created by Julietta Yaunches on 19/06/2014.
// Copyright (c) 2014 goTenna. All rights reserved.
//


#import <Foundation/Foundation.h>

@class GTCommand;


@interface GTPacketBuilder : NSObject
- (NSArray *)generatePackets:(GTCommand *)theCommand;
@end