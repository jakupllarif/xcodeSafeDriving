//
//  SettingsViewController.m
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "SettingsViewController.h"
#import <Parse/Parse.h>

@implementation SettingsViewController

- (IBAction)logout:(id)sender {
    [PFUser logOut];
    [self.view.window.rootViewController dismissViewControllerAnimated:YES completion:nil];
    //[self dismissViewControllerAnimated:YES completion:nil];
}
@end
