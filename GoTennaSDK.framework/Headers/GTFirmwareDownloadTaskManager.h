//
//  GTFirmwareDownloadTaskManager.h
//  NewiOSTests
//
//  Created by JOSHUA M MAKINDA on 3/3/16.
//  Copyright © 2016 JOSHUA M MAKINDA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTFirmwareRetrieveProtocol.h"
#import "GTFirmwareInstallationProgressProtocol.h"


@interface GTFirmwareDownloadTaskManager : NSObject

+ (GTFirmwareDownloadTaskManager*)manager;

- (void)retrieveAndStoreFirmwareUsingRetriever:(id<GTFirmwareRetrieveProtocol>)retriever onCompletion:(RetrievalCompletion)retrievalCompletion;
- (void)downloadLastRetrievedFirmwareWithProgressDelegate:(id<GTFirmwareInstallationProgressProtocol>)progressDelegate;

- (BOOL)isInstallingFirmware;

@end
