//
//  @(#)TTAPIGenericTileSource.h 10/05/28
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "RMLatLong.h"
#import "RMFractalTileProjection.h"
#import "RMAbstractMercatorWebSource.h"
#import "TTSDKUtils.h"
#import "TTAPITileSourceCacheConfig.h"
#import "TTUIMarker.h"

extern NSString * const TILES_SERVER_WMS;
extern NSString * const TILES_SERVER_INTEGER;

/**
 * Point defined using raw double type.
 */
typedef struct { 
	double x; 
	double y;
} CGDoublePoint; 

/**
 * A rectangle defined by a upper left point and a lower right point.
 */
typedef struct { 
	CGDoublePoint ul; 
	CGDoublePoint lr;
} CGXYRect; 


/**
 * Protocol that defines a generic tile source.
 */
@protocol TTAPIGenericTileSource

/**
 * Inits a source tile class with URL and params.
 * This method receives the base URL from which the SDK should be getting the tile images along with parameters 
 * that should be general to all calls. Specific parameters for each call should be passed with the tileUrl method.
 * @param baseUrl The base URL from where the SDK gets the tile images.
 * @param params Generic parameters that the class will use to initialize the object. Should be general for 
 * all calls to the base URL.
 * @return The generic tile source that is used throughout the SDK.
 */
- (id)initWithBaseUrl:(NSString *)baseUrl parameters:(NSDictionary *)params;
@end



/**
 * The generic tile source.
 * This class will be used for interactions with the information for the tile sources. 
 * Classes that represent source information from which to retrieve tiles should always extend this class.
 */
@interface TTAPIGenericTileSource : RMAbstractMercatorWebSource  {
	NSMutableDictionary *wmsParameters;
	NSString *urlTemplate;
	double initialResolution, originShift;
	TTMapLayerType type;
	NSString* typeStr;
	
	TTAPITileSourceCacheConfig *cacheConfiguration;

	NSInteger maxLoadingZoom;
	NSInteger minLoadingZoom;
	NSMutableDictionary* extraParams;
    
    NSMutableArray *markers;
    BOOL    areMarkersVisible;
    id parentViewController; //normally a TTUIMapViewController
    long ID;
    
	@protected
	NSInteger subDomainIndex;
	NSInteger subDomainIndexMaxValue;
	NSInteger maxConcurrentOperations;
	

}


@property (nonatomic, retain) NSString *urlTemplate;
@property (nonatomic, assign) TTMapLayerType type;
@property (nonatomic, retain) NSString* typeStr;
@property (nonatomic, retain) TTAPITileSourceCacheConfig *cacheConfiguration;

@property (nonatomic, assign) NSInteger maxLoadingZoom;
@property (nonatomic, assign) NSInteger minLoadingZoom;
@property (nonatomic, assign) NSInteger maxConcurrentOperations;

@property (nonatomic, retain) NSMutableArray *markers;
@property (nonatomic, assign) BOOL areMarkersVisible;
@property (nonatomic, retain) id parentViewController;
@property (nonatomic, assign) long ID;

/**
 * Resolution (meters/pixel) for given zoom level (measured at Equator).
 * @param zoom Zoom for which the method should calculate the resolution.
 * @return Resolution at the zoom level passed by parameter.
 */
- (NSNumber*)ResolutionAtZoom:(NSInteger)zoom;


/**
 * Returns bounds of the given tile in EPSG:3857 coordinates.
 * @param tile Tile for which the bounds will be calculated.
 * @return A rectangle representing the bounds of the tile.
 */
- (CGXYRect)TileBounds:(RMTile)tile;

/**
 * Enable or Disable network operations on this Tile Source.
 * used for layers that have only markers, for example.
 */
- (void) setNetworkOperations: (BOOL) enable;

/**
 * Lets the SDK know if it should create a new tiles set when loading a new screen.
 * @param create If set to NO the SDK will not create a new tiles set when loading a new screen.
 */
- (void) setCreateNewTileListOnLoad: (BOOL) create;

/**
 * Returns a BOOL indicating if the SDK is creating a new tiles set when loading a new screen.
 * @return Returns YES if the SDK is create a new tiles set when loading a new screen.
 */
