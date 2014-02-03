//
//  RegisterViewController.h
//  xcodeSafeDriving
//
//  Created by Flodjana Jakupllari on 2/2/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RegisterViewController : UITableViewController

@property (weak, nonatomic) IBOutlet UITextField *rfnameField;
@property (weak, nonatomic) IBOutlet UITextField *rlnameField;
@property (weak, nonatomic) IBOutlet UITextField *rgenderField;
@property (weak, nonatomic) IBOutlet UITextField *rbirthdayField;
@property (weak, nonatomic) IBOutlet UITextField *rbloodGroupField;
@property (weak, nonatomic) IBOutlet UITextField *rphoneNumberField;
@property (weak, nonatomic) IBOutlet UITextField *rusernameField;
@property (weak, nonatomic) IBOutlet UITextField *rpasswordField;
@property (weak, nonatomic) IBOutlet UITextField *rrepasswordField;
@property (weak, nonatomic) IBOutlet UITextField *remailField;

@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *ractivityLayView;

- (IBAction)Register:(id)sender;


@end
