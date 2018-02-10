//
//  GTKeepAliveProcessor.h
//  GoTenna
//
//  Created by Julietta Yaunches on 1/27/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTDataTypes.h"

@class GTCommandCenter;

@interface GTKeepAliveProcessor : NSObject

- (void)incomingData:(NSData *)keepAliveData;

@end
