//
//  GTFileTransferUnitMessageData.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 1/22/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTMessageDataProtocol.h"
#import "GTBaseMessageData.h"

@class TLVSection;

@interface GTFileTransferUnitMessageData : GTBaseMessageData<GTMessageDataProtocol>

- (id)initOutgoingWithFileName:(NSString*)fileName fullFileSize:(NSNumber*)fullFileSize fileData:(NSData *)data fileUUID:(NSString*)fileUUID fileStatus:(NSData*)fileStatus onError:(NSError **)error;
- (id)initOutgoingWithFileUUID:(NSString*)fileUUID fileStatus:(NSData*)fileStatus onError:(NSError **)error;

@property (nonatomic, readonly) NSString *fileName;
@property (nonatomic, readonly) NSNumber *fileSize;
@property (nonatomic, readonly) NSString *fileUUID;
@property (nonatomic, readonly) NSData *fileStatus;
@property (nonatomic, readonly) NSData *data;
@end
