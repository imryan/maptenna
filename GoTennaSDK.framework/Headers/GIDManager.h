#import <Foundation/Foundation.h>
#import "GTDataTypes.h"

@class UserDataStore;
extern NSString const *EMERGENCY_GID;
extern NSString const *SHOUT_GID;

@interface GIDManager : NSObject
+ (NSNumber *)shoutGID;
+ (NSNumber*)emergencyGID;
+ (BOOL)senderIsGoTennaHQ:(NSNumber *)number;
+ (GTGIDType)gidTypeForGID:(NSNumber *)number;

- (NSNumber *)personalGIDFromDate:(NSDate *)date;
- (NSNumber *)groupGIDFromDate:(NSDate *)date;
@end