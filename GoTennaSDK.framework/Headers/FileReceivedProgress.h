//
//  FileReceivedProgress.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 2/2/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FileReceivedProgress : NSObject

- (instancetype)initWithCompleteFileSize:(NSNumber*)completeFileSize;

//queries
- (NSNumber*)percentReceived;

@property (nonatomic, strong) NSNumber *bytesReceived;

@end