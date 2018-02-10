//
//  GTGid.h
//  GoTenna
//
//  Created by Julietta Yaunches on 3/2/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTDataTypes.h"

/**
 *  Handles GID values allowing for conversion to different formats
 */

@interface GTGid : NSObject

/**
 *  Readonly baseNumber value
 */
@property(nonatomic, strong, readonly) NSNumber *baseNumber;

/**
 *  Current GID type
 */
@property(nonatomic) GTGIDType type;

/**
 *  initialization method for `GTGID`
 *
 *  @param number GID value
 *
 *  @return `GTGID` instance
 */
+ (GTGid *)initWithBase:(NSNumber *)number;

/**
 *  initialization method for `GTGID`
 *
 *  @param number GID data
 *
 *  @return `GTGID` instance
 */
+ (GTGid *)initfromData:(NSData *)data;

/**
 *  String value of the GID
 *
 *  @return string value representation of GID
 */
- (NSString *)built;

/**
 *  Data representation of GID
 *
 *  @return gid as NSData
 */
- (NSData *)asData;

/**
 *  Data representation of GID with type and token data
 *
 *  @return gid as NSData along with type and token data inside
 */
- (NSData *)asDataWithType;

/**
 *  Data with type using membership byte
 *
 *  @param membershipByte membership byte used internally for the most part
 *
 *  @return gid as NSData along with type and token data inside, along with membership info if relevant
 */
- (NSData *)asDataWithTypeUsingMembershipByte:(NSData*)membershipByte;


/**
 *  Byte length for GIDData
 *
 *  @return byte length
 */
- (NSUInteger)GIDDataByteLength;
@end
