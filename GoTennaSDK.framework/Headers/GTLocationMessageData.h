//
//  GTLocationMessageData.h
//  GoTenna
//
//  Created by Julietta Yaunches on 11/14/14.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import "GTMessageDataProtocol.h"
@class TLVSection;

@interface GTLocationMessageData : NSObject<GTMessageDataProtocol>
@property(nonatomic, strong) NSNumber *locationType;
@property(nonatomic, strong) NSNumber *latitude;
@property(nonatomic, strong) NSNumber *longitude;
@property(nonatomic, copy) NSString *name;

- (id)initFromOrderedData:(NSArray<TLVSection*> *)tlvSections withSenderGID:(NSNumber *)senderGID;
- (id)initWithLocationType:(NSNumber *)number andLatitude:(NSNumber *)latitude andLongitude:(NSNumber *)longitude andName:(NSString *)name onError:(NSError **)error;

- (NSArray<TLVSection *> *)getTLVSections;
- (NSData *)serializeToBytes;
@end