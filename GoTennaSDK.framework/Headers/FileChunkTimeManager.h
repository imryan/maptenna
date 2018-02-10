//
//  FileChunkTimeManager.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 2/2/16.
//  Copyright © 2016 JOSHUA M MAKINDA. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ExpiredIncomingChunkBlockAction)(NSString *fileUUID);

@interface FileChunkTimeManager : NSObject

//commands
- (void)beginNewFileChunkTimingForFileUUID:(NSString*)fileUUID expiredFileChunkBlock:(ExpiredIncomingChunkBlockAction)expiredBlock;
- (void)endFileChunkTimingForFileUUID:(NSString*)fileUUID;

@end