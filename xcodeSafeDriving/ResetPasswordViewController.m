//
//  ResetPasswordViewController.m
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 2/6/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "ResetPasswordViewController.h"
#import <Parse/Parse.h>

@interface ResetPasswordViewController () {
    NSString *email;
}

@end

@implementation ResetPasswordViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

-(void)viewDidAppear:(BOOL)animated {
    self.emailAddressField.delegate = self;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return NO;
}

//dismiss keyboard when user touch anyother place outside textfield
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}

- (IBAction)resetPasswordBtn:(id)sender {
    PFQuery *query = [PFUser query];
    email = _emailAddressField.text;
    if (email != nil) {
        [query whereKey:@"email" equalTo:email];
        [query getFirstObjectInBackgroundWithBlock:^(PFObject *object, NSError *error) {
            if (!error) {
                [PFUser requestPasswordResetForEmailInBackground:email];
            } else {
                UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Ooooopss!" message:[error userInfo][@"error"] delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
                [alert show];
            }
        }];
    }
    
}
@end
