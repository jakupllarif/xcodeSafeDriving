//
//  UtilityFunctions.h
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 2/5/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface UtilityFunctions : NSObject<UIAlertViewDelegate>

+ (void)speedTrack:(double) currentSpeed :(double)speedLimit :(AVAudioPlayer*)audio;
+ (void)smsBlocking:(double) currentSpeed;
+ (void)drunkDriving;
+ (void)emergencyNotification;
@end
