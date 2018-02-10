//
//  FileTransferEngine.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 1/22/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    FileTransferStateNormal,
    FileTransferStateCancel,
} FileTransferState;

@class GTFileTransferUnitMessageData;

@interface FileTransferEngine : NSObject

- (instancetype)initFileTransferCancelWithFileUUID:(NSString*)fileUUID;
- (instancetype)initWithTransferDataBatch:(NSData*)transferDataBatch dataFileName:(NSString*)fileName;
- (instancetype)init NS_UNAVAILABLE;

- (void)markFileTransferAsCancelled;

//queries
- (GTFileTransferUnitMessageData*)nextFileTransferUnit;
- (GTFileTransferUnitMessageData *)cancelFileTransferUnit;
- (NSNumber*)transferProgress;
- (BOOL)isCancelled;
- (BOOL)hasNext;

@property (nonatomic, readonly) FileTransferState fileTransferState;
@property (nonatomic, readonly) NSString *fileUUID;

@end
