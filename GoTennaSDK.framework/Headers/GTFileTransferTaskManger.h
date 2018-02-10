//
//  GTFileTransferTaskManger.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 1/25/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    FileTransferUnitStatusGeneral,
    FileTransferUnitStatusStart,
    FileTransferUnitStatusEnd,
    FileTransferUnitStatusCancel,
    FileTransferUnitStatusUnknown,
} FileTransferUnitStatus;

@class FileTransferEngine;
@class GTFileTransferUnitMessageData;
@class GTFileReceived;
@class FileReceivedProgress;
@class GTFileTransferTaskManger;

@protocol GTFileTransferTaskMangerDelegate <NSObject>
- (void)fileTransferIncomingUpdatePercentReceived:(NSNumber*)percentReceived forFileUUID:(NSString*)fileUUID;
- (void)fileTransferCompleteWithFileReceived:(GTFileReceived*)fileReceived;
@end

@interface GTFileTransferTaskManger : NSObject

+ (GTFileTransferTaskManger*)shared;

+ (FileTransferUnitStatus)statusForFileStatusData:(NSData*)fileStatus;

//commands
- (void)addFileTransferEngineObject:(FileTransferEngine*)fileTransferEngine;
- (void)removeFileTransferEngineWithUUID:(NSString*)fileUUID;
- (void)cancelFileTransferEngineWithUUID:(NSString*)fileUUID;
- (void)addIncomingFileTransferUnitChunk:(GTFileTransferUnitMessageData*)fileChunkUnitData;
- (void)addSentFile:(UIImage*)file forFileUUID:(NSString*)fileUUID;

//queries
- (FileTransferEngine*)fileTransferEngineObjectForUUID:(NSString*)fileUUID;
- (GTFileReceived *)fileReceivedForUUID:(NSString *)fileUUID;
- (BOOL)fileTransferEngineProcessDeadForUUID:(NSString *)fileUUID;
- (BOOL)fileTransferProcessingIncomingForUUID:(NSString *)fileUUID;
- (UIImage *)fileSentForUUID:(NSString *)fileUUID;
- (FileReceivedProgress*)fileReceivedProgressForUUID:(NSString*)fileUUID;

//delegate
@property (nonatomic, weak) id<GTFileTransferTaskMangerDelegate> delegate;

@end

