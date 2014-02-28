//
//  CurrentSpeedViewController.h
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 1/29/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <AVFoundation/AVFoundation.h>

@interface CurrentSpeedViewController : UIViewController <CLLocationManagerDelegate>

@property (strong, nonatomic) AVAudioPlayer *audio;
@property (weak, nonatomic) IBOutlet UILabel *currentSpeedLabel;
@property (weak, nonatomic) IBOutlet UILabel *addressLabel;
@property (weak, nonatomic) IBOutlet UILabel *speedLimitLabel;
@property (weak, nonatomic) IBOutlet UIProgressView *greenProgressBar;
@property (weak, nonatomic) IBOutlet UIProgressView *yellowProgressBar;
@property (weak, nonatomic) IBOutlet UIProgressView *redProgressBar;
- (IBAction)kmmileSegmentedControl:(id)sender;
@property (weak, nonatomic) IBOutlet UISegmentedControl *kmmileSegControl;

@end
