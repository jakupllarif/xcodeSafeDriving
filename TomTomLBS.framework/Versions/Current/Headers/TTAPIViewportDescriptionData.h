//
//  @(#)TTAPIViewportDescription.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIBaseData.h"


/**
 * Represents a response from the ViewPort Description service.
 */
@interface TTAPIViewportDescriptionData : TTAPIBaseData {

@private
    NSString* version;
    BOOL canZoomIn;
    NSNumber* tilesVersion;
    NSNumber* trafficAge;
    NSString* trafficModelId;
    NSString* copyrightIds;
}

/**
 * The version.
 */
@property (nonatomic, retain) NSString* version;
/**
 * If can zoom.
 */
@property BOOL canZoomIn;
/**
 * The version of the tiles.
 * Initialize with [NSNumber numberWithLongLong:(long long) x].
 */
@property (nonatomic, retain) NSNumber* tilesVersion;
/**
 * The traffic age.
 * Initialize with [NSNumber numberWithLongLong:(long long) x].
 */
@property (nonatomic, retain) NSNumber* trafficAge;
/**
 * The traffic model ID.
 */
@property (nonatomic, retain) NSString* trafficModelId;
/**
 * The set of copyright IDs.
 */
@property (nonatomic, retain) NSString* copyrightIds;

@end
