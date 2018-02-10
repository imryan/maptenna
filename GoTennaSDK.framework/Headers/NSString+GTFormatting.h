//
//  NSString+GTFormatting.h
//  GoTenna
//
//  Created by Julietta Yaunches on 16/07/2014.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (GTFormatting)
+ (NSString *)getStringFromDate:(NSDate *) date;
+ (NSString *)presentGeneratedGID:(NSNumber *) gid;
+ (NSString *)presentGID:(NSNumber *)gid;
+ (NSString *)phoneNumberCleaned:(NSString*)gidToClean;
+ (NSString *)pingStringWithDate:(NSDate *)date;

- (BOOL)isAllDigits;
- (BOOL)isValidGIDNumber;
- (NSString *)safeSubstringFromIndex:(NSUInteger)i;
@end
