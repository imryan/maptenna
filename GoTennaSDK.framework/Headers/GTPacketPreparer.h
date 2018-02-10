#import <Foundation/Foundation.h>


@interface GTPacketPreparer : NSObject
- (NSMutableData *)prepare:(NSMutableData *)data;
- (NSData *)addDataLinkEscapesToData:(NSData *)data;

- (NSData *)unescapeData:(NSMutableData *)data;
@end