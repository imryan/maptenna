//
// Created by Julietta Yaunches on 11/14/14.
// Copyright (c) 2014 goTenna-inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TLVSection;
@protocol GTMessageDataProtocol <NSObject>
//- (NSString *)serializeToString;
- (id)initFromOrderedData:(NSArray<TLVSection*> *)data withSenderGID:(NSNumber*)senderGID;
- (NSArray<TLVSection*> *)getTLVSections;
- (NSData*)serializeToBytes;
@end