//
//  @(#)TTAPIGeocodeData.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIBaseData.h"


/**
 * Represents a geo code result entry.
 */
@interface TTAPIGeoResult : NSObject {
	@private
	NSNumber* latitude;
	NSNumber* longitude;
	NSString *geohash;
	NSString *mapName;
	NSString *name;
	NSString *category;
	NSString *phone;
	NSString *url;
	NSString *type;
	NSString *houseNumber;
	NSString *street;
	NSString *district;
	NSString *city;
	NSString *state;
	NSString *postcode;
	NSString *country;
	NSString *countryISO3;
	NSString *formattedAddress;
	NSNumber* widthMeters;
	NSNumber* heightMeters;
	NSNumber* score;
	NSString *defaultLanguage;
	NSString *languages;
	NSString *mapVersion;
}
/** The result latitude. */
@property (nonatomic, retain) NSNumber* latitude;
/** The result longitude. */
@property (nonatomic, retain) NSNumber* longitude;
/** The result geohash. Optional field. */
@property (nonatomic, retain) NSString *geohash;
/** The result map name. Optional field. */
@property (nonatomic, retain) NSString *mapName;
/** The result name. Optional field. */
@property (nonatomic, retain) NSString *name;
/** The result category. Optional field. */
@property (nonatomic, retain) NSString *category;
/** The result phone. Optional field. */
@property (nonatomic, retain) NSString *phone;
/** The result URL. Optional field. */
@property (nonatomic, retain) NSString *url;
/** The result type. Optional field. */
@property (nonatomic, retain) NSString *type;
/** The result house number. Optional field. */
@property (nonatomic, retain) NSString *houseNumber;
/** The result street. Optional field. */
@property (nonatomic, retain) NSString *street;
/** The result district. Optional field. */
@property (nonatomic, retain) NSString *district;
/** The result city. Optional field. */
@property (nonatomic, retain) NSString *city;
/** The result state. Optional field. */
@property (nonatomic, retain) NSString *state;
/** The result postcode. Optional field. */
@property (nonatomic, retain) NSString *postcode;
/** The result country. */
@property (nonatomic, retain) NSString *country;
/** The result country in ISO3. */
@property (nonatomic, retain) NSString *countryISO3;
/** The result formatted address. */
@property (nonatomic, retain) NSString *formattedAddress;
/** The result width in meters. */
@property (nonatomic, retain) NSNumber* widthMeters;
/** The result height in meters. */
@property (nonatomic, retain) NSNumber* heightMeters;
/** The result score. */
@property (nonatomic, retain) NSNumber* score;
/** The result default language. */
@property (nonatomic, retain) NSString *defaultLanguage;
/** The result languages. Optional field. */
@property (nonatomic, retain) NSString *languages;
/** The result map version. */
@property (nonatomic, retain) NSString *mapVersion;

@end

/**
 * Represent a geocode response.
 * This contains the data sent by the LBS server for a geocode request.
 */
@interface TTAPIGeocodeData : TTAPIBaseData {
	@private
	NSString *version;
	NSInteger count;
	NSMutableArray *geoResults;
}

/** The geocode version. */
@property (nonatomic, retain) NSString *version;
/** The geocode count. */
@property (nonatomic, assign) NSInteger count;

/**
 * Creates a new geocode response instance.
 * @return The new instance.
 */
- (id) init;

/**
 * Adds a geocode result.
 * Adds a geocode result to the response object. A query might return several geo result entries.
 * @param geoResult The result to add.
 */
- (void) addGeoResult:(TTAPIGeoResult *)geoResult;

/**
 * Returns all the geo results.
 * Returns an array of TTAPIGeoResult objects.
 * @return An array of TTAPIGeoResult objects.
 */
- (NSArray *) getGeoResults;

@end
