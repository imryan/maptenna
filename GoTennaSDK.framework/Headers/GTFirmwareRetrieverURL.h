//
//  GTFirmwareRetrieverURL.h
//  NewiOSTests
//
//  Created by JOSHUA M MAKINDA on 3/3/16.
//  Copyright © 2016 JOSHUA M MAKINDA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTFirmwareRetrieveProtocol.h"

@interface GTFirmwareRetrieverURL : NSObject <GTFirmwareRetrieveProtocol>

- (instancetype)initWithFirmwareURL:(NSURL*)firmwareURL fileName:(NSString*)fileName;

- (void)retrieveFirmwareWithStorageCompletion:(RetrievalCompletion)retrievalCompletion;
@end
