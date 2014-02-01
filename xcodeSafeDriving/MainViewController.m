//
//  MainViewController.m
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "MainViewController.h"
#import <Parse/Parse.h>

@interface MainViewController ()
{
    NSMutableArray *titleArray;
    NSMutableArray *detialArray;
    NSString *smsBlock;
    NSString *drunkDriving;
    NSString *speedTrack;
    NSString *emergencyNotification;
}
@end

@implementation MainViewController
- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    _functionalitiesTableView.delegate = self;
    _functionalitiesTableView.dataSource = self;
    
    titleArray = [[NSMutableArray alloc] initWithObjects:@"Sms Block",@"Drunk Driving", @"Speed Track", @"Emergency Notification", nil];
    }

-(void)viewWillAppear:(BOOL)animated{
    PFUser *currentuser = [PFUser currentUser];
    [currentuser refresh];
    if (currentuser) {
        _welcomeMessage.text = [NSString stringWithFormat:@"Welcome %@ %@", [currentuser objectForKey:@"firstName"], [currentuser objectForKey:@"lastName"]];
        //bool *temp = [[currentuser objectForKey:@"smsBlock"]];
        smsBlock = [[currentuser objectForKey:@"smsBlock"]boolValue] == YES? @"ON" : @"OFF";
        drunkDriving = [[currentuser objectForKey:@"drunkDriving"]boolValue] == YES ? @"ON" : @"OFF";
        speedTrack = [[currentuser objectForKey:@"speedTrack"]boolValue] == YES ? @"ON" : @"OFF";
        emergencyNotification = [[currentuser objectForKey:@"emergencyNotification"]boolValue] == YES ? @"ON" : @"OFF";
    }
    
    detialArray = [[NSMutableArray alloc]initWithObjects:smsBlock, drunkDriving, speedTrack, emergencyNotification, nil];
    [_functionalitiesTableView reloadData];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [titleArray count];
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    static NSString *cellIdentifier = @"Cell";
    UITableViewCell *cell = [_functionalitiesTableView dequeueReusableCellWithIdentifier:cellIdentifier forIndexPath:indexPath];
    cell.textLabel.text = [titleArray objectAtIndex:indexPath.row];
    cell.detailTextLabel.text = [detialArray objectAtIndex:indexPath.row];
    
    return cell;
}
@end
