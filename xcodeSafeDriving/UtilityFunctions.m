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

+(void)speedTrack:(double)currentSpeed :(double)speedLimit :(AVAudioPlayer*)audio{
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Overspeeding" message:@"Slow down for your safety." delegate:self cancelButtonTitle:@"OK" otherButtonTitles: nil];
    alert.tag = 101;
    
    if (currentSpeed > 0 && speedAlert == false) {
        [alert show];
        speedAlert = true;
        audio.volume = 0.9;
        [audio play];
    } else if (currentSpeed <= speedLimit && speedAlert == true) {
        speedAlert = false;
        [audio stop];
        //[audio release];
    }
}

+(void)smsBlocking:(double)currentSpeed {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"You cannot use the phone while driving!" message:@"Please stop the car to use your phone!" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
    alert.tag = 102;
    if (currentSpeed > 0 && smsAlert == false) {
        [alert show];
        smsAlert = true;
    } else if (currentSpeed <= 0 && smsAlert == true) {
        smsAlert = false;
    }
}

+(void)drunkDriving {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Driving after drunk is dangerous!" message:@"Please don't drive after drunk!" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alert show];
}

+(void)emergencyNotification: (NSString *)currentLocation {
    /*[PFCloud callFunctionInBackground:@"emergencyEmail"
                       withParameters:@{@"Location": currentLocation}//so far I know location is one of the parameters, later on I will add all necessary parameters
                                block:^(id object, NSError *error) {
                                    if (!error) {
                                        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Successed!" message:@"Emergency Email has been sent!" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
                                        [alert show];
                                    }
                                    else {
                                        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Error" message:@"Emergency Email cannot be sent!" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
                                        [alert show];
                                    }
                                }];*/
    
    [PFCloud callFunctionInBackground:@"hello"
                       withParameters:@{}
                                block:^(NSString *result, NSError *error) {
                                    if (!error) {
                                        // result is @"Hello world!"
                                    }
                                }];
    
    
    [PFCloud callFunctionInBackground:@"sendMail"
                       withParameters:@{
                                        @"toEmail":@"liuz@mail.sacredheart.edu",
                                        @"toName":@"Zhenxing Liu",
                                        @"fromEmail":@"jakupllarif@mail.sacredheart.com",
                                        @"fromName":@"Flodjana Jakupllari",
                                        @"text":@"Emergency situation on location:.... Airbag has exploded!",
                                        @"subject":@"Emergency Notification"
                                        }
                                block:^(NSString *result, NSError *error) {
                                    if (!error) {
                                        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Reset Passoword" message:@"Email Sent :-)"
                                            delegate:self cancelButtonTitle:@"OK" otherButtonTitles: nil];
                                        [alert show];
                                    }
                                }];
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
