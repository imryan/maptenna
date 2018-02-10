//
//  DecryptedPayloadData.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 1/6/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EncryptionInfoHeader.h"

@interface DecryptedPayloadData : NSObject

- (instancetype)initWithEncryptionInfoHeader:(EncryptionInfoHeader*)encryptionInfoHeader plaintextPayloadData:(NSData*)plaintextPayloadData;

@property (nonatomic, readonly) EncryptionInfoHeader *encryptionInfoHeader;
@property (nonatomic, readonly) NSData *plaintextPayloadData;

@end
