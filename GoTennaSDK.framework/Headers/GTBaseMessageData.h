//
// Created by Julietta Yaunches on 11/18/14.
// Copyright (c) 2014 goTenna-inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTLocationMessageData.h"
#import "GTCommandCodeConstants.h"

@class TLVSection;

@interface GTBaseMessageData : NSObject
@property(nonatomic, copy) NSString *messageType;
@property(nonatomic, strong) NSNumber *senderGID;
@property(nonatomic, strong) NSString *senderInitials;
@property(nonatomic, strong) NSNumber *addresseeGID;
@property(nonatomic, strong) NSNumber *receivingGID;
@property(nonatomic, strong) GTLocationMessageData *locationMessageData;
@property(nonatomic, copy) NSString *text;
@property(nonatomic, strong) NSArray *baseDataComponents;
@property(nonatomic, strong) GTLocationMessageData *senderLocationData;
@property(nonatomic, strong) NSDate *messageSentDate;

- (id)initOutgoingOnError:(NSError **)pError;
- (id)initIncoming:(NSArray<TLVSection*> *)array withSenderGID:(NSNumber*)senderGID;
- (NSNumber *)getGIDNumber:(id)value;
- (void)setAddressedGID:(NSNumber *)number;

- (NSArray<TLVSection*> *)buildTLVSections;
- (NSArray<TLVSection*> *)getTLVSections;
- (NSData*)serializeToBytes;

@end
