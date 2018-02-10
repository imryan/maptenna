//
//  ChatViewController.h
//  Maptenna
//
//  Created by Ryan Cohen on 4/29/17.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ChatViewController : UIViewController <UITableViewDataSource, UITabBarDelegate>

@property (nonatomic, strong) NSNumber *creatorGID;

@end
