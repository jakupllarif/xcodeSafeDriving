//
//  MapViewController.h
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

@interface MapViewController : UIViewController<MKMapViewDelegate>

@property (weak, nonatomic) IBOutlet MKMapView *map;
- (IBAction)mapSegmentedControl:(id)sender;
@property (weak, nonatomic) IBOutlet UISegmentedControl *segmentedControl;

@end
