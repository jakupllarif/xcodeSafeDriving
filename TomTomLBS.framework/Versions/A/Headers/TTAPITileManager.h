//
//  @(#)TTAPITileManager.h 10/05/24
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTBBox.h"
#import "TTAPITileDelegate.h"
#import "TTSDKUtils.h"
#import "TTAPIBaseData.h"
#import "TTAPIRoutingData.h"

@class TTAPIWMSTileData;
@class TTAPIIntegerTileData;
@class TTAPIWMSTileOperation;
@class TTAPIIntegerTileOperation;

/**
 * Defines the optional parameters for the  WMS tile requests.
 */
@interface TTAPIWMSTileOptionalParameters : NSObject {
@private
	NSString *routeKey;
}
/** The route key. Used when retrieving a WMS route tile. */
@property (nonatomic, retain) NSString *routeKey;

/**
 * Converts the parameters to a query string that can be added to the end of the URL that accesses the server.
 * Accounts for non initialized parameters.
 * @returns An NSString with the parameters in the format: "&ROUTEKEY=123456789"
 */
-(NSString*) stringValue;

@end

/**
 * Defines the optional parameters for the Integer tile requests.
 */
@interface TTAPIIntegerTileOptionalParameters : NSObject {
@private
	NSString *routeKey;
}
/** The route key. Used when retrieving an Integer route tile. */
@property (nonatomic, retain) NSString *routeKey;

/**
 * Converts the parameters to a query string that can be added to the end of the URL that accesses the server.
 * Accounts for non initialized parameters.
 * @returns an NSString with the parameters in the format: ";t=123456789"
 */
-(NSString*) stringValue;

@end

/**
 * The SDK Tile API.
 * Gives access to map and traffic tiles using the WMS and/or Integer services.
 *
 * If you feel the necessity to execute the API calls in background (using the new IOS4 features) be sure to check
 * the following link so that you can prepare your App to run the calls accordingly.
 *
 * https://developer.apple.com/iphone/library/documentation/iPhone/Conceptual/iPhoneOSProgrammingGuide/BackgroundExecution/BackgroundExecution.html
 */
@interface TTAPITileManager : NSObject {

}

#pragma mark -
#pragma mark Generic WMS API tile methods

/**
 * Makes a synchronous tile request using the WMS service.
 * Makes a synchronous tile request using the WMS service based on a bounding box.
 * @param bbox The bounding box.
 * @param type The tile type.
 * @param format The tile image format (png or gif)
 * @return The map tile.
 */
- (TTAPIWMSTileData *) getTileViaWMSWithBBox:(TTBBox*)bbox 
								   layerType:(TTLayerType)type 
									  format:(TTImageFormat)format __attribute__((deprecated));

/**
 * Makes a synchronous tile request using the WMS service.
 * Makes a synchronous tile request using the WMS service based on a bounding box.
 * @param bbox The bounding box.
 * @param type The tile type.
 * @param format The tile image format (png or gif)
 * @param optional An object with optional parameters.
 * @return The map tile.
 */
- (TTAPIWMSTileData *) getTileViaWMSWithBBox:(TTBBox*)bbox layerType:(TTLayerType)type 
									  format:(TTImageFormat)format 
						  optionalParameters:(TTAPIWMSTileOptionalParameters *)optional __attribute__((deprecated));

/**
 * Makes an asynchronous tile request using the WMS service.
 * Makes an asynchronous tile request using the WMS service based on a bounding box. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param bbox The bounding box.
 * @param type The tile type.
 * @param format The tile image format (png or gif)
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getTileViaWMSWithBBox:(TTBBox*)bbox 
					 layerType:(TTLayerType)type 
						format:(TTImageFormat)format 
			 andNotifyDelegate:(id<TTAPITileDelegate>)delegate withPayload:(id)payload __attribute__((deprecated));

/**
 * Makes an asynchronous tile request using the WMS service.
 * Makes an asynchronous tile request using the WMS service based on a bounding box. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param bbox The bounding box.
 * @param type The tile type.
 * @param format The tile image format (png or gif)
 * @param optional An object with optional parameters.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getTileViaWMSWithBBox:(TTBBox*)bbox 
					 layerType:(TTLayerType)type 
						format:(TTImageFormat)format 
			optionalParameters:(TTAPIWMSTileOptionalParameters *)optional 
			 andNotifyDelegate:(id<TTAPITileDelegate>)delegate withPayload:(id)payload __attribute__((deprecated));

/**
 * Creates a tile operation using the WMS service.
 * Creates a tile operation using the WMS service and returns it for later invocation via NSOperationQueue.
 * @param bbox The bounding box.
 * @param type The tile type.
 * @param format The tile image format (png or gif)
 * @return A tile operation.
 */
