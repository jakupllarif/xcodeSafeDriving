//
//  RegisterViewController.m
//  xcodeSafeDriving
//
//  Created by Flodjana Jakupllari on 2/2/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "RegisterViewController.h"
#import <Parse/Parse.h>

@interface RegisterViewController ()

@end

@implementation RegisterViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
    if ([_rfnameField.text isEqualToString:@""] || [_rlnameField.text isEqualToString:@""] || [_rphoneNumberField.text isEqualToString:@""] || [_rusernameField.text isEqualToString:@""] || [_rpasswordField.text isEqualToString:@""] || [_rrepasswordField.text isEqualToString:@""] || [_remailField.text isEqualToString:@""] || [_rgenderField.text isEqualToString:@""] || [_rbloodGroupField.text isEqualToString:@""] || [_rbirthdayField.text isEqualToString:@""]) {
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
    [_ractivityLayView startAnimating];
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
    newUser[@"smsBlock"] = @YES;
    newUser[@"emergencyNotification"] = @YES;
    newUser[@"speedTrack"] = @YES;
    newUser[@"drunkDriving"] = @YES;
    
    [newUser signUpInBackgroundWithBlock:^(BOOL succeeded, NSError *error) {
        if(!error) {
            [_ractivityLayView stopAnimating];
            _rfnameField.text = @"";
            _rlnameField.text = @"";
            _rphoneNumberField.text = @"";
            _rusernameField.text = @"";
            _rpasswordField.text = @"";
            _rrepasswordField.text = @"";
            _remailField.text = @"";
            _rgenderField.text = @"";
            _rbloodGroupField.text = @"";
            _rbirthdayField.text = @"";
            NSLog(@"Registration success!");
            [self performSegueWithIdentifier:@"login" sender:self];
        }
        else {
            [_ractivityLayView stopAnimating];
            UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Error" message:[error userInfo][@"error"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
            [alert show];
            NSLog(@"There was an error in registration");
        }
    }];
}

/*#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
#warning Incomplete method implementation.
    // Return the number of rows in the section.
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];
    
    // Configure the cell...
    
    return cell;
}
 */

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    }   
    else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

/*
#pragma mark - Navigation

// In a story board-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}

 */

@end
