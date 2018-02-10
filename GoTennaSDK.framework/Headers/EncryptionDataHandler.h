//
//  EncryptionDataHandler.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 1/5/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TLVSection;
@class DecryptedPayloadData;
@class EncryptionInfoHeader;

@interface EncryptionDataHandler : NSObject

+ (NSData *)createGroupEncryptedMessagePayloadWithGroupGID:(NSNumber *)groupGID andSharedSecret:(NSData *)sharedSecret andOutgoingData:(NSData *)outgoingData;
+ (NSData*)createOneToOneEncryptedMessagePayloadWithRemotePublicKey:(NSData*)remotePublicKey outgoingData:(NSData*)outgoingData;
+ (NSData*)createPlainMessagePayloadWithOutgoingData:(NSData*)outgoingData;
+ (EncryptionInfoHeader *)parseEncryptionInfoHeaderWithMessagePayloadTLV:(TLVSection *)messagePayloadTLV;
+ (DecryptedPayloadData *)decryptMessagePayloadWith:(EncryptionInfoHeader *)encryptionInfoHeader
                               andMessagePayloadTLV:(TLVSection *)messagePayloadTLV
                                        andGroupGID:(NSNumber *)groupGID
                                     isGroupMessage:(BOOL)isGroupMessage;

@end