- (TTAPIWMSTileOperation *) getTileViaWMSOperationWithBBox:(TTBBox*)bbox 
												 layerType:(TTLayerType)type 
													format:(TTImageFormat)format __attribute__((deprecated));

/**
 * Creates a tile operation using the WMS service.
 * Creates a tile operation using the WMS service and returns it for later invocation via NSOperationQueue.
 * @param bbox The bounding box.
 * @param type The tile type.
 * @param format The tile image format (png or gif)
 * @param optional An object with optional parameters.
 * @return A tile operation.
 */
- (TTAPIWMSTileOperation *) getTileViaWMSOperationWithBBox:(TTBBox*)bbox 
												 layerType:(TTLayerType)type 
													format:(TTImageFormat)format 
										optionalParameters:(TTAPIWMSTileOptionalParameters *)optional __attribute__((deprecated));

#pragma mark -
#pragma mark Helper WMS API tile methods

/**
 * Makes a synchronous map tile request using the WMS service.
 * Makes a synchronous map tile request using the WMS service based on a bounding box. The tile will be served
 * in PNG format.
 * @param bbox The bounding box.
 * @return The map tile.
 */
- (TTAPIWMSTileData *) getMapTileViaWMSWithBBox:(TTBBox*)bbox __attribute__((deprecated));

/**
 * Makes an asynchronous map tile request using the WMS service.
 * Makes an asynchronous map tile request using the WMS service based on a bounding box. The tile will be served
 * in PNG format. Since this is an asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param bbox The bounding box.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getMapTileViaWMSWithBBox:(TTBBox*)bbox andNotifyDelegate:(id<TTAPITileDelegate>)delegate withPayload:(id)payload __attribute__((deprecated));

/**
 * Creates a map tile operation using the WMS service.
 * Creates a map tile operation using the WMS service and returns it for later invocation via NSOperationQueue.
 * @param bbox The bounding box.
 * @return A map tile operation.
 */
- (TTAPIWMSTileOperation *) getMapTileViaWMSOperationWithBBox:(TTBBox*)bbox __attribute__((deprecated));

/**
 * Makes a synchronous traffic tile request using the WMS service.
 * Makes a synchronous traffic tile request using the WMS service based on a bounding box.
 * @param bbox The bounding box.
 * @param format The tile image format (png or gif)
 * @return The traffic tile.
 */
- (TTAPIWMSTileData *) getTrafficTileViaWMSWithBBox:(TTBBox*)bbox format:(TTImageFormat)format __attribute__((deprecated));

/**
 * Makes an asynchronous traffic tile request using the WMS service.
 * Makes an asynchronous traffic tile request using the WMS service based on a bounding box. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param bbox The bounding box.
 * @param format The tile image format (png or gif)
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getTrafficTileViaWMSWithBBox:(TTBBox*)bbox format:(TTImageFormat)format 
					andNotifyDelegate:(id<TTAPITileDelegate>)delegate withPayload:(id)payload __attribute__((deprecated));

/**
 * Creates a traffic tile operation using the WMS service.
 * Creates a traffic tile operation using the WMS service and returns it for later invocation via NSOperationQueue.
 * @param bbox The bounding box.
 * @param format The tile image format (png or gif)
 * @return A traffic tile operation.
 */
- (TTAPIWMSTileOperation *) getTrafficTileViaWMSOperationWithBBox:(TTBBox*)bbox format:(TTImageFormat)format __attribute__((deprecated));

/**
 * Makes a synchronous route tile request using the WMS service.
 * Makes a synchronous route tile request using the WMS service with a route key and bounding box.
 * @param routeKey The route key. Obtained calling the route request from the route API.
 * @param bbox The bounding box.
 * @param format The tile image format (png or gif)
 * @return The route tile.
 */
- (TTAPIWMSTileData *) getRouteTileViaWMSWithRouteKey:(NSString *)routeKey bbox:(TTBBox*)bbox format:(TTImageFormat)format __attribute__((deprecated));

