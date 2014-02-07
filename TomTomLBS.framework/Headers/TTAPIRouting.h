    //
//  @(#)TTAPIRouting.h 10/05/25
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTSDKUtils.h"
#import "TTAPIRoutingDelegate.h"

@class TTAPIRoutingData;
@class TTAPIRoutingOperation;
@class TTAPIRecalculateRoutingOperation;


#pragma mark -
#pragma mark Utilities


/*
 * Defines the route types the API accepts.
 * See RouteType_toString for a way to convert into NSString*
 */
typedef enum {
	Quickest,
	Shortest,
	AvoidMotorway,
	Walk,
	Bicycle,
	SpeedLimited
} TTRouteType;

/**
 * Convers a RouteType into its String equivalent.
 */
__attribute__((visibility("default")))NSString * const TTRouteType_toString[6];

/**
 * Day type for configuraing the departure date when calculating a route.
 */
typedef enum {
    TTRouteDayType_sunday,
    TTRouteDayType_monday,
    TTRouteDayType_tuesday,
    TTRouteDayType_wednesday,
    TTRouteDayType_thursday,
    TTRouteDayType_friday,
    TTRouteDayType_saturday,
    TTRouteDayType_now,
    TTRouteDayType_today,
    TTRouteDayType_tomorrow,
    TTRouteDayType_noTime
} TTRouteDayType;

/**
 * Convers a TTRouteDayType into its String equivalent.
 */
__attribute__((visibility("default")))NSString * const TTRouteDayType_toString[11];

/**
 * IQ Route type for when calculating a route.
 * Charleston – take only day into account.
 * Seattle – take day & time into account.
 * Default is Charleston.
 */
typedef enum {
    TTRouteIQType_None,
    TTRouteIQType_Charleston,
    TTRouteIQType_Seattle
} TTRouteIQType;

/**
 * Convers a TTRouteIQType into its String equivalent.
 */
__attribute__((visibility("default")))NSString * const TTRouteIQType_toString[3];

@interface TTAPIRoutingOptionalParameters: NSObject {
@private
    BOOL avoidTraffic;
    BOOL includeTraffic;
    TTRouteDayType day;
    NSString* time;
    TTRouteIQType iqRoutes;
    NSString* trafficModelId;
    BOOL avoidTolls;
    BOOL includeInstructions;
    NSString* language;
    TTProjection projection;
    BOOL includeDataPath;
    int  dataPathZoomLevel;
}

/**
 *Boolean flag to indicate if traffic information is used to plan the route (only relevant for routeType Quickest 
 * and AvoidMotorway). Default value is false.
 */
@property BOOL avoidTraffic;
/**
 * Boolean flag to indicate if traffic information is used to describe delays in the route (not relevant for routeType 
 * Walk and Bicycle). Default value is false.
 */
@property BOOL includeTraffic;
/**
 * The day of departure. Possible values are today, tomorrow, monday, tuesday, wednesday, thursday, friday, saturday, 
 * and sunday. Default value is today.
 */
@property TTRouteDayType day;
/**
 * The time of departure. Possible values are anytime, now, and 0...1439 (time expressed as the number of minutes since 
 * midnight). Default value is now.
 */
@property (nonatomic, retain) NSString* time;
/**
 * The type of IQ Routes to use when planning the route. Possible values are none, Charleston – take only day 
 * into account), and Seattle – take day & time into account. Default value is none.
 */
@property TTRouteIQType iqRoutes;
/**
 * String representation of the traffic model ID to use in the route calculation. If this parameter is omitted, the 
 * latest ID is used.
 */
@property (nonatomic, retain) NSString* trafficModelId;
/**
 * Boolean flag to indicate whether or not to avoid toll roads when planning the route. Default value is false.
 */
@property BOOL avoidTolls;
/**
 * Boolean flag to indicate if turn-by-turn instructions should be returned in the response. Default value is true.
 */
@property BOOL includeInstructions;
/**
 * The language to use for the route instructions. Default is en (English).
 */
@property (nonatomic, retain) NSString* language;
/**
 * The map projection used to specify coordinates, both for the startPoint:endPoint and data returned in the response. 
 * Possible values are EPSG4326 (default) and EPSG900913.
 */
@property TTProjection projection;

/** Boolean flag to indicate if the complete vector data path of the route must be returned */
@property (nonatomic, assign) BOOL includeDataPath;

/** zoom level for the data path. */
@property (nonatomic, assign) int dataPathZoomLevel;

/**
 * Initializes the parameters object, setting the defaults.
 * @return The initialized object.
 */
-(id) init;

/**
 * Converts the parameters to a query string that can be added to the end of the URL that accesses the server.
 * Accounts for non initialized parameters.
 * @returns an NSString with the parameters in the format: ";paramA;paramB" where paramA is either "paramA" or "paramA=xxx".
 */
-(NSString*) stringValue;

@end

/**
 * Routing API wrapper.
 * Gives access to the Routing operations provided by TomTom's Routing services
 *
 * If you feel the necessity to execute the API calls in background (using the new IOS4 features) be sure to check
 * the following link so that you can prepare your App to run the calls accordingly.
 *
 * https://developer.apple.com/iphone/library/documentation/iPhone/Conceptual/iPhoneOSProgrammingGuide/BackgroundExecution/BackgroundExecution.html
 */
