//
//  User.h
//  GoTenna
//
//  Created by Julietta Yaunches on 25/06/2014.
//  Copyright (c) 2014 goTenna. All rights reserved.
//


#import <Foundation/Foundation.h>
@class CLLocation;
@class GoTennaKeyPair;

@interface User : NSObject <NSCoding>
@property (nonatomic, retain) NSNumber * gId;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, strong) CLLocation *lastLocation;
@property(nonatomic, strong) NSDate *lastConnectedTime;
@property(nonatomic, strong) NSDate *lastConnectionStartedTime;

+ (id)initWithUsername:(NSString *)username andGid:(NSNumber *)gId;
+ (id)initWithUsername:(NSString *)name andGID:(NSNumber *)GID;
- (id)initials;

- (void)addGroupGID:(NSNumber *)number;
- (BOOL)hasGroupGID:(NSNumber *)number;
- (void)deleteGroupGID:(NSNumber *)number;
- (NSArray<NSNumber*>*)allGroupGIDs;

@end