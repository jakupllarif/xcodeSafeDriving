//
//  UtilityFunctions.m
//  xcodeSafeDriving
//
//  Created by Gabriel Liu on 2/5/14.
//  Copyright (c) 2014 Jakupllari F. & Liu Z. All rights reserved.
//

#import "UtilityFunctions.h"

static bool speedAlert = false;
static bool smsAlert = false;

@implementation UtilityFunctions

+(void)speedTrack:(double)currentSpeed :(double)speedLimit{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Overspeeding" message:@"Slow down for your safety." delegate:self cancelButtonTitle:@"OK" otherButtonTitles: nil];
    alert.tag = 101;
    if (currentSpeed > speedLimit && speedAlert == false) {
        [alert show];
        speedAlert = true;
    } else if (currentSpeed <= speedLimit && speedAlert == true) {
        speedAlert = false;
    }
}

+(void)smsBlocking:(double)currengSpeed {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"You cannot use the phone while driving!" message:@"Please stop the car to use your phone!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
    alert.tag = 102;
    if (currengSpeed > 0 && smsAlert == false) {
        [alert show];
        smsAlert = true;
    } else if (currengSpeed <= 0 && smsAlert == true) {
        smsAlert = false;
    }
}

+(void)drunkDriving {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Driving after drunk is dangerous!" message:@"Please don't drive after drunk!" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alert show];
}

+(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    if (alertView.tag == 101) {
        if (buttonIndex == [alertView cancelButtonIndex]) {
            speedAlert = false;
        }
    }else if (alertView.tag == 102) {
        if (buttonIndex == [alertView cancelButtonIndex]) {
            smsAlert = false;
        }
    }
}
@end
