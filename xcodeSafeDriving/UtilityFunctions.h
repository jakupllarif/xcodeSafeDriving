//
//  UtilityFunctions.h
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 2/5/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UtilityFunctions : NSObject<UIAlertViewDelegate>

+ (void)speedTrack:(double) currentSpeed :(double)speedLimit;
+ (void)smsBlocking:(double) currengSpeed;
+ (void)drunkDriving;
@end
