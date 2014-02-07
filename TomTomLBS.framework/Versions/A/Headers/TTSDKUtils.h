//
//  @(#)TTSDKUtils.h 10/05/26
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <CoreLocation/CoreLocation.h>
#import <CoreGraphics/CoreGraphics.h>


@class TTBBox;


/*
 * Defines the TTProjection for API calls.
 * See TTProjection_toString for a way to convert into NSString*
 */
typedef enum {
	TTProjectionEPSG4326,
	TTProjectionEPSG900913
} TTProjection;

/**
 * Convers a TTProjection into its String equivalent
 */
__attribute__((visibility("default")))NSString * const TTProjection_toString[2];

__attribute__((visibility("default")))double const MinXYMeters;

__attribute__((visibility("default")))double const MaxXYMeters;

__attribute__((visibility("default")))double const WorldWidthMeter;

__attribute__((visibility("default")))int const TileWidthPixels;

__attribute__((visibility("default")))int const ZoomLevels;

__attribute__((visibility("default")))int const DefaultMaxZoomLevel;

__attribute__((visibility("default")))int const DefaultMinZoomLevel;

/*
 * Defines the TTLayerType for API tile requests.
 * See TTLayerType_toString for a way to convert into NSString*
 */
typedef enum {
	TTLayerTypeBasic,
	TTLayerTypeTraffic,
	TTLayerTypeCanvas
} TTLayerType;

/**
 * Convers a TTLayerType into its String equivalent
 */
__attribute__((visibility("default")))NSString * const TTLayerType_toString[3];

/*
 * Defines the TTImageFormat for API tile requests.
 * See TTImageFormat_toString for a way to convert into NSString*
 */
typedef enum {
	TTImageFormatPNG,
	TTImageFormatGIF
} TTImageFormat;

/**
 * Convers a TTImageFormat into its String equivalent
 */
__attribute__((visibility("default")))NSString * const TTImageFormat_toString[2];

/**
 * Coordinates class. Composed of latitude and longitude.
 */
@interface TTCoordinates : NSObject {
@private
	NSNumber* latitude;
	NSNumber* longitude;
}

/** Latitude of the coordinate */
@property (nonatomic, retain) NSNumber* latitude;
/** Longitude of the coordinate */
@property (nonatomic, retain) NSNumber* longitude;

/**
 * Initializes a coordinate object with a latitude and a longitude
 * @param lat Latitude of the coordiante.
 * @param lon Longitude of the coordinate.
 * @return The initialized coordinate object.
 */
-(id) initWithLatitude:(NSNumber*)lat andLongitude:(NSNumber*)lon;

@end

/**
 * Point structure. Composed of x and y in pixels.
 */
@interface TTPoint : NSObject {
	NSNumber* x;
	NSNumber* y;
}

@property (nonatomic, retain) NSNumber* x;
@property (nonatomic, retain) NSNumber* y;

/**
 * Initializes a point object with an x and y values.
 * @param anX X value of the point.
 * @param anY Y value of the point
 * @return The initialized point object.
 */
-(id) initWithX:(NSNumber*)anX andY:(NSNumber*)anY;

/**
 * Initializes a point object with an x and y values.
 * @param anX X value of the point.
 * @param anY Y value of the point
 * @return The initialized point object.
 */
+(id) pointWithX:(NSNumber*)anX andY:(NSNumber*)anY;

@end

@interface TTRect : NSObject
{
	TTPoint *origin;
	NSNumber* height;
	NSNumber* width;
}

@property (nonatomic, retain) TTPoint* origin;
@property (nonatomic, retain) NSNumber* height;
@property (nonatomic, retain) NSNumber* width;


@end


/**
 * Class to contain util static methods.
 */
@interface TTSDKUtils : NSObject {
	
}

/**
 * Calculate the zoom level in which the bounding box is totally visible.
 * Calculate the zoom level in which the bounding box is totally visible assuming the screen will be centered in the center 
 * of the bounding box. Starts calculation at the highest zoom level.
 * @param bbox The bounding box that is to be visible.
 * @param rect CGRect representing the portion of the map view that is visible by the user.
 * @return The zoom level that should be used to view the entire bounding box in the screen, assuming the screen is centered in
 * the center of the bounding box.
 */
+ (NSInteger) calculateZoomLevelForBoundingBox: (TTBBox*) bbox 
									   forRect: (CGRect) rect;

/**
 * Calculate the zoom level in which the bounding box is totally visible.
 * Calculate the zoom level in which the bounding box is totally visible.
 * @param bbox The bounding box that is to be visible.
 * @param rect CGRect representing the portion of the map view that is visible by the user.
 * @param center Point in which the map should be centered when showing the bounding box. If nil, it will be ignored and the
 * method will just return the zoom level in which the bounding box is fully visible considering its center. If defined, the 
 * defined center point will be taken into consideration and the zoom level returned can be lower than the one needed to 
 * simply display the entire bounding box.
 * @return The zoom level that should be used to view the entire bounding box in the screen.
 */
