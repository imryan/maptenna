//
//  GTFirmwareRetrieverFactory.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 3/7/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTFirmwareRetrieveProtocol.h"

@interface GTFirmwareRetrieverFactory : NSObject

+ (id<GTFirmwareRetrieveProtocol>)firmwareRetrieverURLWithURL:(NSURL*)url fileName:(NSString*)fileName;
+ (id<GTFirmwareRetrieveProtocol>)firmwareRetrieverFileSystemWithFileName:(NSString*)fileName;
@end
