//
//  GTSendCommand.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 3/14/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import "GTCommand.h"

@interface GTSendCommand : GTCommand


/** The `GTSendCommand` handles the send message commands for the CommandBuilder.
 * It inherits from GTCommand
 */

- (instancetype)initWithOutgoingData:(NSData*)outgoingData SenderGID:(NSNumber*)senderGID recipientGID:(NSNumber*)recipientGID willEncrypt:(BOOL)willEncrypt;

@property (nonatomic, readonly) NSData *outgoingData;
@property (nonatomic, readonly) NSNumber *senderGID;
@property (nonatomic, readonly) NSNumber *recipientGID;
@property (nonatomic, readonly) BOOL willEncrypt;

@end