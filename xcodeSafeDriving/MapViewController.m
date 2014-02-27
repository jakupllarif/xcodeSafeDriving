//
//  MapViewController.m
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "MapViewController.h"

@implementation MapViewController
@synthesize map = _map;

double const METERS_PER_MILE = 1609.344;

-(void)viewDidLoad {
    [super viewDidLoad];
    [self.map.delegate self];
    [self.map setShowsUserLocation: YES];

}

- (void)mapView:(MKMapView *)map didUpdateUserLocation:(MKUserLocation *)userLocation{
    CLLocationCoordinate2D loc = [userLocation coordinate];
    MKCoordinateRegion region = MKCoordinateRegionMakeWithDistance(loc, 500, 500);
    [self.map setRegion:region animated:YES];
    //_map.centerCoordinate = userLocation.location.coordinate;
}

-(void) viewDidUnload{
    [self setMap:nil];
    [super viewDidUnload];
}

/*-(void)mapView:(MKMapView *)mapView regionDidChangeAnimated:(BOOL)animated {
    MKCoordinateRegion mapRegion;
    mapRegion.center = _map.userLocation.coordinate;
    mapRegion.span.latitudeDelta = 0.1;
    mapRegion.span.longitudeDelta = 0.1;
    
    [_map setRegion:mapRegion animated: YES];
}*/

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
