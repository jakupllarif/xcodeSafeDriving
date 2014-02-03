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

@synthesize birthDate;

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
    
    //_rbirthdayField.delegate = self;
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

//hide keyboard when scroll
//-(void)scrollViewWillBeginDragging:(UIScrollView *)scrollView {
//    [_rfnameField resignFirstResponder];
//    [_rlnameField resignFirstResponder];
//    [_rgenderField resignFirstResponder];
//    [_rbloodGroupField resignFirstResponder];
//    [_rphoneNumberField resignFirstResponder];
//    [_rusernameField resignFirstResponder];
//    [_rpasswordField resignFirstResponder];
//    [_rrepasswordField resignFirstResponder];
//    [_remailField resignFirstResponder];
//}

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
            [self performSegueWithIdentifier:@"registing" sender:self];
        }
        else {
            [_ractivityLayView stopAnimating];
            UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Error" message:[error userInfo][@"error"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
            [alert show];
            NSLog(@"There was an error in registration");
        }
    }];
}

- (void)setBirth {
    
    dateSheet = [[UIActionSheet alloc] initWithTitle:nil delegate:nil cancelButtonTitle:nil destructiveButtonTitle:nil otherButtonTitles:nil];
    
    [dateSheet setActionSheetStyle:UIActionSheetStyleDefault];
    CGRect pickerFrame = CGRectMake(0, 44, 0, 0);
    UIDatePicker *birthDayPicker = [[UIDatePicker alloc] initWithFrame:pickerFrame];
    [birthDayPicker setDatePickerMode:UIDatePickerModeDate];
    [dateSheet addSubview:birthDayPicker];
    
    UIToolbar *controlToolBar = [[UIToolbar alloc] initWithFrame:CGRectMake(0, 0, dateSheet.bounds.size.width, 44)];
    [controlToolBar setBarStyle:UIBarStyleDefault];
    [controlToolBar sizeToFit];
    
    UIBarButtonItem *spacer = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil];
    UIBarButtonItem *setButton = [[UIBarButtonItem alloc] initWithTitle:@"Set" style:UIBarButtonItemStyleDone target:self action:@selector(dismissDateSet)];
    UIBarButtonItem *cancelButton = [[UIBarButtonItem alloc] initWithTitle:@"Cancel" style:UIBarButtonItemStyleBordered target:self action:@selector(cancelDateSet)];
    [controlToolBar setItems:[NSArray arrayWithObjects:spacer, cancelButton, setButton, nil] animated:NO];
    
    [dateSheet addSubview:controlToolBar];
    [dateSheet showInView:self.view];
    [dateSheet setBounds:CGRectMake(0, 0, 320, 485)];
}

-(void)cancelDateSet {
    [dateSheet dismissWithClickedButtonIndex:0 animated:YES];
}

-(void)dismissDateSet {
    NSArray *listOfViews = [dateSheet subviews];
    for (UIView *subView in listOfViews) {
        if ([subView isKindOfClass:[UIDatePicker class]]) {
            self.birthDate = [(UIDatePicker *)subView date];
        }
    }
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"MM/dd/yyyy"];
    
    //if user put date that has not happened yet, show error
    NSCalendar *calender = [NSCalendar currentCalendar];
    unsigned unitFlags = NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit;
    NSDateComponents *calcBirthday = [calender components:unitFlags fromDate:self.birthDate toDate:[NSDate date] options:0];
    int months = [calcBirthday month];
    int days = [calcBirthday day];
    int years = [calcBirthday year];
    if (years < 0 || days < 0 || months < 0) {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:@"Not Born Yet!" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles: nil];
        [alert show];
    } else
        [_rbirthdayField setText:[dateFormatter stringFromDate:self.birthDate]];
    [dateSheet dismissWithClickedButtonIndex:0 animated:YES];
}

-(void)setGender {
    UIActionSheet *genderSet = [[UIActionSheet alloc] initWithTitle:nil delegate:self cancelButtonTitle:nil destructiveButtonTitle:nil otherButtonTitles:@"Male", @"Female", nil];
    [genderSet setTag:0];
    [genderSet showInView:self.view];
}

-(void)setBloodGroup {
    UIActionSheet *bloodGroupSet = [[UIActionSheet alloc] initWithTitle:nil delegate:self cancelButtonTitle:nil destructiveButtonTitle:nil otherButtonTitles:@"A", @"B", @"O", @"AB", nil];
    [bloodGroupSet setTag:1];
    [bloodGroupSet showInView:self.view];
}

-(void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex {
    switch (actionSheet.tag) {
        case 0:
        {
            if (buttonIndex == 0)
                [_rgenderField setText:@"Male"];
            else if (buttonIndex == 1)
                [_rgenderField setText:@"Femal"];
        }
            break;
            
        case 1:
        {
            if (buttonIndex == 0)
                [_rbloodGroupField setText:@"A"];
            else if (buttonIndex == 1)
                [_rbloodGroupField setText:@"B"];
            else if (buttonIndex == 2)
                [_rbloodGroupField setText:@"O"];
            else if (buttonIndex == 3)
                [_rbloodGroupField setText:@"AB"];
        }
            break;
        default:
            break;
    }
    
}

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField {
    if (textField.tag == 1) {
        [self setGender];
        return NO;
    }
    else if (textField.tag == 2) {
        [self setBirth];
        return NO;
    }
    else if (textField.tag == 3) {
        [self setBloodGroup];
        return NO;
    } else
        return YES;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    if (textField.tag == 4)
        [textField resignFirstResponder];
    return NO;
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
