//
//  EncryptionInfoHeader.h
//  GoTenna
//
//  Created by Thomas Colligan on 1/25/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TLVSection;

/**
 * A model class that represents an EncryptionInfoHeader.
 * This header is sent along will all message data.
 
 * It tells us helpful info about the message, such as who sent it, the time it was sent, and whether the data payload
 * was encrypted or not.
 */
@interface EncryptionInfoHeader : NSObject

@property (nonatomic, assign) BOOL isEncrypted;
@property (nonatomic, strong) NSNumber *senderGID;
@property (nonatomic, assign) int timestamp;
@property (nonatomic, assign) int encryptionCounter;
@property (nonatomic, assign) int fullTlvLength;

+ (BOOL)isValidHeaderSize:(int)len;

- (instancetype)initWithIsEncrypted:(BOOL)isEncrypted andSenderGID:(NSNumber *)senderGID andEncryptionCounter:(int)encryptionCounter;
- (instancetype)initWithTlvSection:(TLVSection *)encryptionInfoTLV;

- (NSString *)getPacketId;
- (NSDate *)getTimestampAsDate;
- (NSData *)toData;
- (NSString *)description;

@end
