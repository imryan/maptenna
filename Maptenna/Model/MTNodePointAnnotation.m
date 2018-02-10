//
//  MTNodePointAnnotation.m
//  Maptenna
//
//  Created by Ryan Cohen on 5/8/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

#import "MTNodePointAnnotation.h"
#import "MTNode.h"

@interface MTNodePointAnnotation ()

@property (nonatomic, strong) MTNode *node;
@property (nonatomic, strong) NSString *nodeIdentifier;

@end

@implementation MTNodePointAnnotation

- (instancetype)initWithNode:(MTNode *)node {
    self = [super init];
    
    if (self) {
        if (self.node != nil) {
            self.node = node;
            self.title = [node displayName];
            self.subtitle = [NSString stringWithFormat:@"Last pinged: %@", [NSDate date]];
            self.coordinate = [node.location coordinate];
            self.nodeIdentifier = node.identifier;
        }
    }
    
    return self;
}

@end
