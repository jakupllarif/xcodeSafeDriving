//
//  SettingsViewController.m
//  xcodeSafeDriving
//
//  Created by Flodjana Jakupllari on 2/2/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "SettingsViewController.h"
#import <Parse/Parse.h>

@interface SettingsViewController ()
{
    NSMutableArray *titleArray;
    NSMutableArray *detailArray;
    BOOL smsBlock;
    BOOL drunkDriving;
    BOOL speedTrack;
    BOOL emergencyNotification;
}
@end

@implementation SettingsViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    _settingsTableController.delegate = self;
    _settingsTableController.dataSource = self;
    
    //titleArray = [[NSMutableArray alloc] initWithObjects:@"Sms Block",@"Drunk Driving", @"Speed Track", @"Emergency Notification", nil];
}

-(void)viewWillAppear:(BOOL)animated{
    PFUser *currentuser = [PFUser currentUser];
    [currentuser refresh];
    if (currentuser) {
        smsBlock = [[currentuser objectForKey:@"smsBlock"]boolValue];
        drunkDriving = [[currentuser objectForKey:@"drunkDriving"]boolValue];
        speedTrack = [[currentuser objectForKey:@"speedTrack"]boolValue];
        emergencyNotification = [[currentuser objectForKey:@"emergencyNotification"]boolValue];
    }
    [_messageBlockBtnOutlet setOn:smsBlock];
    [_drunkBtnOutlet setOn:drunkDriving];
    [_overspeedBtnOutlet setOn:speedTrack];
    [_emergencyBtnOutlet setOn:emergencyNotification];
    
    //detailArray = [[NSMutableArray alloc]initWithObjects:smsBlock, drunkDriving, speedTrack, emergencyNotification, nil];
    //[_settingsTableController reloadData];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{    // Return the number of rows in the section.
    return [titleArray count];
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    static NSString *cellIdentifier = @"SCell";
    UITableViewCell *cell = [_settingsTableController dequeueReusableCellWithIdentifier:cellIdentifier forIndexPath:indexPath];
    cell.textLabel.text = [titleArray objectAtIndex:indexPath.row];
    cell.detailTextLabel.text = [detailArray objectAtIndex:indexPath.row];
    
    return cell;
}*/

- (IBAction)logout:(id)sender {
    [PFUser logOut];
    [self.view.window.rootViewController dismissViewControllerAnimated:YES completion:nil];
    //[self dismissViewControllerAnimated:YES completion:nil];
}

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

- (IBAction)logoutBtn:(id)sender {
}
- (IBAction)drunkBtn:(id)sender {
}

- (IBAction)overspeedBtn:(id)sender {
}

- (IBAction)messageBlockBtn:(id)sender {
}

- (IBAction)emergencyBtn:(id)sender {
}
@end
