//
//  @(#)TTAPIRouteTileSourceInteger.h 10/09/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPITileSourceInteger.h"
#import "TTAPIRoutingData.h"

/**
 * Integer specific tile source object.
 * Represents a specific route tile source object that fetches data from TomTom's Integer API.
 */
@interface TTAPIRouteTileSourceInteger : TTAPITileSourceInteger {
	CGRect routeBboxes[18];
}

/**
 * TTAPIRouteTileSourceInteger constructor class. 
 * @param baseUrl Base URL to be used to download the tiles of the source.
 * @param parameters Extra parameters to be added to the URL of the source.
 * @param routingData Information regarding the route that the source will be downloading. Requires the bounding box of the route
 * and the route key to be defined.
 * @return The new TTAPIRouteTileSourceInteger object.
 */
- (id) initWithBaseUrl:(NSString *)baseUrl parameters:(NSDictionary *)params andRoutingData: (TTAPIRoutingData*) routingData;

@end
