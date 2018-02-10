//
//  UserDataStore.h
//  GoTenna
//
//  Created by Julietta Yaunches on 4/06/2014.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@class User;
@class CLLocation;
@class GTSecurityService;

@interface UserDataStore : NSObject
+ (UserDataStore *)shared;
- (BOOL)saveUser:(User *)user;
- (void)deleteUser;
- (User *)currentUser;
- (BOOL)userIsLoggedIn;
- (BOOL)userIsUpdatingFirmware;
- (BOOL)isMyGID:(NSNumber *)gid;
- (BOOL)userHasOnboarded;
- (void)addGroupGID:(NSNumber *)number;
- (void)deleteGroupGID:(NSNumber *)number;
- (User *)registerUserWithName:(NSString *)username andGid:(NSNumber *)gid;
- (BOOL)hasValidUser;
@end
