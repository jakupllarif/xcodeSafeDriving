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
#import <TomTomLBS/TTLBSSDK.h>

@interface CurrentSpeedViewController()
{
    PFUser *currentuser;
    TTAPIReverseGeocodeData *data;
    TTAPILocation *location;
    TTAPIReverseGeocodeOptionalParameters *paramters;
}
@end

@implementation CurrentSpeedViewController {
    CLLocationManager *locationManager;
    CLGeocoder *geocoder;
    CLPlacemark *placemark;
    BOOL smsBlock;
    BOOL speedTrack;
    int speedSystem;
    double speedLimitSystem;
}

-(void)viewDidLoad {
    
    [super viewDidLoad];
    //apply tomtom geocoding api
    [[TTSDKContext sharedContext] setDeveloperKey:@"axmp4hjyvzqs4a45knk3zqa9"];
    location = [[TTAPILocation alloc ] init ];
    paramters = [[TTAPIReverseGeocodeOptionalParameters alloc]init];
    /* To get speed limit information, you have to call the Reverse Geocoder with one of its more specific types: International, National or Regional. These will give you different information about the nearest cities: Regional will give you small towns, National cities, and International major cities. But for roads, they all return the nearest road to the point you've called. */
    [paramters setType:TTReverseGeocodeTypeRegional];
    //[paramters setType:TTReverseGeocodeTypeNational];
    //[paramters setType:TTReverseGeocodeTypeInternational];
    
    //done init Tom-Tom map
    _kmmileSegControl.selectedSegmentIndex = 0; //preselect km/h as a speed system
    speedSystem = 3.6; //set the speed system to km/h
    speedLimitSystem = 1;
    
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
    data = [location reverseGeocodeWithLatitude:[NSNumber numberWithDouble:currentLocation.coordinate.latitude] andLongitude:[NSNumber numberWithDouble:currentLocation.coordinate.longitude] andOptionalParameters:paramters];
    
    TTAPIReverseGeoResult *result = [[data getReverseGeoResults]objectAtIndex:0];
    
    double speedLimit = result.maxSpeedKph * speedLimitSystem;
    
    _speedLimitLabel.text = [NSString stringWithFormat:@"%.2f", round(speedLimit)];
    
    if (currentLocation != nil) {
        double speed = currentLocation.speed <= 0.00 ? 0 : currentLocation.speed * speedSystem;
        //calling Utility functions
        if (smsBlock)
            [UtilityFunctions smsBlocking:speed];
        if (speedTrack)
            [UtilityFunctions speedTrack:speed :speedLimit];
        //update the progress bar to change color depending on the speed
        [self updateProgressBar:speed];
        //update the label showing the current speed, in the current system
        _currentSpeedLabel.text = [NSString stringWithFormat:@"%.2f", speed];
    }
    
    // Reverse Geocoding
    NSLog(@"Resolving the Address");
    [geocoder reverseGeocodeLocation:currentLocation completionHandler:^(NSArray *placemarks, NSError *error) {
        //NSLog(@"Found placemarks: %@, error: %@", placemarks, error);
        if (error == nil && [placemarks count] > 0) {
            placemark = [placemarks lastObject];
            _addressLabel.text = [NSString stringWithFormat:@"%@ %@\n%@ %@\n%@\n%@", placemark.subThoroughfare == nil ? @"" : placemark.subThoroughfare, placemark.thoroughfare, placemark.postalCode, placemark.locality, placemark.administrativeArea, placemark.country];
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
    if(_kmmileSegControl.selectedSegmentIndex == 0) {
        speedLimitSystem = 1;
        speedSystem = 3.6; //km system
    }
    else if (_kmmileSegControl.selectedSegmentIndex == 1) {
        speedSystem = 2.24; //mile system
        speedLimitSystem = 0.62;
    }
}
@end








