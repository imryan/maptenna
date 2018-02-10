//
// Created by Julietta Yaunches on 11/4/14.
// Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GTCommand;
@class GTResponse;
@class SystemInfoResponseData;
@protocol GTMessageDataProtocol;
@class GTFirmwareVersion;
@class GTGid;
@class GTGroupCreationMessageData;
@class GTMessageData;
@class GTError;
@class FrequencyMode;
@class GTFrequencyChannel;

@interface GTCommandBuilder : NSObject

- (GTCommand *)buildSetGID:(GTGid *)number onError:(void (^)(NSError *))error;
- (GTCommand *)buildResetGotenna;
- (GTCommand *)buildSetPublicKey:(NSData *)publicKey;
- (GTCommand *)buildSendMessageCommand:(NSData *)outgoingData
                                 toGID:(GTGid *)addresseeGID
                            onResponse:(void (^)(GTResponse *))onResponse
                               onError:(void (^)(NSError *))onError
                           willEncrypt:(BOOL)willEncrypt;
- (GTCommand *)buildDeleteLastMessage;
- (GTCommand *)buildGetMessageWithOnSuccess:(void (^)(GTMessageData *))onIncomingMessage
                             onGroupCreated:(void (^)(GTGroupCreationMessageData *))onGroupAdded
                 onSuccessLastMessageDelete:(void (^)())lastMessageDelete;
- (GTCommand *)buildEchoCommandOnResponse:(void (^)(GTResponse *))onSuccess onError:(void (^)(NSError *))error;
- (GTCommand *)buildDisconnectGotenna;
- (GTCommand *)buildDeleteGID:(GTGid *)number onError:(void (^)(NSError *))error;
- (GTCommand *)buildGetSystemInfoOnError:(void (^)(NSError *))pFunction;
- (GTCommand *)setAppTokenOnResponse:(void (^)(GTResponse *))onResponse onError:(void (^)(NSError *))error;

//Update firmware commands
- (GTCommand *)buildInitiateFirmware:(int)numCommands totalNumOfBytesSending:(int)numBytes;
- (GTCommand *)buildWriteFirmware:(NSData *)data;
- (GTCommand *)buildAbortFirmwareUpdate:(GTFirmwareVersion *)version;
- (GTCommand *)buildFinalizeFirmwareUpdateForVersion:(GTFirmwareVersion *)version;

- (GTCommand *)buildStoreDateTime:(NSString *)emergencyMessage;
- (GTCommand *)buildHardReset;
- (GTCommand *)buildFrequencyCommandWithChannels:(NSArray <GTFrequencyChannel *> *)frequencyChannels
                                       onSuccess:(void (^)(GTResponse *))onResponse
                                         onError:(void (^)(NSError *))error;

@end