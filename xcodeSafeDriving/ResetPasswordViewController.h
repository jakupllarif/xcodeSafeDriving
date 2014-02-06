//
//  ResetPasswordViewController.h
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 2/6/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ResetPasswordViewController : UIViewController<UIAlertViewDelegate, UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UITextField *emailAddressField;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *resetActivity;
- (IBAction)resetPasswordBtn:(id)sender;

@end