+ (NSInteger) calculateZoomLevelForBoundingBox: (TTBBox*) bbox 
									   forRect: (CGRect) rect 
									centeredAt: (TTCoordinates*) center;
@end

/**
 * Enumeration for the souce tile types.
 */
enum TTMapLayerType {
	/* The Map Tile Source. */
	TTMapLayerType_MapTileSource = 0,
	/* The Traffic Tile Source. */
	TTMapLayerType_TrafficTileSource = 1,
	/* The Routing Tile Source. */
	TTMapLayerType_RouteTileSource = 2,
    /* The 3rd party Tile Source */
    TTMapLayerType_OtherTileSource = 3
};
typedef NSUInteger TTMapLayerType;

/**
 * Enumeration for the souce types. 
 * Different from TTMapLayerType because it distinguishes between Integer and WMS source type.
 */
enum TTTileSourceType {
#ifdef WMS_API
	/* The Wms Tile Source. */
	TTTileSourceType_Wms = 0,
#endif
	/* The Integer Tile Source. */
	TTTileSourceType_Integer = 1,
	/* The Community Tile Source. */
	TTTileSourceType_Community = 2
};
typedef NSUInteger TTTileSourceType;


/**
 * Enumeration for the cache purging strategy.
 */
enum TTCachePurgeStrategy {
	/* Last Recently Used strategy. */
	TTCachePurgeStrategyLRU = 0,
	/* First In First Out strategy. */
	TTCachePurgeStrategyFIFO = 1
};
typedef NSUInteger TTCachePurgeStrategy;

/**
 * A coordinate representation in degrees, minutes and seconds format.
 */
typedef struct {
	NSInteger degrees;
	NSInteger minutes;
	NSInteger seconds;
} CLLocationCoordinateDMS;

/**
 * The latitude and longitude coordinate DMS representation.
 */
typedef struct {
	CLLocationCoordinateDMS latitude;
	CLLocationCoordinateDMS longitude;
} CLLocationCoordinate2DDMS;

/**
 * Converts from degree, minutes, second coordinates to decimal degrees coordinates.
 * Converts from degree, minutes, second coordinates to decimal degrees coordinates.
 * @param dms The coordinates in degrees, minutes and seconds.
 * @return The coordinates converted to decimal degrees.
 */
CLLocationCoordinate2D dmsToDecimalDegrees(CLLocationCoordinate2DDMS dms);

/**
 * Converts from decimal degrees coordinates to degree, minutes, second coordinates.
 * Converts from decimal degrees coordinates to degree, minutes, second coordinates.
 * @param dd The coordinates in decimal degrees.
 * @return The coordinates converted to degrees, minutes and seconds.
 */
CLLocationCoordinate2DDMS decimalDegreesToDms(CLLocationCoordinate2D dd);

/**
 * Converts from meters coordinates to decimal degrees coordinates.
 * Converts XY point from Spherical Mercator EPSG:3857 to lat/lon in WGS84 Datum.
 * @param meters The coordinates in meters.
 * @return The coordinates converted to decimal degrees.
 */
CLLocationCoordinate2D metersToDecimalDegrees(CGPoint meters);

/**
 * Converts from decimal degrees to meters coordinates.
 * Converts given lat/lon in WGS84 Datum to XY in Spherical Mercator EPSG:3857.
 * @param dd The coordinates in decimal degrees.
 * @return The coordinates converted to meters.
 */
CGPoint decimalDegreesToMeters(CLLocationCoordinate2D dd);

/**
 * Converts meters into a corresponding (x,y) tile for the given zoom level.
 * Since there is no direct correspondency between a tile's (x,y) coordinates and geo meters, the tile 
 * returned will be the tile (for the given zoom level) that contains the geo point location. The upper left corner of 
 * the tile may not correspond to the geo location passed as parameter.
 * @param meters Geo meters of the intended location.
 * @param zoom Zoom level for which the tile (x,y) should be calculated.
 * @return The CGPoint corresponding to the (x,y) coordinates of the tile.
 */
CGPoint metersToTileXy (CGPoint meters, int zoom);


/**
 * @return offset between 0 and 1 for each coordinate, inside the tile to which the point in meters belongs to.
 */
CGPoint offsetOfPointInTile (CGPoint point, int zoom);

__attribute__((visibility("default")))NSString * const MapCacheKey;

/**
 * SDK Notifications
 */
extern NSString * const TTSDKTrafficModelIdChangedNotification;