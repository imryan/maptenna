//
//  MTNodePointAnnotation.h
//  Maptenna
//
//  Created by Ryan Cohen on 5/8/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

#import <Mapbox/Mapbox.h>

@class MTNode;

@interface MTNodePointAnnotation : MGLPointAnnotation

@property (nonatomic, readonly) NSString *nodeIdentifier;

- (instancetype)initWithNode:(MTNode *)node;

@end
