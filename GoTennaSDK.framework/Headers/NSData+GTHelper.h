#import <Foundation/Foundation.h>

@interface NSData (GTHelper)
- (NSArray *)splitDataByLength:(int)unit;
+ (NSData *)swapInt:(unsigned int)theInt toByteLength:(NSUInteger)length;

- (void)safeGetBytes:(unsigned char *)string range:(NSRange)range;

- (NSData *)safeSubData:(int)position withLength:(int)length;
@end