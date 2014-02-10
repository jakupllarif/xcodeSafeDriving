//
//  TTSDKLogRecord.h
//  MobileSDK
//
//  Created by JJ Rojas on 1/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TTSDKLogRecord : NSObject {
    double timestamp;
    NSString *description;
    NSString *appid;
    int recordType;
    NSString *device;
    NSString *network;
    double value;
    NSString *udid;
}
@property double timestamp;
@property (nonatomic, retain) NSString *description;
@property (nonatomic, retain) NSString *appid;
@property int recordType;
@property (nonatomic, retain) NSString *device;
@property (nonatomic, retain) NSString *network;
@property double value;
@property (nonatomic, retain) NSString *udid;

@end
