//
//  MapViewController.m
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "MapViewController.h"

@implementation MapViewController
double const METERS_PER_MILE = 1609.344;
-(void)viewDidLoad {
    [super viewDidLoad];
    
    //show user's current location
    _map.showsUserLocation = YES;
    
    _map.delegate = self;
}

-(void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

}

- (void)map:(MKMapView *)map didUpdateUserLocation:(MKUserLocation *)userLocation{
    _map.centerCoordinate = userLocation.location.coordinate;
}

-(void)mapView:(MKMapView *)mapView regionDidChangeAnimated:(BOOL)animated {
    MKCoordinateRegion mapRegion;
    mapRegion.center = _map.userLocation.coordinate;
    mapRegion.span.latitudeDelta = 0.1;
    mapRegion.span.longitudeDelta = 0.1;
    
    [_map setRegion:mapRegion animated: YES];
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
