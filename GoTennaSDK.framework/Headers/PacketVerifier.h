//
//  PacketVerifier.h
//  GoTenna
//
//  Created by Thomas Colligan on 1/26/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Checks to see if we have recorded a packet with the same ID already.
 * If we have, it will tell us so we can reject the packet.
 *
 * This helps us to prevent replay attacks and pulling duplicate messages.
 */
@interface PacketVerifier : NSObject

/**
 * Singleton Instance Method.
 */
+ (instancetype)shared;

/**
 * Records a packetId so we can prevent replay attacks or re-pulling the same message again.
 * @param packetId The packetId we want to record.
 */
- (void)addVerifiedPacketId:(NSString *)packetId;

/**
 * Checks to see if we have already recorded the packet id on an incoming packet.
 *
 * @param packetId The id of the packet we want to check.
 * @return YES if we have already recorded this packetId.
 */
- (BOOL)isDuplicatePacketId:(NSString *)packetId;

@end
