//
//  FileChunkReceivedTimer.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 2/2/16.
//  Copyright © 2016 JOSHUA M MAKINDA. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FileChunkReceivedTimer;
typedef void(^DelayedFileChunkBlock)(FileChunkReceivedTimer*);

@interface FileChunkReceivedTimer : NSObject

- (instancetype)initWithFileUUID:(NSString *)fileUUID maxTime:(int)maxTime delayedFileChunkBlock:(DelayedFileChunkBlock)delayedFileChunkBlock;

//commands
- (void)cancel;

//queries
@property (nonatomic, readonly) NSString *fileUUID;
@end

