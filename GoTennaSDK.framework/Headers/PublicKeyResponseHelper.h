//
//  PublicKeyResponseHelper.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 1/4/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PublicKeyResponseHelper : NSObject


//commands
- (void)registerPublicKeyResponseUsingData:(NSData*)data forConversationTypeCondition:(BOOL)condition receivingGID:(NSNumber*)receivingGID;

//queries
- (BOOL)publicKeyRegistered;

@end
