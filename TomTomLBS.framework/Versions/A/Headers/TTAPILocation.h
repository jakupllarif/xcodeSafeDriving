//
//  @(#)TTAPILocation.h 10/05/24
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPILocationDelegate.h"
#include "TTSDKUtils.h"

#pragma mark -
#pragma mark Location API Utils

@class TTBBox;
@class TTCoordinates;

/*
 * Defines the TTLocationOrder for geocode calls.
 * See TTLocationOrder_toString for a way to convert into NSString*
 */
typedef enum {
	TTLocationOrderScore,
	TTLocationOrderProximity
} TTLocationOrder;

/**
 * Convers a TTLocationOrder into its String equivalent.
 */
__attribute__((visibility("default")))NSString * const TTLocationOrder_toString[2];


/*
 * Defines the TTType for API calls.
 * See TTType_toString for a way to convert into NSString*
 */
typedef enum {
	TTReverseGeocodeTypeBasic,
	TTReverseGeocodeTypeAll,
	TTReverseGeocodeTypeInternational,
	TTReverseGeocodeTypeNational,
	TTReverseGeocodeTypeRegional
} TTReverseGeocodeType;

/**
 * Convers a TTReverseGeocodeType into its String equivalent.
 */
__attribute__((visibility("default")))NSString * const TTReverseGeocodeType_toString[5];

/**
 * Defines the optional parameters for the geocode requests.
 */
@interface TTAPIGeocodeOptionalParameters : NSObject {
	@private
	TTBBox *bbox;
	TTCoordinates *biasPoint;
	TTProjection projection;
	NSInteger poiCategories;
	TTLocationOrder order;
	NSString *geoHash;
	NSString *language;
}

/** A bounding box to which the request should be restricted. Specified as min_lat,min_lon,max_lat,max_lon in the 
 * coordinate system of the projection used (see projection below). */
@property (nonatomic, retain) TTBBox *bbox;
/** The point from where the results should be ordered. This defaults to the center of bbox. */
@property (nonatomic, retain) TTCoordinates *biasPoint;
/** The map projection used to specify coordinates returned in the response. Possible values are EPSG4326 (default) and
 * EPSG900913. */
@property (nonatomic, assign) TTProjection projection;
/** The categories of the POIs the request should look for. */
@property (nonatomic, assign) NSInteger poiCategories;
/** The sort order of the results. Possible values are SCORE (default) and PROXIMITY. */
@property (nonatomic, assign) TTLocationOrder order;
/** The query geohash. */
@property (nonatomic, retain) NSString *geoHash;
/** The language of the response. Default is en (English). */
@property (nonatomic, retain) NSString *language;

/**
 * Converts the parameters to a query string that can be added to the end of the URL that accesses the server.
 * Accounts for non initialized parameters.
 * @returns An NSString with the parameters in the format: ";fullCopyright;map=mapType"
 */
-(NSString*) stringValue;

@end

/**
 * Defines the optional parameters for the reverse geocode requests.
 */
@interface TTAPIReverseGeocodeOptionalParameters : NSObject {
	@private
	TTReverseGeocodeType type;
	TTProjection projection;
	NSString *language;
}

/** Possible values are Basic (default), All, International, National, and Regional. */
@property (nonatomic, assign) TTReverseGeocodeType type;
/** The map projection used to specify coordinates returned in the response. Possible values are EPSG4326 (default) and 
 * EPSG900913. */
@property (nonatomic, assign) TTProjection projection;
/** The language of the response. Default is en (English). */
@property (nonatomic, retain) NSString *language;

/**
 * Converts the parameters to a query string that can be added to the end of the URL that accesses the server.
 * Accounts for non initialized parameters.
 * @returns An NSString with the parameters in the format: ";fullCopyright;map=mapType"
 */
-(NSString*) stringValue;

@end



#pragma mark -
#pragma mark Location API

@class TTAPIGeocodeData;
@class TTAPIReverseGeocodeData;
@class TTAPIGeocodeOperation;
@class TTAPIReverseGeocodeOperation;

/**
 * The SDK Location API.
 * Brings geocode and reverse geocode search to the SDK.
 *
 * If you feel the necessity to execute the API calls in background (using the new IOS4 features) be sure to check
 * the following link so that you can prepare your App to run the calls accordingly.
 *
 * https://developer.apple.com/iphone/library/documentation/iPhone/Conceptual/iPhoneOSProgrammingGuide/BackgroundExecution/BackgroundExecution.html
 */
@interface TTAPILocation : NSObject {

}

/**
 * Makes a synchronous geocode request.
 * Makes a synchronous geocode request based on a text query. The text query is normally a location, country or address.
 * @param query The geocode query.
 * @return The geocode response.
 */
- (TTAPIGeocodeData *) geocode:(NSString *)query;

/**
 * Makes a synchronous geocode request.
 * Makes a synchronous geocode request based on a text query. The text query is normally a location, country or address.
 * @param query The geocode query.
 * @param optional An object of optional parameters.
 * @return The geocode response.
 */