/**
 * Makes an asynchronous route tile request using the WMS service.
 * Makes na asynchronous route tile request using the WMS service with a route key and bounding box. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param routeKey The route key. Obtained calling the route request from the route API.
 * @param bbox The bounding box.
 * @param format The tile image format (png or gif)
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getRouteTileViaWMSWithRouteKey:(NSString *)routeKey bbox:(TTBBox*)bbox format:(TTImageFormat)format 
					  andNotifyDelegate:(id<TTAPITileDelegate>)delegate withPayload:(id)payload __attribute__((deprecated));

/**
 * Creates a route tile operation using the WMS service.
 * Creates a route tile operation using the WMS service and returns it for later invocation via NSOperationQueue.
 * @param routeKey The route key. Obtained calling the route request from the route API.
 * @param bbox The bounding box.
 * @param format The tile image format (png or gif)
 * @return A route tile operation.
 */
- (TTAPIWMSTileOperation *) getRouteTileViaWMSOperationWithRouteKey:(NSString *)routeKey bbox:(TTBBox*)bbox format:(TTImageFormat)format __attribute__((deprecated));

#pragma mark -
#pragma mark Generic Integer API tile methods

/**
 * Makes a synchronous tile request using the Integer service.
 * Makes a synchronous tile request using the Integer service based on x, y and zoom level.
 * @param type The tile type.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @return The map tile.
 */
- (TTAPIIntegerTileData *) getTileViaIntegerWithLayerType:(TTLayerType)type 
														x:(NSInteger)x 
														y:(NSInteger)y 
													 zoom:(NSInteger)zoom;

/**
 * Makes a synchronous tile request using the Integer service.
 * Makes a synchronous tile request using the Integer service based on x, y and zoom level.
 * @param type The tile type.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @param optional An object with optional parameters.
 * @return The map tile.
 */
- (TTAPIIntegerTileData *) getTileViaIntegerWithLayerType:(TTLayerType)type 
														x:(NSInteger)x 
														y:(NSInteger)y 
													 zoom:(NSInteger)zoom 
									   optionalParameters:(TTAPIIntegerTileOptionalParameters *)optional;


/**
 * Makes an asynchronous tile request using the Integer service.
 * Makes an asynchronous tile request using the Integer service based on x, y and zoom level. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param type The tile type.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getTileViaIntegerWithLayerType:(TTLayerType)type 
									  x:(NSInteger)x 
									  y:(NSInteger)y 
								   zoom:(NSInteger)zoom 
					  andNotifyDelegate:(id<TTAPITileDelegate>)delegate withPayload:(id)payload;

/**
 * Makes an asynchronous tile request using the Integer service.
 * Makes an asynchronous tile request using the Integer service based on x, y and zoom level. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param type The tile type.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @param optional An object with optional parameters.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getTileViaIntegerWithLayerType:(TTLayerType)type 
									  x:(NSInteger)x 
									  y:(NSInteger)y 
								   zoom:(NSInteger)zoom 
					 optionalParameters:(TTAPIIntegerTileOptionalParameters *)optional 
					  andNotifyDelegate:(id<TTAPITileDelegate>)delegate withPayload:(id)payload;

/**
 * Creates a tile operation using the Integer service.
 * Creates a tile operation using the Integer service and returns it for later invocation via NSOperationQueue.
 * @param type The tile type.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @return A map tile operation.
 */
- (TTAPIIntegerTileOperation *) getTileViaIntegerOperationWithLayerType:(TTLayerType)type 
																	  x:(NSInteger)x 
																	  y:(NSInteger)y 
																   zoom:(NSInteger)zoom;

/**
 * Creates a tile operation using the Integer service.
 * Creates a tile operation using the Integer service and returns it for later invocation via NSOperationQueue.
 * @param type The tile type.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @param optional An object with optional parameters.
 * @return A map tile operation.
 */
- (TTAPIIntegerTileOperation *) getTileViaIntegerOperationWithLayerType:(TTLayerType)type 
																	  x:(NSInteger)x 
																	  y:(NSInteger)y 
																   zoom:(NSInteger)zoom 
													 optionalParameters:(TTAPIIntegerTileOptionalParameters *)optional;

#pragma mark -
#pragma mark Helper Integer API tile methods

/**
 * Makes a synchronous map tile request using the Integer service.
 * Makes a synchronous map tile request using the Integer service based on x, y and zoom level. The tile will be served
 * in PNG format.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @return The map tile.
 */
- (TTAPIIntegerTileData *) getMapTileViaIntegerWithX:(NSInteger)x y:(NSInteger)y zoom:(NSInteger)zoom;

/**
 * Makes an asynchronous map tile request using the Integer service.
 * Makes an asynchronous map tile request using the Integer service based on x, y and zoom level. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getMapTileViaIntegerWithX:(NSInteger)x 
								 y:(NSInteger)y 
							  zoom:(NSInteger)zoom 
				 andNotifyDelegate:(id<TTAPITileDelegate>)delegate withPayload:(id)payload;

/**
 * Creates a map tile operation using the Integer service.
 * Creates a map tile operation using the Integer service and returns it for later invocation via NSOperationQueue.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @return A map tile operation.
 */
