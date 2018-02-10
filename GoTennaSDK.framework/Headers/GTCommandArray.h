//
//  GTCommandArray.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 11/14/15.
//  Copyright © 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GTCommand.h"

@interface GTCommandArray : NSObject

@property (nonatomic) GTCommandPriority priority;

- (void)addGTCommand:(GTCommand*)command;
- (void)addGTCommandsFromArray:(NSArray*)commands;

- (void)each:(void (^)(id object))block;

- (NSArray*)toArray;
@end
