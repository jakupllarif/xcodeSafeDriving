//
//  @(#)TTAPITileSourceFactory.h 10/05/28
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIGenericTileSource.h"
#import "TTAPITileSourceWms.h"
#import "TTAPITileSourceInteger.h"
#import "TTSDKUtils.h"
#import "TTSDKContext.h"
#import "TTAPIRouteTileSourceWms.h"
/**
 * The source tile factory.
 * This class encapsulates the creation of the source tile objects, hiding it from the rest of the SDK code.
 * A generic tile source object is always returned.
 */
@interface TTAPITileSourceFactory : NSObject {
	
}

/**
 * Get a WMS Map Tile Source.
 * @return Generic tile source of WMS Map tiles.
 */
+ (TTAPIGenericTileSource*) getWmsMapTileSource __attribute__((deprecated));

/**
 * Get a WMS Map Route Source.
 * @param route Route data to be used in the source url to fetch the correct route. Needs to contain the route key and the route's
 * bounding box.
 * @return Generic tile source of WMS Route tiles.
 */
+ (TTAPIGenericTileSource*) getWmsRouteTileSource: (TTAPIRoutingData*) route __attribute__((deprecated));

/**
 * Get a WMS Map Traffic Source.
 * @return Generic tile source of WMS Traffic tiles.
 */
+ (TTAPIGenericTileSource*) getWmsTrafficTileSource __attribute__((deprecated));

/**
 * Get an Integer Map Tile Source.
 * @return Generic tile source of Integer Map tiles.
 */
+ (TTAPIGenericTileSource*) getIntegerBasicMapTileSource;

/**
 * Get an Integer Traffic Tile Source.
 * @return Generic tile source of Integer traffic tiles.
 */
+ (TTAPIGenericTileSource*) getIntegerTrafficTileSource;

/**
 * Get a Integer Community Map Tile Source.
 * @return Generic tile source of Integer Community Map tiles.
 */
+ (TTAPIGenericTileSource*) getIntegerCommunityMapTileSource;

/**
 * Get an Integer Route tiles
 * @return Generic tile source of Integer API route tiles.
 */
+ (TTAPIGenericTileSource*) getIntegerRouteTileSource: (TTAPIRoutingData*) route;

/**
 * Get a Generic Layer with a name
 */
+ (TTAPIGenericTileSource*) getBasicLayerWithName: (NSString*)name;

@end