- (TTAPIIntegerTileOperation *) getMapTileViaIntegerOperationWithX:(NSInteger)x y:(NSInteger)y zoom:(NSInteger)zoom;

/**
 * Makes a synchronous traffic tile request using the Integer service.
 * Makes a synchronous traffic tile request using the Integer service based on x, y and zoom level.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @return The traffic tile.
 */
- (TTAPIIntegerTileData *) getTrafficTileViaIntegerWithX:(NSInteger)x 
													   y:(NSInteger)y 
													zoom:(NSInteger)zoom;

/**
 * Makes an asynchronous traffic tile request using the Integer service.
 * Makes an asynchronous traffic tile request using the Integer service based on x, y and zoom level. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getTrafficTileViaIntegerWithX:(NSInteger)x 
									 y:(NSInteger)y 
								  zoom:(NSInteger)zoom 
					 andNotifyDelegate:(id<TTAPITileDelegate>)delegate withPayload:(id)payload;

/**
 * Creates a traffic tile operation using the Integer service.
 * Creates a traffic tile operation using the Integer service and returns it for later invocation via NSOperationQueue.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @return A traffic tile operation.
 */
- (TTAPIIntegerTileOperation *) getTrafficTileViaIntegerOperationWithX:(NSInteger)x 
																	 y:(NSInteger)y 
																  zoom:(NSInteger)zoom;

/**
 * Makes a synchronous route tile request using the Integer service.
 * Makes a synchronous route tile request using the Integer service with a route key, x, y and zoom level.
 * @param routeKey The route key. Obtained calling the route request from the route API.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @return The route tile.
 */
- (TTAPIIntegerTileData *) getRouteTileViaIntegerWithRouteKey:(NSString *)routeKey 
															x:(NSInteger)x 
															y:(NSInteger)y 
														 zoom:(NSInteger)zoom;

/**
 * Makes an asynchronous route request using the Integer service.
 * Makes an asynchronous route tile request using the Integer service based on x, y and zoom level. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param routeKey The route key. Obtained calling the route request from the route API.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getRouteTileViaIntegerWithRouteKey:(NSString *)routeKey 
										  x:(NSInteger)x 
										  y:(NSInteger)y 
									   zoom:(NSInteger)zoom 
						  andNotifyDelegate:(id<TTAPITileDelegate>)delegate withPayload:(id)payload;

/**
 * Creates a route tile operation using the Integer service.
 * Creates a route tile operation using the Integer service and returns it for later invocation via NSOperationQueue.
 * @param routeKey The route key. Obtained calling the route request from the route API.
 * @param x The x point.
 * @param y The y point.
 * @param zoom The zoom level.
 * @return A route tile operation.
 */
- (TTAPIIntegerTileOperation *) getRouteTileViaIntegerOperationWithRouteKey:(NSString *)routeKey 
																		  x:(NSInteger)x 
																		  y:(NSInteger)y 
																	   zoom:(NSInteger)zoom;

/**
 * Makes a synchronous map tile request using the WMS service.
 * Makes a synchronous map tile request using the WMS service based on a (x,y) map point and zoom level. The tile will be served
 * in PNG format.
 * @param coordinates Coordinates of a point in the tile we want to retrieve.
 * @param zoomLevel The zoom level.
 * @return The map tile.
 */
- (TTAPIWMSTileData*) getMapTileViaWMSWithCoordinates: (TTCoordinates*) coordinates 
										 andZoomLevel: (NSInteger) zoomLevel;

/**
 * Makes an asynchronous map tile request using the WMS service.
 * Makes an asynchronous map tile request using the WMS service based on a (x,y) map point and zoom level. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param coordinates Coordinates of a point in the tile we want to retrieve.
 * @param zoomLevel The zoom level.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getMapTileViaWMSWithCoordinates: (TTCoordinates*) coordinates 
							andZoomLevel: (NSInteger) zoomLevel 
					   andNotifyDelegate: (id<TTAPITileDelegate>)delegate 
							 withPayload: (id)payload;
	
/**
 * Makes a synchronous route tile request using the WMS service.
 * Makes a synchronous route tile request using the WMS service based on a (x,y) map point and zoom level. The tile will be served
 * in PNG format.
 * @param coordinates Coordinates of a point in the tile we want to retrieve.
 * @param zoomLevel The zoom level.
 * @param routingData Route data. Contains the route key that needs to be passed to the server.
 * @return The map tile.
 */
