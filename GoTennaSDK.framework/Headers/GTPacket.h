//
//  GTPacket.h
//  GoTenna
//
//  Created by Julietta Yaunches on 19/06/2014.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Data packet to be sent to goTenna
 */

@interface GTPacket : NSObject
@property(nonatomic, strong) NSData *data;
@property(nonatomic) BOOL successfullySent;

- (id)initWithChunk:(NSData *)data;
@end
