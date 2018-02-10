//
//  NotificationCodes.h
//  GoTenna
//
//  Created by Julietta Yaunches on 19/06/2014.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString* const FILE_TRANSFER_PROGRESS_UPDATED;
extern NSString* const FILE_TRANSFER_INCOMING_PROGRESS_UPDATED;
extern NSString* const CONTACT_LIST_UPDATED;
extern NSString* const GROUP_MEMBER_UPDATED;
extern NSString* const CONVERSATION_UPDATED;
extern NSString* const NEW_GROUP_CREATED;
extern NSString* const SIGNIFICANT_USER_LOCATION_UPDATED;
extern NSString* const OUTGOING_MESSAGE_RESPONSE_RECEIVED;
extern NSString* const NEW_MAP_DOWNLOADED;

extern NSString* const CONVERSATION_GID_DATA_KEY;
extern NSString* const SENDER_GID_DATA_KEY;
extern NSString* const FILE_TRANSFER_UUID_KEY;
extern NSString* const FILE_TRANSFER_PROGRESS_KEY;

extern NSString* const ONE_TO_ONE_ACTIVITY_FINISHED;
extern NSString* const ONE_TO_ONE_FAILED;
extern NSString* const ONE_TO_ONE_FAILED_FILE_TRANSFER;
extern NSString* const ONE_TO_ONE_QUICK_REDO;
extern NSString* const ONE_TO_ONE_NEXT_CHUNK_FILE_TRANSFER;
extern NSString* const ONE_TO_ONE_CANCEL_FILE_TRANSFER;
extern NSString* const ONE_TO_ONE_SUCCEEDED;
extern NSString* const ONE_TO_ONE_SUCCEEDED_FILE_TRANSFER;

extern NSString *const GTNOTIFICATIONS_WRITE_ERROR_OCCURED;
extern NSString *const GTNOTIFICATIONS_WRITE_TIMEOUT_OCCURED;
extern NSString *const GTNOTIFICATIONS_PARSING_ERROR_OCCURED;
extern NSString *const GTNOTIFICATIONS_RSSI_READING_EVENT;
extern NSString *const GTNOTIFICATIONS_LOGGING_EVENT;
extern NSString *const GTNOTIFICATIONS_ANALYTICS_EVENT;

extern NSString *const GTCONNECTION_LOST;
extern NSString *const GTUSER_DISCONNECT;
extern NSString *const GTCONNECTION_LOST_AFTER_RETRYING;
extern NSString *const GTCONNECTION_ESTABLISHED;

extern NSString *const GTNEW_FIRMWARE_VERSION_AVAILABLE;

extern NSString *const GTNEW_HALT_TEST_RESULTS;
