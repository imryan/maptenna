//
//  GTGroupCreationMessage.h
//  GoTenna
//
//  Created by Julietta Yaunches on 11/14/14.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTMessageDataProtocol.h"
#import "GTBaseMessageData.h"

@interface GTGroupCreationMessageData : GTBaseMessageData<GTMessageDataProtocol>
@property(nonatomic, strong) NSNumber *groupGID;
@property(nonatomic, strong) NSArray *groupAddressees;
@property(nonatomic, strong) NSData *sharedSecret;

- (id)initWithGroupGID:(NSNumber *)number andAddressees:(NSArray *)addressees andSharedSecret:(NSData *)sharedSecret onError:(NSError **)error;
@end
