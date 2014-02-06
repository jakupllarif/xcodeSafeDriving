//
//  ViewController.h
//  xcodeSafeDriving
//
//  Created by Flodjana Jakupllari on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController<UITextFieldDelegate>
//login view
@property (weak, nonatomic) IBOutlet UITextField *usernameField;
@property (weak, nonatomic) IBOutlet UITextField *passwordField;
- (IBAction)loginBtn:(id)sender;

@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityLayView;
 

@end
