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
    _map.showsUserLocation = true;
    
    //tack user's location and update the map
   // trackLocation ();
    //change the view of map according to the segment selected
    //changeMapView ();
}


//track user's location and update the map showing the location closer
/*- (void) trackLocation
{
        if (_map.userLocation != null) {
            CLLocationCoordinate2D coords = _map.userLocation.coordinate;
            MKCoordinateSpan span = MKCoordinateSpan(MilesToLatitudeDegrees (2), MilesToLongitudeDegrees (2, coords.latitude));
            _map.Region = MKCoordinateRegion(coords, span);
        }
        _message = String.Format("{0:f2}", _map.userLocation.location.speed < 0 ? 0 : (_map.userLocation.location.speed* 2.23694));
        //this.NavigationItem.Title = _message + " MPH";
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
