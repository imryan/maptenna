//
//  GoTenna.h
//  GoTenna
//
//  Created by Julietta Yaunches on 3/2/15.
//  Copyright (c) 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GoTenna : NSObject

/** Sets the application token for the app, this is a necessary condition
 * for any goTenna operations to function thereafter
 */

// commands
+ (void)setApplicationToken:(NSString *)number;

// queries
+ (NSData *)applicationToken;

@end
