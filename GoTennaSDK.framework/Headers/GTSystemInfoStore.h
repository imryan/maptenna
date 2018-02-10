//
//  GTFirmwareVersionStore.h
//  GoTenna
//
//  Created by Julietta Yaunches on 1/15/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GTFirmwareVersion;
@class SystemInfoResponseData;
@class GTSystemInfo;
@class BluetoothConnectionManager;
@class GTCommandCenter;

@interface GTSystemInfoStore : NSObject

+ (GTSystemInfoStore *)shared;

- (void)storeVersionToInstall:(double)version withFileName:(NSString *)filename;
- (GTFirmwareVersion *)versionToInstall;
- (GTSystemInfo *)currentSystemInfo;
- (void)removeVersionToInstall;
- (void)storeVersionToInstall:(GTFirmwareVersion *)version;

- (void)updateNewSystemInfo:(SystemInfoResponseData *)systemInfo;
@end