- (BOOL) getCreateNewTileListOnLoad;

/**
 * Lets the SDK know if it should clear all tiles outside the screen when the screen is loaded.
 * @param clear If set to YES the SDK clear all tiles outside the screen when the screen is loaded
 */
- (void) setClearAllTilesOutsideScreenOnLoad: (BOOL) clear;

/**
 * Returns a BOOL indicating if the SDK is clearing all tiles outside the screen when the screen is loaded
 * @return Returns YES if the SDK clear all tiles outside the screen when the screen is loaded.
 */
- (BOOL) getClearAllTilesOutsideScreenOnLoad;

/**
 * Lets the SDK know if it should clear tiles below a loaded tile after it is loaded.
 * @param clear If set to NO the SDK will not clear tiles below a loaded tile after it is loaded.
 */
- (void) setClearPyramidBelowAfterLoad: (BOOL) clear;

/**
 * Returns a BOOL indicating if the SDK is clearing tiles below a loaded tile after it is loaded.
 * @return Returns YES if the SDK is clearing tiles below a loaded tile after it is loaded.
 */
- (BOOL) getClearPyramidBelowAfterLoad;

/**
 * Lets the SDK know if it should clear tiles outside the bounding box after loading.
 * @param clear If set to NO the SDK will not clear tiles outside the bounding box after loading.
 */
- (void) setClearOutsideBboxAfterLoad: (BOOL) clear;

/**
 * Returns a BOOL indicating if the SDK is clearing tiles outside the bounding box after loading a new screen.
 * @return Returns YES if the SDK is clearing tiles outside the bounding box after loading a new screen.
 */
- (BOOL) getClearOutsideBboxAfterLoad;

/**
 * Lets the SDK know if it should perform the outbounds pyramid cleaning before loading.
 * @param clear If set to NO the SDK will not perform the outbounds pyramid cleaning before loading.
 */
- (void) setPerformOutbondPyramidCleaningOnLoad: (BOOL) clear;

/**
 * Returns a BOOL indicating if the SDK is performing the outbounds pyramid cleaning before loading.
 * @return Returns YES if the SDK is performing the outbounds pyramid cleaning before loading.
 */
- (BOOL) getPerformOutbondPyramidCleaningOnLoad;

/**
 * Allows the developer to define if the tile source should display an error image when the 
 * connection to fetch a tile fails. The error image will be the one defined with the name "error_tile.png".
 * @param allow Set to true if the SDK should display the error image when a connection failure occurs.
 */
- (void) setAllowDisplayErrorTile: (BOOL) allow;

/**
 * Returns true of the SKD is displaying an error image when a connection failure 
 * occurs for the tile source, returns false if otherwise.
 * @return BOOL indicating if the SDK is display the error image.
 */
- (BOOL) getAllowDisplayErrorTile;

/**
 * Sets an extra parameter and its value.
 * Valid params are "r" for the route key and "i" for the instruction ID in the case of the integer tile source and "ROUTEKEY" 
 * for the route key and "i" for the instruction ID in the case of the WMS tile source.
 * TODO Create more complete support for all parameters
 * To clear pass a nil value
 * @param key the key
 * @param the value. Pass a nil to clear the key from the dictionary.
 */
-(void) setExtraParam:(NSString*)key withValue:(NSString*)value;

/**
 * Joins the params that have been set and returns a string with them. If the generic implementation is invoked an empty string is returned.
 * TODO make the extra parameters a bean
 * @return A string with the params with a format appropriate for the specific source.
 */
- (NSString*) getExtraParamsString;


/**
 * Add a marker to this Tile Source.
 */
- (void) addMarker:(TTUIMarker*)marker;

/**
 * Remove a marker from the list
 * return TRUE is the marker existed and it was deleted. NO if ther marker was not in the list, so nothing was done.
 */
- (BOOL) removeMarker: (TTUIMarker*)marker;

/**
 * Remove all markers from the list
 */
- (void) removeAllMarkers;

/**
 * Enable/Disable the visibility of the markers.
 */
- (void) setMarkersVisible:(BOOL) visible;

/**
 * Sync will synchronize the visible ( or invisible ) markers with the MapViewController
 * Markers.
 */
- (void) syncMarkers;

@end
