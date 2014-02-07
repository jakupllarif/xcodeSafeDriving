//
//  @(#)TTAAPIRouteTileSourceWms.h 10/06/17
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPITileSourceWms.h"
#import "TTSDKContext.h"
#import "TTAPIRoutingData.h"


@interface TTAPIRouteTileSourceWms : TTAPITileSourceWms {
	NSString *routeKey;
	/* Bounding boxes of the route for the several levels, should be set in tile x,y */
	CGRect routeBboxes[18];
}
@property (nonatomic, readonly) NSString *routeKey;

/**
 * TTAPIRouteTileSourceWms constructor class. 
 * @param baseUrl Base URL to be used to download the tiles of the source.
 * @param parameters Extra parameters to be added to the URL of the source.
 * @param routingData Information regarding the route that the source will be downloading. Requires the bounding box of the route
 * and the route key to be defined.
 * @return The new TTAPIRouteTileSourceWms object.
 */
- (id) initWithBaseUrl:(NSString *)baseUrl parameters:(NSDictionary *)params andRoutingData: (TTAPIRoutingData*) routingData;

@end
