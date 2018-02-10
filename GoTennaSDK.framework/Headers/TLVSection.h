//
//  TLVSection.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 12/14/15.
//  Copyright © 2015 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TLVSection : NSObject

- (instancetype)initWithType:(int)type value:(NSData*)value;
+ (NSArray<TLVSection*> *)tlvSectionsFromData:(NSData*)data;
+ (TLVSection*)createTLVFromData:(NSData*)data;
+ (NSData*)createDataFromTLVWithType:(int)type value:(NSData*)value;

//queries
- (int)type;
- (int)length;
- (int)fullLength;
- (NSData*)value;

- (NSData*)toBytes;
- (NSString*)toString;
- (NSData*)tlvSectionToData:(NSArray<TLVSection*> *)tlvSections;

@end
