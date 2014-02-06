//
//  SettingsViewController.h
//  xcodeSafeDriving
//
//  Created by Flodjana Jakupllari on 2/2/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SettingsViewController : UITableViewController
- (IBAction)logout:(id)sender;
@property (weak, nonatomic) IBOutlet UITableView *settingsTableController;
- (IBAction)drunkBtn:(id)sender;
- (IBAction)overspeedBtn:(id)sender;
- (IBAction)messageBlockBtn:(id)sender;
- (IBAction)emergencyBtn:(id)sender;
@property (weak, nonatomic) IBOutlet UISwitch *drunkBtnOutlet;
@property (weak, nonatomic) IBOutlet UISwitch *overspeedBtnOutlet;
@property (weak, nonatomic) IBOutlet UISwitch *messageBlockBtnOutlet;
@property (weak, nonatomic) IBOutlet UISwitch *emergencyBtnOutlet;

@end
