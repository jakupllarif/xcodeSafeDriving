//
//  SettingViewController.m
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 2/5/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "SettingViewController.h"
#import <Parse/Parse.h>

@implementation SettingViewController

- (IBAction)logoutBtn:(id)sender {
    [PFUser logOut];
    [self.view.window.rootViewController dismissViewControllerAnimated:YES completion:nil];
}
@end
