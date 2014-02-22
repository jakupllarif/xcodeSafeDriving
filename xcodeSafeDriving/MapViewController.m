//
//  MapViewController.m
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "MapViewController.h"

@implementation MapViewController

-(void)viewDidLoad {
    [super viewDidLoad];
    
    //show user's current location
    _map.showsUserLocation = YES;
    
    _map.delegate = self;
    
}

- (void)map:(MKMapView *)map didUpdateUserLocation:(MKUserLocation *)userLocation{
    _map.centerCoordinate =
    userLocation.location.coordinate;
}

- (IBAction)mapSegmentedControl:(id)sender {
    switch (_segmentedControl.selectedSegmentIndex) {
        case 0:
            _map.mapType = MKMapTypeStandard;
            break;
        case 1:
            _map.mapType = MKMapTypeSatellite;
            break;
        case 2:
            _map.mapType = MKMapTypeHybrid;
            break;
        default:
            break;
    }
}
@end
