//
//  ViewController.h
//  xcodeSafeDriving
//
//  Created by Flodjana Jakupllari on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Parse/Parse.h>

@interface ViewController : UIViewController
//login view
@property (weak, nonatomic) IBOutlet UITextField *usernameField;
@property (weak, nonatomic) IBOutlet UITextField *passwordField;
- (IBAction)loginBtn:(id)sender;
- (IBAction)registerBtn:(id)sender;

//register view
@property (weak, nonatomic) IBOutlet UIView *registerLayout;
@property (weak, nonatomic) IBOutlet UITextField *rfnameField;
@property (weak, nonatomic) IBOutlet UITextField *rlnameField;
@property (weak, nonatomic) IBOutlet UITextField *rphoneNumberField;
@property (weak, nonatomic) IBOutlet UITextField *rusernameField;
@property (weak, nonatomic) IBOutlet UITextField *rpasswordField;
@property (weak, nonatomic) IBOutlet UITextField *rrepasswordField;
@property (weak, nonatomic) IBOutlet UITextField *remailField;
@property (weak, nonatomic) IBOutlet UITextField *rgenderField;
@property (weak, nonatomic) IBOutlet UITextField *rbloodGroupField;
@property (weak, nonatomic) IBOutlet UITextField *rbirthdayField;
- (IBAction)Register:(id)sender;

@end
