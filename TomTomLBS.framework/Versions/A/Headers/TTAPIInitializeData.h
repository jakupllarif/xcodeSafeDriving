//
//  @(#)TTAPIInitializeData.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIBaseData.h"


@class TTCoordinates;
@class TTBBox;

/**
 * Represents part of an Initialize service response.
 * Represents a traffic region entry from the list of traffic regions.
 */
@interface TTAPITrafficRegionData : NSObject {
@private
    NSString* areaName;
    TTCoordinates* point;
    NSString* feedType;
    NSInteger fromZoom;
}

/**
 * The area name.
 */
@property (nonatomic, retain) NSString* areaName;
/**
 * The point.
 */
@property (nonatomic, retain) TTCoordinates* point;
/**
 * The feed type.
 */
@property (nonatomic, retain) NSString* feedType;
/**
 * The from zoom field.
 */
@property NSInteger fromZoom;

@end


/**
 * Represents part of an Initialize service response.
 * Represents a copyright entry from the list of copyright results.
 */

@interface TTAPICopyrightData : NSObject {
@private
    NSString* copyrightId;
    NSString* copyrightDescription;
    NSString* copyrightLabel;
    NSString* copyrightLogo;
}

/**
 * The copyright ID.
 */
@property (nonatomic, retain) NSString* copyrightId;
/**
 * The copyright description.
 */
@property (nonatomic, retain) NSString* copyrightDescription;
/**
 * The copyright label.
 */
@property (nonatomic, retain) NSString* copyrightLabel;
/**
 * The copyright logo.
 */
@property (nonatomic, retain) NSString* copyrightLogo;

@end


/**
 * Represents part of an Initialize service response.
 * It represents the map location field.
 */

@interface TTAPIInitializeMapLocation : NSObject {
@private
    TTCoordinates* center;
    NSNumber* width;
    NSNumber* height;
}

@property (nonatomic, retain) TTCoordinates* center;
@property (nonatomic, retain) NSNumber* width;
@property (nonatomic, retain) NSNumber* height;

@end


/**
 * Represents an Initialize service response.
 */
@interface TTAPIInitializeData : TTAPIBaseData {
@private
    NSString* version;
    TTAPIInitializeMapLocation* mapLocation;
	NSMutableArray *trafficRegionResults;
	NSMutableArray *copyrightResults;
}

/**
 * The version.
 */
@property (nonatomic, retain) NSString* version;
/**
 * The map location.
 */
@property (nonatomic, retain) TTAPIInitializeMapLocation* mapLocation;

/**
 * Creates a new instance.
 */
- (id) init;

/**
 * Adds a Traffic Region result.
 * Adds a Traffic Region result to the response object. A query might return one or more Traffic Region result entries.
 * @param trafficRegionResult The result to add.
 */
- (void) addTrafficRegionResult:(TTAPITrafficRegionData *)trafficRegionResult;

/**
 * Returns all the traffic region results.
 * Returns an array of TTAPITrafficRegionData objects.
 * @return An array of TTAPITrafficRegionData objects.
 */
- (NSArray *) getTrafficRegionResults;

/**
 * Adds a Copyright result.
 * Adds a Copyright result to the response object. A query might return one or more Copyright result entries.
 * @param copyrightData The result to add.
 */
- (void) addCopyrightResult:(TTAPICopyrightData *)copyrightData;

/**
 * Returns all the copyright results.
 * Returns an array of TTAPICopyrightData objects.
 * @return An array of TTAPICopyrightData objects.
 */
- (NSArray *) getCopyrightResults;

@end
