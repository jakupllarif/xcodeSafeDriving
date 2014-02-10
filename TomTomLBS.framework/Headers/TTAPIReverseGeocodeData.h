//
//  @(#)TTAPIReverseGeocodeData.h 10/05/27
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
 * Represent a reverse geo code result entry.
 */
@interface TTAPIReverseGeoResult : NSObject {
	@private
	NSString *type;
	NSNumber* latitude;
	NSNumber* longitude;
	NSString *street;
	NSString *city;
	NSString *district;
	NSString *state;
	NSString *country;
	NSString *countryISO3;
	NSString *formattedAddress;
	TTCoordinates* centerCoord;
	NSString *roadType;
	NSString *streetClass;
	NSMutableArray *postcodes;
	NSString *highwayJunction;
	NSString *locationName;
	NSString *locationPartName;
	NSString *majorLocationName;
	NSInteger majorLocationDistanceMeters;
	NSString *majorLocationCountry;
	NSInteger maxSpeedKph;
	NSInteger averageSpeedKph;
	NSString *mediumLocationCountry;
	NSString *houseNumber;
	NSString *houseNumberMin;
	NSString *houseNumberMax;
}

/** The result type. */
@property (nonatomic, retain) NSString *type;
/** The result latitude. */
@property (nonatomic, retain) NSNumber* latitude;
/** The result longitude. */
@property (nonatomic, retain) NSNumber* longitude;
/** The result street. Optional field.*/
@property (nonatomic, retain) NSString *street;
/** The result city. Optional field.*/
@property (nonatomic, retain) NSString *city;
/** The result district. Optional field.*/
@property (nonatomic, retain) NSString *district;
/** The result state. Optional field.*/
@property (nonatomic, retain) NSString *state;
/** The result country. Optional field.*/
@property (nonatomic, retain) NSString *country;
/** The result country in ISO3 format. Optional field.*/
@property (nonatomic, retain) NSString *countryISO3;
/** The result formatted address. Optional field.*/
@property (nonatomic, retain) NSString *formattedAddress;
/** The result center coordinates. Optional field.*/
@property (nonatomic, retain) TTCoordinates* centerCoord;
/** The result road type. Optional field.*/
@property (nonatomic, retain) NSString *roadType;
/** The result street class. Optional field.*/
@property (nonatomic, retain) NSString *streetClass;
/** The result highway junction. Optional field.*/
@property (nonatomic, retain) NSString *highwayJunction;
/** The result location name. Optional field.*/
@property (nonatomic, retain) NSString *locationName;
/** The result location part name. Optional field.*/
@property (nonatomic, retain) NSString *locationPartName;
/** The result major location name. Optional field.*/
@property (nonatomic, retain) NSString *majorLocationName;
/** The result major location distance in meters. Optional field.*/
@property (nonatomic, assign) NSInteger majorLocationDistanceMeters;
/** The result major location country. Optional field.*/
@property (nonatomic, retain) NSString *majorLocationCountry;
/** The result max speed in kph. Optional field.*/
@property (nonatomic, assign) NSInteger maxSpeedKph;
/** The result average speed in kph. Optional field.*/
@property (nonatomic, assign) NSInteger averageSpeedKph;
/** The result medium location country. Optional field.*/
@property (nonatomic, retain) NSString *mediumLocationCountry;
/** The result house number. Optional field.*/
@property (nonatomic, retain) NSString *houseNumber;
/** The result house number min. Optional field.*/
@property (nonatomic, retain) NSString *houseNumberMin;
/** The result house number max. Optional field.*/
@property (nonatomic, retain) NSString *houseNumberMax;

/**
 * Creates a new reverse geocode result instance.
 * @return The new instance.
 */
- (id) init;

/**
 * Adds a postcode.
 * Adds a postcode.
 * @param postcode The postcode to add.
 */
- (void) addPostcode:(NSString *)postcode;

/**
 * Returns all the postcodes.
 * Returns an array of postcodes (NSString objects).
 * @return An array of postcodes (NSString objects).
 */
- (NSArray *) getPostcodes;

@end

/**
 * Represent a reverse geocode response.
 * This contains the data sent by the LBS server for a reverse geocode request.
 */
@interface TTAPIReverseGeocodeData : TTAPIBaseData {
	@private
	NSString *version;
	NSMutableArray *reverseGeoResults;
}

/** The response version.*/
@property (nonatomic, retain) NSString *version;

/**
 * Creates a new reverse geocode response instance.
 * @return The new instance
 */
- (id) init;

/**
 * Adds a reverse geocode result.
 * Adds a reverse geocode result to the response object. A query might return one or more reverse geo result 
 * entries.
 * @param reverseGeoResult The result to add.
 */
- (void) addReverseGeoResult:(TTAPIReverseGeoResult *)reverseGeoResult;

/**
 * Returns all the reverse geo results.
 * Returns an array of TTAPIReverseGeoResult objects.
 * @return An array of TTAPIReverseGeoResult objects.
 */
- (NSArray *) getReverseGeoResults;

@end
