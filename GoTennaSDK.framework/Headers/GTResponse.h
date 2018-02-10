//
//  ResponseChunk.h
//  GoTenna
//
//  Created by Julietta Yaunches on 29/05/2014.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTDataTypes.h"

@class GTMessageData;

@interface GTResponse : NSObject
@property(nonatomic, strong) NSData *commandData;
@property(nonatomic) GTCommandResponseType responseCode;
@property(nonatomic, strong) NSNumber *sequenceNumber;

- (BOOL)responsePositive;
@end
