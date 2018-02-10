//
//  GTFirmwareInstallationManager.h
//  GoTenna
//
//  Created by Julietta Yaunches on 1/22/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GTCommandCenter;
@class GTCommandBuilder;
@class FirmwareFileParser;
@class GTSystemInfoStore;
@class SettingsTVC;
@protocol GTFirmwareInstallationProgressProtocol;
@class FirmwareInstallationHud;

@interface GTFirmwareInstallationManager : NSObject
- (void)checkAndInstallFirmwareWithFirmwareProgressDelegate:(id <GTFirmwareInstallationProgressProtocol>)delegate;
- (BOOL)isCurrentlyDownloading;
@end
