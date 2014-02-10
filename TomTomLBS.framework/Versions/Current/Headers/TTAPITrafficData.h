//
//  @(#)TTAPITrafficData.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTSDKUtils.h"
#import "TTAPIBaseData.h"


/**
 * Represents the traffic incident type.
 */
typedef enum {
	TTAPITrafficIconServerCategoryUnknown =  0,
	TTAPITrafficIconServerCategoryAccident =  1,
	TTAPITrafficIconServerCategoryFog=  2,
	TTAPITrafficIconServerCategoryDangerousConditions =  3,
	TTAPITrafficIconServerCategoryRain =  4,
	TTAPITrafficIconServerCategoryIce =  5,
	TTAPITrafficIconServerCategoryJam =  6,
	TTAPITrafficIconServerCategoryLaneClosed =  7,
	TTAPITrafficIconServerCategoryRoadClosure =  8,
	TTAPITrafficIconServerCategoryRoadWork =  9,
	TTAPITrafficIconServerCategoryWind = 10,
	TTAPITrafficIconServerCategorySlipRoadClosed = 11,
	TTAPITrafficIconServerCategoryDetour = 12
} TTAPITrafficIconCategory;

#pragma mark -
#pragma mark TTAPITrafficShape

/**
 * Represent a Traffic Shape.
 */
@interface TTAPITrafficShape : NSObject {

@private
    NSInteger width;
    NSString* shapePoints;
}

/**
 * Traffic shape width.
 */
@property NSInteger width;
/**
 * Traffic shape's poinsts list. 
 * - List of points separated by ';'. Each point is in the format 'x,y' where x and y are pixel
 * coordinates referring to the zoom level used to get the traffic data.
 */
@property (nonatomic, retain) NSString* shapePoints;

@end
    
    
#pragma mark -
#pragma mark TTAPITrafficPoi

/**
 * Represent a Traffic Point of Interest.
 */
@interface TTAPITrafficPoi : NSObject {

@private
    TTCoordinates* poiPosition;
    TTAPITrafficIconCategory iconCategory;
    NSInteger trafficType;
    TTCoordinates* clusterBottomLeftPosition;
    TTCoordinates* clusterTopRightPosition;
    NSInteger clusterSize;
    NSMutableArray *clusterPois;

    TTAPITrafficShape* trafficShape;

    NSString* incidentDescription;
    NSString* incidentCause;
    NSString* incidentFromName;
    NSString* incidentToName;
    
    NSInteger incidentLength;
    NSInteger incidentDelay;
    
    NSString* incidentRoadNumber;
    NSString* incidentCountryCode;
}
/**
 * Poi position in pixels relative to the zoom level used.
 */
@property (nonatomic, retain) TTCoordinates* poiPosition;
//TODO what is this?
/**
 * Icon category. 
 */
@property TTAPITrafficIconCategory iconCategory;
//TODO what is this?
/**
 * Traffic type. 
 */
@property NSInteger trafficType;
//TODO what is this?
/**
 * Cluster bottom left position. 
 */
@property (nonatomic, retain) TTCoordinates* clusterBottomLeftPosition;
//TODO what is this?
/**
 * Cluster top right position. 
 */
@property (nonatomic, retain) TTCoordinates* clusterTopRightPosition;
//TODO what is this?
/**
 * Cluster size. 
 */
@property NSInteger clusterSize;

/**
 * Incident inside the current cluster. 
 */
@property (nonatomic, retain) NSMutableArray *clusterPois;

/**
 * The Traffic Shape.
 */
@property (nonatomic, retain) TTAPITrafficShape* trafficShape;
/**
 * The incident's description.
 */
@property (nonatomic, retain) NSString* incidentDescription;
/**
 * The incident's cause.
 */
@property (nonatomic, retain) NSString* incidentCause;
/**
 * The incident's initial location name.
 */
@property (nonatomic, retain) NSString* incidentFromName;
/**
 * The incident's end location name.
 */
@property (nonatomic, retain) NSString* incidentToName;
//TODO in which measure?
/**
 * The incident's legth. 
 */
@property NSInteger incidentLength;
//TODO in which measure?
/**
 * The incident's delay. 
 */
@property NSInteger incidentDelay;
/**
 * The incident's road number.
 */
@property (nonatomic, retain) NSString* incidentRoadNumber;
/**
 * The incident's country code.
 */
@property (nonatomic, retain) NSString* incidentCountryCode;

@end

    
#pragma mark -
#pragma mark TTAPITrafficData


/**
 * Represents a response from the traffic service.
 */
@interface TTAPITrafficData : TTAPIBaseData {

@private
    NSString* trafficId;
    NSMutableArray* poiList;
}

/**
 * The ID of the traffic model.
 */
@property (nonatomic, retain) NSString* trafficId;

/**
 * Adds a traffic POI.
 * Adds a traffic POI to the list.
 * @param poi The POI to add.
 */
- (void) addTrafficPoi:(TTAPITrafficPoi*)poi;

/**
 * Returns all the traffic pois.
 * Returns an array of TTTrafficPoi objects.
 * @return An array of TTTrafficPoi objects.
 */
- (NSArray*) getTrafficPois;

/** 
 * An alias for the property NSString* trafficId.
 * @return the traffic model ID
 */
- (NSString*) getTrafficModelId;
@end
