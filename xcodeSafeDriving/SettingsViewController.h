//
//  SettingsViewController.h
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 2/5/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SettingsViewController : UITableViewController
@property (weak, nonatomic) IBOutlet UISwitch *smsBlockSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *drunkDrivingSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *speedTrackSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *emergencyNotificationSwitch;
- (IBAction)logoutBtn:(id)sender;
- (IBAction)smsBlockOnOff:(id)sender;
- (IBAction)drunkDrivingOnOff:(id)sender;
- (IBAction)speedTrackOnOff:(id)sender;
- (IBAction)emergencyNotificationOnOff:(id)sender;

@end
