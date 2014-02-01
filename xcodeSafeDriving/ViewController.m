//
//  ViewController.m
//  xcodeSafeDriving
//
//  Created by Flodjana Jakupllari on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "ViewController.h"
#import <Parse/Parse.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidAppear:(BOOL)animated{
    PFUser *user = [PFUser currentUser];
    [user refresh];
    if (user.username != nil)
        [self performSegueWithIdentifier:@"login" sender:self];
    self.passwordField.delegate = self;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return NO;
}

//dismiss keyboard when user touch anyother place outside textfield
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}

- (IBAction)loginBtn:(id)sender {
    [_activityLayView startAnimating];
    NSLog(@"Logging in");
    [PFUser logInWithUsernameInBackground:_usernameField.text password:_passwordField.text block:^(PFUser *user, NSError *error) {
        if (!error) {
            [_activityLayView stopAnimating];
            _usernameField.text = @"";
            _passwordField.text = @"";
            NSLog(@"Login user!");
            [self performSegueWithIdentifier:@"login" sender:self];
        }
        if (error) {
            [_activityLayView stopAnimating];
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Ooooopss!" message:[error userInfo][@"error"] delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
            [alert show];
        }
    }];

}

- (IBAction)registerBtn:(id)sender {
    [UIView animateWithDuration:0.3 animations:^{
        _registerLayout.frame = self.view.frame;
    }];
}

- (IBAction)resetPasswordBtn:(id)sender {
}

- (IBAction)Register:(id)sender {
    [_rfnameField resignFirstResponder];
    [_rlnameField resignFirstResponder];
    [_rphoneNumberField resignFirstResponder];
    [_rusernameField resignFirstResponder];
    [_rpasswordField resignFirstResponder];
    [_rrepasswordField resignFirstResponder];
    [_remailField resignFirstResponder];
    [_rgenderFirld resignFirstResponder];
    [_rbloodGroupField resignFirstResponder];
    [_rbirthdayField resignFirstResponder];
    [self validateUserData];
}

//validate if all entered data is correct and then register the user
- (void) validateUserData {
    if ([self checkFieldComplete])
        if([self checkPhoneNumber])
            if([self checkPasswordsMatch])
                [self registerNewUser];
}

- (Boolean) checkFieldComplete {
     if ([_rfnameField.text isEqualToString:@""] || [_rlnameField.text isEqualToString:@""] || [_rphoneNumberField.text isEqualToString:@""] || [_rusernameField.text isEqualToString:@""] || [_rpasswordField.text isEqualToString:@""] || [_rrepasswordField.text isEqualToString:@""] || [_remailField.text isEqualToString:@""] || [_rgenderFirld.text isEqualToString:@""] || [_rbloodGroupField.text isEqualToString:@""] || [_rbirthdayField.text isEqualToString:@""]) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Ooooopss!" message:@"You need to complete all fields" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        [alert show];
         return false;
    }else
        return true;
}

- (Boolean) checkPhoneNumber{
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"^\\d{10,15}$" options:0 error:NULL];
    NSTextCheckingResult *match = [regex firstMatchInString:_rphoneNumberField.text options:0 range:NSMakeRange(0, [_rphoneNumberField.text length])];
    if (!match) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Ooooopss" message:@"Please enter a valid phone number" delegate:nil cancelButtonTitle:@"Dismiss" otherButtonTitles:nil, nil];
        [alert show];
        return false;
    } else
        return true;
}

- (Boolean) checkPasswordsMatch {
    if ([_rpasswordField.text length] >= 6 && [_rpasswordField.text length] <= 14) {
        if (![_rpasswordField.text isEqualToString:_rrepasswordField.text]) {
            UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Ooooopss!" message:@"Passwords don't match" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
            [alert show];
            return false;
        }
        else {
            return true;
        }
    } else {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Ooooopss" message:@"The password has to be between 6 to 14" delegate:nil cancelButtonTitle:@"Dismiss" otherButtonTitles:nil, nil];
        [alert show];
        return false;
    }
}

- (void) registerNewUser {
    [_activityLayView startAnimating];
    NSLog(@"registering...");
    PFUser *newUser = [PFUser user];
    newUser.username = _rusernameField.text;
    newUser.email = _remailField.text;
    newUser.password = _rpasswordField.text;
    [newUser setObject:_rfnameField.text forKey:@"firstName"];
    [newUser setObject:_rlnameField.text forKey:@"lastName"];//access customize field
    [newUser setObject:_rphoneNumberField.text forKey:@"phoneNumber"];
    [newUser setObject:_rgenderFirld.text forKey:@"gender"];
    [newUser setObject:_rbloodGroupField.text forKey:@"bloodGroup"];
    [newUser setObject:_rbirthdayField.text forKey:@"birthday"];
    
    [newUser signUpInBackgroundWithBlock:^(BOOL succeeded, NSError *error) {
        if(!error) {
            [_activityLayView stopAnimating];
            _rfnameField.text = @"";
            _rlnameField.text = @"";
            _rphoneNumberField.text = @"";
            _rusernameField.text = @"";
            _rpasswordField.text = @"";
            _rrepasswordField.text = @"";
            _remailField.text = @"";
            _rgenderFirld.text = @"";
            _rbloodGroupField.text = @"";
            _rbirthdayField.text = @"";
            NSLog(@"Registration success!");
            [self performSegueWithIdentifier:@"login" sender:self];
        }
        else {
            [_activityLayView stopAnimating];
            UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Error" message:[error userInfo][@"error"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
            [alert show];
            NSLog(@"There was an error in registration");
        }
    }];
}
@end