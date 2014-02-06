//
//  SettingsViewController.m
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 2/5/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "SettingsViewController.h"
#import <Parse/Parse.h>

@interface SettingsViewController()
{
    PFUser *currentuser;
}
@end

@implementation SettingsViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    currentuser = [PFUser currentUser];
}

-(void)viewWillAppear:(BOOL)animated{
    [currentuser refresh];
    if (currentuser) {
        _smsBlockSwitch.on = [[currentuser objectForKey:@"smsBlock"]boolValue];
        _drunkDrivingSwitch.on = [[currentuser objectForKey:@"drunkDriving"]boolValue];
        _speedTrackSwitch.on = [[currentuser objectForKey:@"speedTrack"]boolValue];
        _emergencyNotificationSwitch.on = [[currentuser objectForKey:@"emergencyNotification"]boolValue];
    }
}


- (IBAction)logoutBtn:(id)sender {
    [PFUser logOut];
    [self.view.window.rootViewController dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)smsBlockOnOff:(id)sender {
    currentuser[@"smsBlock"] = _smsBlockSwitch.on ? @YES : @NO;
    [currentuser saveInBackground];
}

- (IBAction)drunkDrivingOnOff:(id)sender {
    currentuser[@"drunkDriving"] = _drunkDrivingSwitch.on ? @YES : @NO;
    [currentuser saveInBackground];
}

- (IBAction)speedTrackOnOff:(id)sender {
    currentuser[@"speedTrack"] = _speedTrackSwitch.on ? @YES : @NO;
    [currentuser saveInBackground];
}

- (IBAction)emergencyNotificationOnOff:(id)sender {
    currentuser[@"emergencyNotification"] = _emergencyNotificationSwitch.on ? @YES : @NO;
    [currentuser saveInBackground];
}
@end
