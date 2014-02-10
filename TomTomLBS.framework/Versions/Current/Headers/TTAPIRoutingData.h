//
//  @(#)TTAPIRoutingData.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTSDKUtils.h"
#import "TTAPIBaseData.h"

@class TTBBox;

/**
 * Represent a Route Summary.
 */
@interface TTAPIRouteSummaryOverview : NSObject {
@private
	NSString* day;
	NSString* time;
	NSString* message;
}
/** The day. */
@property (nonatomic, retain) NSString* day;
/** The time. */
@property (nonatomic, retain) NSString* time;
/** The message. */
@property (nonatomic, retain) NSString* message;

@end

/**
 * Represent a Route Summary.
 */
@interface TTAPIRouteSummary : NSObject {
@private
	NSString* routeKey;
	NSString* iqType;
	TTBBox* bbox;
	NSNumber* trafficModelId;
	NSString* startTimeZone;
	NSString* endTimeZone;
	NSInteger deltaTimeZone;
	NSInteger totalDelaySeconds;
	NSInteger totalDistanceMeters;
	NSInteger totalTimeSeconds;
	TTAPIRouteSummaryOverview* departureOverview;
	TTAPIRouteSummaryOverview* arrivalOverview;
}

/** The route key. */
@property (nonatomic, retain) NSString *routeKey;
/** The iq type of the search. */
@property (nonatomic, retain) NSString *iqType;
/** The bouding box. */
@property (nonatomic, retain) TTBBox* bbox;
/** The traffic model id used in the route's calculation. */
@property (nonatomic, retain) NSNumber* trafficModelId;
/** The start location timezone. */
@property (nonatomic, retain) NSString *startTimeZone;
/** The end location timezone. */
@property (nonatomic, retain) NSString *endTimeZone;

/** The variation between the start and end timezones. */
@property (nonatomic, assign) NSInteger deltaTimeZone;
/** The delay in seconds. */
@property (nonatomic, assign) NSInteger totalDelaySeconds;
/** The total route distance in meters. */
@property (nonatomic, assign) NSInteger totalDistanceMeters;
/** The time the route will take to be completed in seconds. */
@property (nonatomic, assign) NSInteger totalTimeSeconds;
/** The departure overview with date, time and message. */
@property (nonatomic, retain) TTAPIRouteSummaryOverview* departureOverview;
/** The arrival overview with date, time and message. */
@property (nonatomic, retain) TTAPIRouteSummaryOverview* arrivalOverview;

@end

/**
 * Represents an intruction from a route's instruction set.
 */
@interface TTAPIRouteInstruction : NSObject {
	
@private
	BOOL isDepartureAction;
	BOOL isDestination;
	BOOL isDestinationAction;
	BOOL isOneWayBack;
	NSInteger distanceMeters;
	NSString* iconPath;
	TTBBox* bbox;
	TTCoordinates* point;
	NSString* roadName;
	NSString* roadNumber;
	NSString* text;
	NSString* transportMode;
	NSInteger travelTimeSeconds;
	NSMutableArray* instructionShape;
}

/** Indicates if an instruction is the departure action. */
@property (nonatomic, assign) BOOL isDepartureAction;
/** Indicates if an instruction is the destination of the route. */
@property (nonatomic, assign) BOOL isDestination;
/** Indicates if an instruction is the destination action. */
@property (nonatomic, assign) BOOL isDestinationAction;
/** The indicates if the instruction is one way. */
@property (nonatomic, assign) BOOL isOneWayBack;
/** The distance in meter between the instruction location and the start location of the route. */
@property (nonatomic, assign) NSInteger distanceMeters;
/** The icon to be used to represent the instruction (turn left, turn right...). */
@property (nonatomic, retain) NSString* iconPath;
/** The bounding box of the instruction, representing its area of effect. */
@property (nonatomic, retain) TTBBox* bbox;
/** The coordinates indication the location where the instruction should be followed. */
@property (nonatomic, retain) TTCoordinates* point;
/** The name of the road where the instruction is valid. */
@property (nonatomic, retain) NSString* roadName;
/** The number of the road where the instruction is valid. */
@property (nonatomic, retain) NSString* roadNumber;
/** The text of the instruction. */
@property (nonatomic, retain) NSString* text;
/** The transport mode used in the instruction. */
@property (nonatomic, retain) NSString* transportMode;
/** The travel time in seconds between this instruction and the previous. */
@property (nonatomic, assign) NSInteger travelTimeSeconds;

/**
 * Creates a new instance.
 * @return The new instance.
 */
- (id) init;


/**
 * Adds an intruction shape point to the set.
 * Adds an intruction shape point to the set of the response object. This is an optional parameter.
 * @param aPoint The point to add.
 */
- (void) addInstructionShapePoint:(TTCoordinates*) aPoint;
/**
 * Returns all the instruction shape points
 * Returns an array of TTCoordinates objects.
 * @return An array of TTCoordinates objects.
 */
- (NSArray*) getInstructionShapePoints;

@end


/**
 * Represents a routing response.
 * This contains the data sent by the LBS server for a routing request.
 */
@interface TTAPIRoutingData : TTAPIBaseData {
	
@private
	NSString *version;
	NSMutableArray *instructions;
    NSMutableArray *pathData;
	TTAPIRouteSummary* summary;
}

/** The route version. */
@property (nonatomic, retain) NSString *version;
/** The number of instructions. */
@property (nonatomic, readonly) NSInteger count;
/** The route's summary. */
@property (nonatomic, retain) TTAPIRouteSummary* summary;


/**
 * Creates a new instance.
 */
- (id) init;

/**
 * Adds a route instruction.
 * Adds a route instruction to the response object. A query might return several instruction entries.
 * @param instruction The instruction to add.
 */
- (void) addInstruction:(TTAPIRouteInstruction *)instruction;

/**
 * Adds a path data point
 * the value pair comes from the response object in the projection coordinates requested
 * @param coord The Coordinate in Mercator Projection OR WGS
 */
- (void) addPathPoint:(TTCoordinates *)coord;

/**
 * Returns all the route instructions.
 * Returns an array of TTAPIRouteInstruction objects.
 * @return An array of TTAPIRouteInstruction objects.
 */
- (NSArray *) getInstructions;

/**
 * Returns all the path data
 * @return An array of TTCoordinates objects
 */
- (NSArray *) getPathData;

@end
