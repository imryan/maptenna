//
//  GTCRC16.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 1/5/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Runs the CRC operation - useful for encryption and overall data integrity
 */

@interface GTCRC16 : NSObject

+ (unsigned short)getCRC16ChecksumForData:(NSData *)data;
+ (int)getCRC32ChecksumForData:(NSData *) data;
@end
