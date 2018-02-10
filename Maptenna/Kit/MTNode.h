//
//  MTNode.h
//  Maptenna
//
//  Created by Ryan Cohen on 4/30/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

@class MTUser;

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface MTNode : NSObject

@property (nonatomic, readonly) MTUser *owner;
@property (nonatomic, readonly) NSNumber *uptime;
@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) NSNumber *batteryLevel;
@property (nonatomic, readonly) CLLocation *location;

/**
 Always call when referring to the current user's node
 
 @return Shared instance
 */
+ (instancetype)currentNode;

/**
 Creates node object with owner and initial location
 
 @param  owner    Node's owner
 @param  location Node's coordinates
 
 @return Instance of node
 */
- (instancetype)initWithOwner:(MTUser *)owner location:(CLLocation *)location;

/**
 Update node location
 
 @param location Node's new coordinates
 */
- (void)updateNodeLocation:(CLLocation *)location;

/**
 Formatted display name
 
 @return Formatted node display name
 */
- (NSString *)displayName;

@end
