//
//  MaptennaKit.h
//  Maptenna
//
//  Created by Ryan Cohen on 4/29/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

@import GoTennaSDK;

@class MaptennaKit;

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "MTUser.h"
#import "MTNode.h"
#import "MTNodeRequest.h"

static NSString * _Nonnull kMTNodeIdentifierKey = @"kMTNodeIdentifierKey";

@protocol MaptennaKitDelegate <NSObject>

@required
- (void)maptenna:(MaptennaKit * _Nonnull)maptenna didReceiveNodeUpdateRequest:(MTNodeRequest * _Nonnull)request;

@required
- (void)maptenna:(MaptennaKit * _Nonnull)maptenna didReceiveNodeUpdate:(MTNode * _Nonnull)node;

@optional
- (void)maptenna:(MaptennaKit * _Nonnull)maptenna didPostNodeUpdate:(MTNode * _Nonnull)node;

@end

typedef void (^MaptennaErrorBlock)(NSError * _Nullable error);
typedef void (^MaptennaUserUpdateBlock)(MTUser * _Nullable user, MTNode * _Nullable node, NSError * _Nullable error);
typedef void (^MaptennaParseIncomingBlock)(id _Nullable object);

@interface MaptennaKit : NSObject

/**
 Receive callbacks for location and node updates
 */
@property (nonatomic, weak) id <MaptennaKitDelegate> delegate;

/**
 Singleton
 
 @return Shared class instance
 */
+ (nonnull instancetype)shared;

/**
 Update user
 
 @param gid  User's GID
 @param name User's public display name
 */
- (void)updateUserWithGID:(nonnull NSNumber *)gid name:(nonnull NSString *)name block:(nonnull MaptennaUserUpdateBlock)block;

/**
 Updates devices last location
 
 @param gid   GID from node update request
 @param block Returns error if so, otherwise nil
 */
- (void)updateDeviceLocationForGID:(nonnull NSNumber *)gid block:(nullable MaptennaErrorBlock)block;

/**
 Request nearby node locations
 
 @param block Returns error if so, otherwise nil
 */
- (void)requestNearbyNodesUpdate:(nullable MaptennaErrorBlock)block;

/** DEPRECATED
 Sends device location at the specified interval
 
 @param interval Time in seconds to update location
 */
- (void)beginUpdatingDeviceLocationAtInterval:(NSTimeInterval)interval NS_UNAVAILABLE;

/**
 Parse incoming message
 
 @param messageData Incoming message object to be deserialized
 @param block       Returns instance of `MTNode` if successful
 */
- (void)parseIncomingMessage:(nonnull GTMessageData *)messageData block:(nonnull MaptennaParseIncomingBlock)block;

@end
