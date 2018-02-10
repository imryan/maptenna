//
//  GTFirmwareUpdater.h
//  GoTenna
//
//  Created by Julietta Yaunches on 1/7/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GTCommandCenter;
@class GTFirmwareVersion;
@protocol GTFirmwareInstallationProgressProtocol;
@class GTCommand;

static dispatch_queue_t GTGTFirmwareUpdate() {
    static dispatch_queue_t firmware_update_queue;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        firmware_update_queue = dispatch_queue_create("com.GT.GTFirmwareUpdate", DISPATCH_QUEUE_CONCURRENT);
    });

    return firmware_update_queue;
}

/** Writes the firmware data straight to the firmware device,
\ */

@interface GTFirmwareWriter : NSObject
- (id)initWithVersionToWrite:(GTFirmwareVersion *)version progressDelegate:(id <GTFirmwareInstallationProgressProtocol>)progressDelegate onFinalizeSent:(void (^)())onFinalizeSent;
- (void)writeFirmware;
- (void)abortCurrentCommand;
- (void)resolveInProgressWrite:(double)currentInstalledVersion;

@property(nonatomic) BOOL isDownloading;

@end
