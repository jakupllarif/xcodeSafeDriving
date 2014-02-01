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

@end

@implementation MainViewController
- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidAppear:(BOOL)animated{
    PFUser *currentuser = [PFUser currentUser];
    if (currentuser) {
        //NSString *firstName = [currentuser objectForKey:@"firstName"];
        NSString *welcomeMessage = [NSString stringWithFormat:@"Welcome %@ %@", [currentuser objectForKey:@"firstName"], [currentuser objectForKey:@"lastName"]];
        _welcomeMessage.text = welcomeMessage;
       // _welcomeMessage.text = [NSString stringWithFormat:@"Welcome %@ %@", [currentuser objectForKey:@"firstName"], [currentuser objectForKey:@"lastName"]];
    }
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
@end
