//
// Created by Julietta Yaunches on 5/06/2014.
// Copyright (c) 2014 goTenna. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "GTDataTypes.h"
#import "GTResponse.h"
#import "GTCommand.h"
#import "GTGroupCreationMessageData.h"

@class SystemInfoResponseData;
@class GTError;
@class FrequencyMode;
@class BinaryLogResponseData;
@class GTCommandArray;
@class GTFrequencyChannel;

/**
 * `GTCommandCenter` is the lifeblood of the application,
 * all commands to be sent to the goTenna must go through this class.
 * This is the way in which one is to communicate with a goTenna
 */

@interface GTCommandCenter : NSObject
@property(nonatomic, copy) void (^onIncomingMessage)(GTMessageData *);

+ (GTCommandCenter *)shared;

// SDK methods for partners

// Send echo
// This is essentially a ping to your goTenna to make sure that it's connected and functioning
//
// parameters:
// onResponse
//      - called when your goTenna responds with a postive or negative acknowledgement
// onError
//      - required
//      - called when an error occurs (See error code for details)
- (void)sendEchoCommand:(void (^)(GTResponse *))onResponse onError:(void (^)(NSError *))onError;

// Set goTennaGID
// This method is used to set a goTenna's unique GID. This GID is used for one-to-one messaging.
// When this gets set, the previous one-to-one GID for the connected goTenna will be erased and the new
// GID set.
//
// parameters:
// number
//      - must be an NSNumber 15 digits or less
// onError
//      - required
//      - called when an error occurs (See error code for details)
- (void)setgoTennaGID:(NSNumber *)number withUsername:(NSString *)username onError:(void (^)(NSError *))onError;

// One-to-one Messaging
// With this you send a single message to another goTenna user. This is the only means of
// sending a message where you'll receive negative or positive confirmation that the receiver
// received your message
//
// NOTE: must have set goTenna GID before calling this
// NOTE: if your receiver needs to know the sender's GID, you'll need to send it in the payload
//
// parameters:
// messageData
//      - must be 160 characters or less
// destinationGID
//      - must be an NSNumber 15 digits or less
//      - cannot be 111-111-1111
// onResponse
//      - called when your goTenna responds
//      - responseCode in GTResponse can be used to determine whether receiver received the message
// onError
//      - required
//      - called when an error occurs (See error code for details)
- (void)sendMessage:(NSData *)messageData encrypt:(BOOL)encryptionEnabled toGID:(NSNumber *)destinationGID fromGID:(NSNumber *)senderGID onResponse:(void (^)(GTResponse *))success onError:(void (^)(NSError *))onError;

// Delete GID
// User to delete Group GIDs from your goTenna. AFter calling this, you should receive no further messages for the
// given GID.
// NOTE: if you call this with the goTenna's unique GID, you'll need to call setgoTennaGID before continueing to use
// your goTenna. You do NOT need to call this before updating your goTenna's unique GID
//
// parameters:
// gidToDelete
//      - the GID that should be removed from
// onError
//      - required
//      - called when an error occurs (See error code for details)
- (void)deleteGID:(NSNumber *)gidToDelete onError:(void (^)(NSError *))onError;

// Broadcast Messaging
// Data sent using this is sent to all goTennas in range. There is no confirmation of
// receipt of message by any goTennas
//
// parameters:
// messageData
//      - must be 160 characters or less
// onError
//      - required
//      - called when an error occurs (See error code for details)
- (void)sendBroadcast:(NSData *)messageData toGID:(NSNumber*)destinationGID onResponse:(void (^)(GTResponse *))success onError:(void (^)(NSError *))onError;

// Create Group with GIDs
// Call this method to create a group.
// You must have the unique GIDs for all members of the group.
// When you call this, a one-to-one message is sent to each member of the group notifying them of group creation
// NOTE: if the group is large, this method can take a while to process as each message goes out
//
// parameters:
// memberGIDs
//      - Cannot include either 1111111111
//      - Cannot include any other group GIDs
//      - Can not exceed 10 members
// onMemberResponse
//      - called for each member response to the group create message
//      - responseCode in GTResponse can be used to determine whether receiver received the message (and subsequently knows about the group)
// onError
//      - required
//      - called when an error occurs (See error code for details)
- (NSNumber *)createGroupWithGIDs:(NSArray *)memberGIDs encrypt:(BOOL)willEncrypt onMemberResponse:(void (^)(GTResponse *, NSNumber *memberGID))onMemberResponse fromGID:(NSNumber*)senderGID onError:(void (^)(NSError *, NSNumber *))onError;

// Set block to perform when receiving a group creation message
// As a member of a created group, you need to know when you've been added to a group. Here, set the block to be called when
// you are added to a group
//
// NOTE: you must have called setGotennaGID with your unique GID to receive these messages
//
// parameters:
// externalOnGroupCreate
//      - called when you are added to a group
//      - GTGroupCreationMessageData contains information about the group you've been added to
- (void)setOnGroupCreated:(void (^)(GTGroupCreationMessageData *))externalOnGroupCreate;

- (void)sendGetSystemInfoOnSuccess:(void (^)(SystemInfoResponseData *))onSuccess onError:(void (^)(NSError *))onError;

//SDK methods not for partners
- (void)sendSetAppTokenOnResponse:(void (^)(GTResponse *))onResponse onError:(void (^)(NSError *))error;
- (void)sendDisconnectGotenna;
- (void)resetGotenna;
- (void)setPublicKey:(NSData *)publicKey;
- (void)queueCommand:(GTCommand *)command;
- (void)resetQueue;
- (void)dispatchResponse:(NSMutableData *)response;
- (void)sendGetMessageRequest;
- (void)abortCurrentCommand;
- (void)addGroupGID:(NSNumber *)number;
- (void)sendStoreDateTime;
- (void)pauseQueue;
- (void)queuePriorityCommands:(GTCommandArray *)array;
- (void)executeUpcomingQueueCommand;
- (void)sendHardReset;
- (void)sendPublicKeyRequestToGID:(NSNumber *)destinationGID;
- (void)sendPublicKeyResponseToGID:(NSNumber *)destinationGID;
- (void)sendFrequencyChannels:(NSArray <GTFrequencyChannel *> *)frequencyChannels
                    onSuccess:(void (^)(GTResponse *))onResponse
                      onError:(void (^)(NSError *))error;

@end
