//
//  @(#)TTAPITraffic.h 10/06/08
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>

#import "TTAPITrafficDelegate.h"

@class TTAPITrafficData;
@class TTAPITrafficOperation;
@class TTBBox;

/**
 * Defines the optional parameters for the traffic requests.
 */
@interface TTAPITrafficOptionalParameters : NSObject {
	@private
	NSString *language;
    NSString *projection;
    BOOL      expandClusters; // Default is YES
}
/** The language of the response. Default is en (English). */
@property (nonatomic, retain) NSString *language;

/** The projection of the response. Default is en EPSG4326 ( lat/long ). */
@property (nonatomic, retain) NSString *projection;

/**If Cluster incidents must be included. Default is YES. */
@property BOOL expandClusters;

/**
 * Converts the parameters to a query string that can be added to the end of the URL that accesses the server.
 * Accounts for non initialized parameters.
 * @returns an NSString with the parameters in the format: ";fullCopyright;map=mapType"
 */
-(NSString*) stringValue;

@end

/**
 * Traffic API wrapper.
 * Gives access to the Traffic operations provided by TomTom's Routing services
 *
 * If you feel the necessity to execute the API calls in background (using the new IOS4 features) be sure to check
 * the following link so that you can prepare your App to run the calls accordingly.
 *
 * https://developer.apple.com/iphone/library/documentation/iPhone/Conceptual/iPhoneOSProgrammingGuide/BackgroundExecution/BackgroundExecution.html
 */
@interface TTAPITraffic : NSObject {

}

/**
 * Makes a synchronous traffic request.
 * Makes a synchronous traffic request.
 * @param geoExtent The geo extent bounding box using mercator projection.
 * @param zoom The zoom level.
 * @param pixelExtent The pixel coordinates bounding box.
 * @param trafficModelId The traffic model Id.
 * @return The traffic model.
 */
- (TTAPITrafficData *) getTraffic:(TTBBox*)geoExtent 
					withZoomLevel:(NSInteger)zoom 
					  pixelExtent:(TTBBox*)pixelExtent 
				   trafficModelId:(NSNumber *)trafficModelId;

/**
 * Makes a synchronous traffic request.
 * Makes a synchronous traffic request.
 * @param geoExtent The geo extent bounding box using mercator projection.
 * @param zoom The zoom level.
 * @param pixelExtent The pixel coordinates bounding box.
 * @param trafficModelId The traffic model Id.
 * @param options An object containing optional parameters.
 * @return The traffic model.
 */
- (TTAPITrafficData *) getTraffic:(TTBBox*)geoExtent 
					withZoomLevel:(NSInteger)zoom 
					  pixelExtent:(TTBBox*)pixelExtent 
				   trafficModelId:(NSNumber *)trafficModelId 
			   optionalParameters:(TTAPITrafficOptionalParameters*)options;

/**
 * Makes an asynchronous traffic request.
 * Makes an asynchronous traffic request. Since this is an asynchronous call, a delegate is defined and notified 
 * at the end of the call.
 * @param geoExtent The geo extent bounding box using mercator projection.
 * @param zoom The zoom level.
 * @param pixelExtent The pixel coordinates bounding box.
 * @param trafficModelId The traffic model Id.
 * @param delegate The traffic delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getTraffic:(TTBBox*)geoExtent 
	  withZoomLevel:(NSInteger)zoom 
		pixelExtent:(TTBBox*)pixelExtent 
	 trafficModelId:(NSNumber *)trafficModelId
  andNotifyDelegate:(id<TTAPITrafficDelegate>)delegate withPayload:(id)payload;

/**
 * Makes an asynchronous traffic request.
 * Makes an asynchronous traffic request. Since this is an asynchronous call, a delegate is defined and notified 
 * at the end of the call.
 * @param geoExtent The geo extent bounding box using mercator projection.
 * @param zoom The zoom level.
 * @param pixelExtent The pixel coordinates bounding box.
 * @param trafficModelId The traffic model Id.
 * @param options An object containing optional parameters.
 * @param delegate The traffic delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getTraffic:(TTBBox*)geoExtent 
	  withZoomLevel:(NSInteger)zoom 
		pixelExtent:(TTBBox*)pixelExtent 
	 trafficModelId:(NSNumber *)trafficModelId 
 optionalParameters:(TTAPITrafficOptionalParameters*)options 
  andNotifyDelegate:(id<TTAPITrafficDelegate>)delegate withPayload:(id)payload;

/**
 * Creates a traffic operation.
 * Creates a traffic operation and returns it for later invocation via NSOperationQueue.
 * @param geoExtent The geo extent bounding box using mercator projection.
 * @param zoom The zoom level.
 * @param pixelExtent The pixel coordinates bounding box.
 * @param trafficModelId The traffic model Id.
 * @return A traffic operation.
 */
- (TTAPITrafficOperation *) getTrafficOperation:(TTBBox*)geoExtent
								  withZoomLevel:(NSInteger)zoom 
									pixelExtent:(TTBBox*)pixelExtent 
								 trafficModelId:(NSNumber *)trafficModelId;

/**
 * Creates a traffic operation.
 * Creates a traffic operation and returns it for later invocation via NSOperationQueue.
 * @param geoExtent The geo extent bounding box using mercator projection.
 * @param zoom The zoom level.
 * @param pixelExtent The pixel coordinates bounding box.
 * @param trafficModelId The traffic model Id.
 * @param options An object containing optional parameters.
 * @return A traffic operation.
 */
- (TTAPITrafficOperation *) getTrafficOperation:(TTBBox*)geoExtent 
								  withZoomLevel:(NSInteger)zoom 
									pixelExtent:(TTBBox*)pixelExtent 
								 trafficModelId:(NSNumber *)trafficModelId 
							 optionalParameters:(TTAPITrafficOptionalParameters*)options;

/**
 * Returns a default pixel extent populated with 0,0,0,0.
 * Returns a default pixel extent. All coordinates will be initialized with 0 value.
 * @return A default pixel extent.
 */
+ (TTBBox *) defaultPixelExtent;

@end
