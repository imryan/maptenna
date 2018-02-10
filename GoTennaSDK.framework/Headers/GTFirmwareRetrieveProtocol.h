//
//  GTFirmwareRetrieveProtocol.h
//  NewiOSTests
//
//  Created by JOSHUA M MAKINDA on 3/3/16.
//  Copyright © 2016 JOSHUA M MAKINDA. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^RetrievalCompletion)();

@protocol GTFirmwareRetrieveProtocol <NSObject>

-(void)retrieveFirmwareWithStorageCompletion:(RetrievalCompletion)retrievalCompletion;

@end
