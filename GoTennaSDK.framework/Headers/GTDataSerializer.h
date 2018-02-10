//
//  GTMessageResponseProcessor.h
//  GoTenna
//
//  Created by Julietta Yaunches on 1/8/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GTResponse;
@class SystemInfoResponseData;
@class GTMessageData;
@class GTGroupCreationMessageData;
@protocol GTMessageDataProtocol;
@class GTCommand;
@class GTBaseMessageData;
@class PacketVerifier;

@interface GTDataSerializer : NSObject

+ (GTGroupCreationMessageData *)deserializeGroupMessageDataObj:(GTMessageData *)data;
+ (SystemInfoResponseData *)deserializeSystemInfo:(GTResponse *)response;
+ (GTResponse *)deserializeMessage:(NSData *)data forCommand:(GTCommand *)command;
+ (NSData *)appTokenData;
+ (BOOL)parseAndHandleGetMessageResponse:(GTResponse *)response
                               onIncoming:(void (^)(GTMessageData *))onIncomingMessage
                           onGroupCreated:(void (^)(GTGroupCreationMessageData *))onGroupAdded
               onSuccessLastMessageDelete:(void (^)())lastMessageDelete
                   isDecryptionErrorRetry:(BOOL)isDecryptionErrorRetry;
@end