- (TTAPIWMSTileData*) getRouteTileViaWMSWithCoordinates: (TTCoordinates*) coordinates 
										   andZoomLevel: (NSInteger) zoomLevel 
											andRoutingData: (TTAPIRoutingData*) routingData;

/**
 * Makes an asynchronous route tile request using the WMS service.
 * Makes an asynchronous route tile request using the WMS service based on a (x,y) map point and zoom level. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param coordinates Coordinates of a point in the tile we want to retrieve.
 * @param zoomLevel The zoom level.
 * @param routingData Route data. Contains the route key that needs to be passed to the server.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getRouteTileViaWMSWithCoordinates: (TTCoordinates*) coordinates 
							  andZoomLevel: (NSInteger) zoomLevel 
							   andRoutingData: (TTAPIRoutingData*) routingData 
						 andNotifyDelegate: (id<TTAPITileDelegate>)delegate 
							   withPayload: (id)payload;

/**
 * Makes a synchronous traffic tile request using the WMS service.
 * Makes a synchronous traffic tile request using the WMS service based on a (x,y) map point and zoom level. The tile will be served
 * in PNG format.
 * @param coordinates Coordinates of a point in the tile we want to retrieve.
 * @param zoomLevel The zoom level.
 * @return The map tile.
 */
- (TTAPIWMSTileData*) getTrafficTileViaWMSWithCoordinates: (TTCoordinates*) coordinates 
											 andZoomLevel: (NSInteger) zoomLevel ;

/**
 * Makes an asynchronous traffic tile request using the WMS service.
 * Makes an asynchronous traffic tile request using the WMS service based on a (x,y) map point and zoom level. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param coordinates Coordinates of a point in the tile we want to retrieve.
 * @param zoomLevel The zoom level.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getTrafficTileViaWMSWithCoordinates: (TTCoordinates*) coordinates 
								andZoomLevel: (NSInteger) zoomLevel 
						   andNotifyDelegate: (id<TTAPITileDelegate>)delegate 
								 withPayload: (id)payload;

/**
 * Makes a synchronous map tile request using the Integer service.
 * Makes a synchronous map tile request using the Integer service based on a (x,y) map point and zoom level. The tile will be served
 * in PNG format.
 * @param coordinates Coordinates of a point in the tile we want to retrieve.
 * @param zoomLevel The zoom level.
 * @return The map tile.
 */
- (TTAPIWMSTileData*) getMapTileViaIntegerWithCoordinates: (TTCoordinates*) coordinates 
											 andZoomLevel: (NSInteger) zoomLevel ;

/**
 * Makes an asynchronous map tile request using the Integer service.
 * Makes an asynchronous map tile request using the Integer service based on a (x,y) map point and zoom level. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param coordinates Coordinates of a point in the tile we want to retrieve.
 * @param zoomLevel The zoom level.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getMapTileViaIntegerWithCoordinates: (TTCoordinates*) coordinates 
								andZoomLevel: (NSInteger) zoomLevel 
						   andNotifyDelegate: (id<TTAPITileDelegate>)delegate 
								 withPayload: (id)payload;

/**
 * Makes a synchronous traffic tile request using the Integer service.
 * Makes a synchronous traffic tile request using the Integer service based on a (x,y) map point and zoom level. The tile will be served
 * in PNG format.
 * @param coordinates Coordinates of a point in the tile we want to retrieve.
 * @param zoomLevel The zoom level.
 * @return The map tile.
 */
- (TTAPIWMSTileData*) getTrafficTileViaIntegerWithCoordinates: (TTCoordinates*) coordinates 
												 andZoomLevel: (NSInteger) zoomLevel;

/**
 * Makes an asynchronous traffic tile request using the Integer service.
 * Makes an asynchronous traffic tile request using the Integer service based on a (x,y) map point and zoom level. Since this is an 
 * asynchronous call, a delegate is defined and notified at the end of the call.
 *
 * Internally an operation is created and added to the SDK Operation Queue. The operation will retain the delegate 
 * for as long as the operation life cycle.
 *
 * @param coordinates Coordinates of a point in the tile we want to retrieve.
 * @param zoomLevel The zoom level.
 * @param delegate The tile delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getTrafficTileViaIntegerWithCoordinates: (TTCoordinates*) coordinates 
									andZoomLevel: (NSInteger) zoomLevel 
							   andNotifyDelegate: (id<TTAPITileDelegate>)delegate 
									 withPayload: (id)payload;

@end
