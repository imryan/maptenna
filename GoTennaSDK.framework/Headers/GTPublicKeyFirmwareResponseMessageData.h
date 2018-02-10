//
//  GTPublicKeyFirmwareResponseMessageData.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 12/29/15.
//  Copyright © 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTMessageDataProtocol.h"
#import "GTBaseMessageData.h"

@interface GTPublicKeyFirmwareResponseMessageData : GTBaseMessageData<GTMessageDataProtocol>

@property (nonatomic, readonly) NSData *publicKey;
@end
