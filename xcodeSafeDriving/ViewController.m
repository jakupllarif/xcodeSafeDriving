//
//  ViewController.m
//  xcodeSafeDriving
//
//  Created by Flodjana Jakupllari on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "ViewController.h"

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
    if (user.username != nil) {
        [self performSegueWithIdentifier:@"login" sender:self];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//dismiss keyboard when user touch anyother place outside textfield
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}

- (IBAction)loginBtn:(id)sender {
}

- (IBAction)registerBtn:(id)sender {
    [UIView animateWithDuration:0.3 animations:^{
        _registerLayout.frame = self.view.frame;
    }];
}

- (IBAction)Register:(id)sender {
    [_rfnameField resignFirstResponder];
    [_rlnameField resignFirstResponder];
    [_rphoneNumberField resignFirstResponder];
    [_rusernameField resignFirstResponder];
    [_rpasswordField resignFirstResponder];
    [_rrepasswordField resignFirstResponder];
    [_remailField resignFirstResponder];
    [_rgenderField resignFirstResponder];
    [_rbloodGroupField resignFirstResponder];
    [_rbirthdayField resignFirstResponder];
    [self checkFieldComplete];
}

- (void) checkFieldComplete {
    if ([_rfnameField.text isEqualToString:@""] || [_rlnameField.text isEqualToString:@""] || [_rphoneNumberField.text isEqualToString:@""] || [_rusernameField.text isEqualToString:@""] || [_rpasswordField.text isEqualToString:@""] || [_rrepasswordField.text isEqualToString:@""] || [_remailField.text isEqualToString:@""] || [_rgenderField.text isEqualToString:@""] || [_rbloodGroupField.text isEqualToString:@""] || [_rbirthdayField.text isEqualToString:@""]) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Ooooopss!" message:@"You need to complete all fields" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        [alert show];
    }else {
        [self checkPasswordsMatch];
    }
}

- (void) checkPasswordsMatch {
    if (![_rpasswordField.text isEqualToString:_rrepasswordField.text]) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Ooooopss!" message:@"Passwords don't match" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        [alert show];
    }
    else {
        [self registerNewUser];
    }
}

- (void) registerNewUser {
    //[_activityLayView startAnimating];
    NSLog(@"registering...");
    PFUser *newUser = [PFUser user];
    newUser.username = _rusernameField.text;
    newUser.email = _remailField.text;
    newUser.password = _rpasswordField.text;
    [newUser setObject:_rfnameField.text forKey:@"firstName"];
    [newUser setObject:_rlnameField.text forKey:@"lastName"];//access customize field
    [newUser setObject:_rphoneNumberField.text forKey:@"phoneNumber"];
    [newUser setObject:_rgenderField.text forKey:@"gender"];
    [newUser setObject:_rbloodGroupField.text forKey:@"bloodGroup"];
    [newUser setObject:_rbirthdayField.text forKey:@"birthday"];
    
    [newUser signUpInBackgroundWithBlock:^(BOOL succeeded, NSError *error) {
        if(!error) {
            //[_activityLayView stopAnimating];
            NSLog(@"Registration success!");
            [self performSegueWithIdentifier:@"login" sender:self];
        }
        else {
            NSLog(@"There was an error in registration");
        }
    }];
    
}
@end
