//
//  BCTSServiceInfo.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 11/10/15.
//  Copyright © 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BCTSServiceInfo : NSObject

+ (BCTSServiceInfo *)shared;

//commands
- (void)prepareToSendCommand;
- (void)commandFinished;
- (void)setProtocolVersion:(float)protocolVersion;

//queries
- (BOOL)isCommandSendWindowOfOpportunityOpen;

@end