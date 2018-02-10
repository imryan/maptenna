//
//  MTNode.m
//  Maptenna
//
//  Created by Ryan Cohen on 4/30/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

#import "MTNode.h"
#import "MTUser.h"
#import "MaptennaKit.h"
#import <CommonCrypto/CommonCrypto.h>

@interface MTNode ()

@property (nonatomic, strong) MTUser *owner;
@property (nonatomic, strong) NSNumber *uptime;
@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) CLLocation *location;

@end

@implementation MTNode

# pragma mark - Init

+ (instancetype)currentNode {
    static MTNode *node = nil;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        node = [self new];
    });
    
    return node;
}

- (instancetype)initWithOwner:(MTUser *)owner location:(CLLocation *)location {
    self = [super init];
    
    if (self) {
        self.owner = owner;
        self.location = location;
        self.uptime = @0;
        
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            [self generateHashedIdentifier];
        });
    }
    
    return self;
}

# pragma mark - Functions

- (void)updateNodeLocation:(CLLocation *)location {
    self.location = location;
}

- (void)generateHashedIdentifier {
    if (![[NSUserDefaults standardUserDefaults] stringForKey:kMTNodeIdentifierKey]) {
        self.identifier = [self generateSHA256String:self.owner.gid];
        
        [[NSUserDefaults standardUserDefaults] setObject:self.identifier forKey:kMTNodeIdentifierKey];
        [[NSUserDefaults standardUserDefaults] synchronize];
    } else {
        self.identifier = [[NSUserDefaults standardUserDefaults] stringForKey:kMTNodeIdentifierKey];
    }
}

- (NSString *)displayName {
    return self.owner.name;
}

# pragma mark - Helpers

- (NSString *)generateSHA256String:(NSNumber *)gid {
    const char *cstr = [gid.stringValue cStringUsingEncoding:NSUTF8StringEncoding];
    NSData *data = [NSData dataWithBytes:cstr length:gid.stringValue.length];
    uint8_t digest[CC_SHA256_DIGEST_LENGTH];
    
    CC_SHA256(data.bytes, (uint32_t)data.length, digest);
    
    NSMutableString *output = [NSMutableString stringWithCapacity:CC_SHA256_DIGEST_LENGTH * 2];
    
    for (int i = 0; i < CC_SHA256_DIGEST_LENGTH; i++) {
        [output appendFormat:@"%02x", digest[i]];
    }
    
    return output;
}

@end