@interface TTAPIRouting : NSObject {

}


#pragma mark -
#pragma mark Calculate Route


/**
 * Makes a synchronous route request.
 * Makes a synchronous route request.
 * @param startPoint The coordinates for the route start point.
 * @param endPoint The coordinates for the route end point.
 * @param routeType The route type.
 * @param optional The set of optional parameters.
 * @return The route data.
 */
- (TTAPIRoutingData *) getRouteWithStartPoint:(TTCoordinates*)startPoint andEndPoint:(TTCoordinates*)endPoint 
        andRouteType:(TTRouteType)routeType andOptionalParameters:(TTAPIRoutingOptionalParameters*)optional;

/**
 * Makes a synchronous route request.
 * @param points The coordinates for the route. It is an array if TTCoordinates
 * @param routeType The route type.
 * @param optional The set of optional parameters.
 * @return The route data.
 */
- (TTAPIRoutingData *) getRouteWithPointsArray:(NSArray*)points 
                                 andRouteType:(TTRouteType)routeType 
                        andOptionalParameters:(TTAPIRoutingOptionalParameters*)optional;

/**
 * Makes an asynchronous route request.
 * Makes an asynchronous route request. Since this is an asynchronous call, a delegate is defined and notified 
 * at the end of the call.
 * @param startPoint The coordinates for the route start point.
 * @param endPoint The coordinates for the route end point.
 * @param routeType The route type.
 * @param optional The set of optional parameters.
 * @param delegate The route delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getRouteWithStartPoint:(TTCoordinates*)startPoint andEndPoint:(TTCoordinates*)endPoint 
        andRouteType:(TTRouteType)routeType andOptionalParameters:(TTAPIRoutingOptionalParameters*)optional 
        andNotifyDelegate:(id<TTAPIRoutingDelegate>)delegate withPayload:(id)payload;

/**
 * Makes an asynchronous route request.
 * Makes an asynchronous route request. Since this is an asynchronous call, a delegate is defined and notified 
 * at the end of the call.
 * @param Points The coordinates for the route. It is an array if TTCoordinates
 * @param routeType The route type.
 * @param optional The set of optional parameters.
 * @param delegate The route delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getRouteWithPointsArray:(NSArray*)points 
                   andRouteType:(TTRouteType)routeType 
          andOptionalParameters:(TTAPIRoutingOptionalParameters*)optional 
              andNotifyDelegate:(id<TTAPIRoutingDelegate>)delegate 
                    withPayload:(id)payload;

/**
 * Creates a route operation.
 * Creates a route operation and returns it for later invocation via NSOperationQueue.
 * @param startPoint The coordinates for the route start point.
 * @param endPoint The coordinates for the route end point.
 * @param routeType The route type.
 * @param optional The set of optional parameters.
 * @return The route operation.
 */
- (TTAPIRoutingOperation *) getRoutingOperationWithStartPoint:(TTCoordinates*)startPoint andEndPoint:(TTCoordinates*)endPoint 
        andRouteType:(TTRouteType)routeType andOptionalParameters:(TTAPIRoutingOptionalParameters*)optional;

/**
 * Creates a route operation.
 * Creates a route operation and returns it for later invocation via NSOperationQueue.
 * @param Points Array of coordinates for the route 
 * @param routeType The route type.
 * @param optional The set of optional parameters.
 * @return The route operation.
 */
- (TTAPIRoutingOperation *) getRoutingOperationWithPointsArray:(NSArray*)points 
                                                  andRouteType:(TTRouteType)routeType 
                                         andOptionalParameters:(TTAPIRoutingOptionalParameters*)optional;



 
#pragma mark -
#pragma mark Recalculate Route


/**
 * Makes a synchronous route recalculation request.
 * Makes a synchronous route recalculation request.
 * @param routeId The route Id.
 * @param optional The set of optional parameters.
 * @return The recalculated route data.
 */
- (TTAPIRoutingData *) recalculateRouteWithId:(NSString *)routeId 
        andOptionalParameters:(TTAPIRoutingOptionalParameters*)optional;


/**
 * Makes an asynchronous route recalculation request.
 * Makes an asynchronous route recalculation request. Since this is an asynchronous call, a delegate is defined and 
 * notified at the end of the call.
 * @param routeId The route Id.
 * @param optional The set of optional parameters.
 * @param delegate The route delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) recalculateRouteWithId:(NSString *)routeId andOptionalParameters:(TTAPIRoutingOptionalParameters*)optional 
        andNotifyDelegate:(id<TTAPIRoutingDelegate>)delegate withPayload:(id)payload;


/**
 * Creates a route recalculation operation.
 * Creates a route recalculation operation and returns it for later invocation via NSOperationQueue.
 * @param routeId The route Id.
 * @param optional The set of optional parameters.
 * @return The route recalculation operation.
 */
- (TTAPIRecalculateRoutingOperation *) getRecalculateRoutingOperationWithId:(NSString *)routeId 
        andOptionalParameters:(TTAPIRoutingOptionalParameters*)optional;


@end
