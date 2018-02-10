//
//  MTNodeAnnotation.m
//  Maptenna
//
//  Created by Ryan Cohen on 4/30/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

#import "MTNodeAnnotation.h"

@implementation MTNodeAnnotation

- (void)layoutSubviews {
    [super layoutSubviews];
    
    // Force the annotation view to maintain a constant size when the map is tilted.
    self.scalesWithViewingDistance = NO;

    self.layer.cornerRadius = self.frame.size.width / 2;
    self.backgroundColor = [[UIColor blueColor] colorWithAlphaComponent:0.2f];
}

//- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
//    [super setSelected:selected animated:animated];
//    
//    // Animate the border width in/out, creating an iris effect.
//    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"borderWidth"];
//    animation.duration = 0.1;
//    self.layer.borderWidth = selected ? self.frame.size.width / 4 : 2;
//    [self.layer addAnimation:animation forKey:@"borderWidth"];
//}

@end