- (TTAPIGeocodeData *) geocode:(NSString *)query withOptionalParameters:(TTAPIGeocodeOptionalParameters *)optional;

/**
 * Makes an asynchronous geocode request.
 * Makes an asynchronous geocode request based on a text query. The text query is normally a location, country or 
 * address. Since this is an asynchronous call, a delegate is defined and notified at the end of the call.
 * @param query The geocode query.
 * @param delegate The geocode delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed.
 */
- (void) geocode:(NSString *)query andNotifyDelegate:(id<TTAPILocationDelegate>)delegate withPayload:(id)payload;

/**
 * Makes an asynchronous geocode request.
 * Makes an asynchronous geocode request based on a text query. The text query is normally a location, country or 
 * address. Since this is an asynchronous call, a delegate is defined and notified at the end of the call.
 * @param query The geocode query.
 * @param optional An object of optional parameters.
 * @param delegate The geocode delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed.
 */
- (void) geocode:(NSString *)query withOptionalParameters:(TTAPIGeocodeOptionalParameters *)optional 
                                        andNotifyDelegate:(id<TTAPILocationDelegate>)delegate withPayload:(id)payload;

/**
 * Creates a geocode operation.
 * Creates a geocode operation and returns it for later invocation via NSOperationQueue.
 * @param query The geocode query.
 * @return A geocode operation.
 */
- (TTAPIGeocodeOperation *) getGeoCodeOperation:(NSString *)query;

/**
 * Creates a geocode operation.
 * Creates a geocode operation and returns it for later invocation via NSOperationQueue.
 * @param query The geocode query.
 * @param optional An object of optional parameters.
 * @return A geocode operation.
 */
- (TTAPIGeocodeOperation *) getGeoCodeOperation:(NSString *)query 
						 withOptionalParameters:(TTAPIGeocodeOptionalParameters *)optional;

/**
 * Makes a synchronous reverse geocode request.
 * Makes a synchronous reverse geocode request based on a latitude and longitude. 
 * @param latitude The latitude.
 * @param longitude The longitude.
 * @return The reverse geocode response.
 */
- (TTAPIReverseGeocodeData *) reverseGeocodeWithLatitude:(NSNumber*)latitude andLongitude:(NSNumber*)longitude;

/**
 * Makes a synchronous reverse geocode request.
 * Makes a synchronous reverse geocode request based on a latitude and longitude. 
 * @param latitude The latitude.
 * @param longitude The longitude.
 * @param optional An object of optional parameters.
 * @return The reverse geocode response.
 */
- (TTAPIReverseGeocodeData *) reverseGeocodeWithLatitude:(NSNumber*)latitude andLongitude:(NSNumber*)longitude 
								   andOptionalParameters:(TTAPIReverseGeocodeOptionalParameters*)optional;

/**
 * Makes an asynchronous reverse geocode request.
 * Makes an asynchronous reverse geocode request based on a latitude and longitude. Since this is an asynchronous 
 * call, a delegate is defined and notified at the end of the call.
 * @param latitude The latitude.
 * @param longitude The longitude.
 * @param delegate The reverse geocode delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) reverseGeocodeWithLatitude:(NSNumber*)latitude andLongitude:(NSNumber*)longitude 
				  andNotifyDelegate:(id<TTAPILocationDelegate>)delegate withPayload:(id)payload;

/**
 * Makes an asynchronous reverse geocode request.
 * Makes an asynchronous reverse geocode request based on a latitude and longitude. Since this is an asynchronous 
 * call, a delegate is defined and notified at the end of the call.
 * @param latitude The latitude.
 * @param longitude The longitude.
 * @param optional An object of optional parameters.
 * @param delegate The reverse geocode delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) reverseGeocodeWithLatitude:(NSNumber*)latitude andLongitude:(NSNumber*)longitude 
				 andOptionalParameters:(TTAPIReverseGeocodeOptionalParameters*)optional 
				  andNotifyDelegate:(id<TTAPILocationDelegate>)delegate withPayload:(id)payload;

/**
 * Creates a reverse geocode operation.
 * Creates a reverse geocode operation and returns it for later invocation via NSOperationQueue.
 * @param latitude The latitude.
 * @param longitude The longitude.
 * @return A reverse geocode operation.
 */
- (TTAPIReverseGeocodeOperation *) getReverseGeoCodeOperationWithLatitude:(NSNumber*)latitude 
															 andLongitude:(NSNumber*)longitude;

/**
 * Creates a reverse geocode operation.
 * Creates a reverse geocode operation and returns it for later invocation via NSOperationQueue.
 * @param latitude The latitude.
 * @param longitude The longitude.
 * @param optional An object of optional parameters.
 * @return A reverse geocode operation.
 */
- (TTAPIReverseGeocodeOperation *) getReverseGeoCodeOperationWithLatitude:(NSNumber*)latitude 
																andLongitude:(NSNumber*)longitude 
												   andOptionalParameters:(TTAPIReverseGeocodeOptionalParameters*)optional;

@end
