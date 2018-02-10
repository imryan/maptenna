//
// Created by Julietta Yaunches on 30/05/2014.
// Copyright (c) 2014 goTenna. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "GTResponse.h"

@interface GTResponseDataWrapper : NSObject
@property(nonatomic, strong) NSData *cleanedData;

- (id)initWithChunks:(NSData *)data;
- (NSNumber *)extractSequenceNumber;
- (NSData *)extractChecksum:(NSData *)data;
- (BOOL)responseTypeIs:(char *)response;
- (NSData *)extractMessageData;
@end
