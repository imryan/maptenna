//
//
//  GTCommandValidator.h
//  GoTennaSDKExample
//
//  Created by Julietta Yaunches on 4/1/15.
//  Copyright (c) 2015 gotenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GTCommandValidator : NSObject

- (BOOL)validateSendMessage:(NSData *)data destinationGID:(NSNumber *)GID onError:(void (^)(NSError *))error;

- (BOOL)validateBroadcast:(NSData *)data onError:(void (^)(NSError *))error;

- (BOOL)validateSetGoTennaGID:(NSNumber *)number onError:(void (^)(NSError *))error;
@end
