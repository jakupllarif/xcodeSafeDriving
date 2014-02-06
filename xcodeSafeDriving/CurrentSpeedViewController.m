//
//  CurrentSpeedViewController.m
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "CurrentSpeedViewController.h"
#import "UtilityFunctions.h"
#import <Parse/Parse.h>

@interface CurrentSpeedViewController()
{
    PFUser *currentuser;
}
@end

@implementation CurrentSpeedViewController {
    CLLocationManager *locationManager;
    CLGeocoder *geocoder;
    CLPlacemark *placemark;
    BOOL smsBlock;
    BOOL speedTrack;
    int speedSystem;
}

-(void)viewDidLoad {
    
    [super viewDidLoad];
    _kmmileSegControl.selectedSegmentIndex = 0; //preselect km/h as a speed system
    speedSystem = 3.6; //set the speed system to km/h
    
    currentuser = [PFUser currentUser];
    locationManager = [[CLLocationManager alloc] init];
    geocoder = [[CLGeocoder alloc] init];
    
    locationManager.delegate = self;
    locationManager.desiredAccuracy = kCLLocationAccuracyBest;
    if ([CLLocationManager locationServicesEnabled]) {
        [locationManager startUpdatingLocation];
    }
}

-(void)viewWillAppear:(BOOL)animated {
    [currentuser refresh];
    if (currentuser) {
        smsBlock = [currentuser[@"smsBlock"] boolValue];
        speedTrack = [currentuser[@"speedTrack"] boolValue];
    }
    [locationManager startUpdatingLocation];
}

-(void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error {
    NSLog(@"didFailWithError: %@", error);
    UIAlertView *errorAlert = [[UIAlertView alloc] initWithTitle:@"Ooops!" message:@"We couldn't get your location!" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [errorAlert show];
}

-(void)locationManager:(CLLocationManager *)manager didUpdateToLocation:(CLLocation *)newLocation fromLocation:(CLLocation *)oldLocation {
    NSLog(@"didUpdateToLocation: %@", newLocation);
    CLLocation *currentLocation = newLocation;
    
    if (currentLocation != nil) {
        double speed = currentLocation.speed <= 0.00 ? 0 : currentLocation.speed;
        //calling Utility functions
        if (smsBlock)
            [UtilityFunctions smsBlocking:speed];
        if (speedTrack)
            [UtilityFunctions speedTrack:speed];
        //update the progress bar to change color depending on the speed
        [self updateProgressBar:speed];
        //update the label showing the current speed, in the current system
        _currentSpeedLabel.text = [NSString stringWithFormat:@"%.2f", (speed * speedSystem)];
    }
    
    // Reverse Geocoding
    NSLog(@"Resolving the Address");
    [geocoder reverseGeocodeLocation:currentLocation completionHandler:^(NSArray *placemarks, NSError *error) {
        //NSLog(@"Found placemarks: %@, error: %@", placemarks, error);
        if (error == nil && [placemarks count] > 0) {
            placemark = [placemarks lastObject];
            _addressLabel.text = [NSString stringWithFormat:@"%@ %@\n%@ %@\n%@\n%@", placemark.subThoroughfare, placemark.thoroughfare, placemark.postalCode, placemark.locality, placemark.administrativeArea, placemark.country];
        } else {
            NSLog(@"%@", error.debugDescription);
        }
    } ];
}



//changes the color of the progress bars according to the value of the speed
- (void) updateProgressBar : (double) speedNumber{
    _greenProgressBar.Progress = 0.0f;
    _yellowProgressBar.Progress = 0.0f;
    _redProgressBar.Progress = 0.0f;
    
    //update progress bars according to the current speed
    if (speedNumber <= 30) {
        _greenProgressBar.Progress = (float)speedNumber / 30.0f;
        _currentSpeedLabel.textColor = [UIColor greenColor];
    }
    else if (speedNumber > 30 && speedNumber <= 36) {
        _greenProgressBar.Progress = (float)100 / 10.0f;
        _yellowProgressBar.Progress = (float)(speedNumber-30) / 10.0f;
        _currentSpeedLabel.textColor = [UIColor yellowColor];
    } else {
        _greenProgressBar.Progress = (float)100 / 10.0f;
        _yellowProgressBar.Progress = (float)100 / 10.0f;
        _redProgressBar.Progress = (float)(speedNumber-40) / 20.0f;
        _currentSpeedLabel.textColor = [UIColor redColor];
    }
}

-(void)viewWillDisappear:(BOOL)animated {
    [locationManager stopUpdatingLocation];
}

//change the system of the showing speed: km/h or mile/h
- (IBAction)kmmileSegmentedControl:(id)sender {
    if(_kmmileSegControl.selectedSegmentIndex == 0)
        speedSystem = 3.6; //km system
    else if (_kmmileSegControl.selectedSegmentIndex == 1)
        speedSystem = 2.24; //mile system
}
@end








