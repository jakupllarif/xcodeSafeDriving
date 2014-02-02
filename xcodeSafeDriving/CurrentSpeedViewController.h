//
//  CurrentSpeedViewController.h
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@interface CurrentSpeedViewController : UIViewController <CLLocationManagerDelegate>

@property (weak, nonatomic) IBOutlet UILabel *currentSpeedLabel;
@property (weak, nonatomic) IBOutlet UILabel *addressLabel;

@end
