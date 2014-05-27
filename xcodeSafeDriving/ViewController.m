//
//  ViewController.m
//  xcodeSafeDriving
//
//  Created by Flodjana Jakupllari on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "ViewController.h"
#import <Parse/Parse.h>
#import <CommonCrypto/CommonDigest.h>

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
    //NSLog([self sha1:@"password1234"]);
    [PFUser logInWithUsernameInBackground:_usernameField.text password:[self sha1:_passwordField.text] block:^(PFUser *user, NSError *error) {
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

//hashing the password for security

-(NSString*) sha1:(NSString*)input
{
    const char *cstr = [input cStringUsingEncoding:NSUTF8StringEncoding];
    NSData *data = [NSData dataWithBytes:cstr length:input.length];
    
    uint8_t digest[CC_SHA1_DIGEST_LENGTH];
    
    CC_SHA1(data.bytes, data.length, digest);
    
    NSMutableString* output = [NSMutableString stringWithCapacity:CC_SHA1_DIGEST_LENGTH * 2];
    
    for(int i = 0; i < CC_SHA1_DIGEST_LENGTH; i++)
        [output appendFormat:@"%02x", digest[i]];
    
    return output;
    
}

@end