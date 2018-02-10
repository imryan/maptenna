//
//  MTNodeViewController.m
//  Maptenna
//
//  Created by Ryan Cohen on 5/22/17.
//  Copyright © 2017 goTenna. All rights reserved.
//

#import "MTNodeViewController.h"

#import "MTNode.h"

@interface MTNodeViewController ()

@property (nonatomic, strong) MTNode *node;

@end

@implementation MTNodeViewController

# pragma mark - Init

- (instancetype _Nonnull)initWithNode:(nonnull MTNode *)node {
    self = [super init];
    
    if (self) {
        self.node = node;
    }
    
    return self;
}

# pragma mark - View

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */

@end
