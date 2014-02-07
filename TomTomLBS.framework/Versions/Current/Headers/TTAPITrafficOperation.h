//
//  @(#)TTAPITrafficOperation.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIOperation.h"

@class TTAPITrafficData;
@class TTBBox;

/**
 * The traffic operation.
 * Called to obtain the traffic for a given area.
 */
@interface TTAPITrafficOperation : TTAPIOperation {

}

#ifdef DEVPORTAL
/**
* Creates a new instance.
* Creates a new instance for a given query and options.
* @param geoExtent The geoExtent to use. In projected coordinates, which are comma-separated (minY,minX,maxY,maxX).
* @param zoom The zoom level.
* @param trafficModelId Number which references a traffic model.
* @param optional The optional parameters.
* @return The new instance.
*/
- (id) initWithGeoExtent:(TTBBox*)geoExtent zoomLevel:(NSInteger)zoom 
          trafficModelId:(NSNumber *)trafficModelId optionalParameters:(NSString*)optional;
#else

/**
 * Creates a new instance.
 * Creates a new instance for a given query and options.
 * @param geoExtent The geoExtent to use. In projected coordinates, which are comma-separated (minY,minX,maxY,maxX).
 * @param zoom The zoom level.
 * @param pixelExtent Pixel coordinates, which are comma-separated (minY,minX,maxY,maxX).
 * @param trafficModelId Number which references a traffic model.
 * @param optional The optional parameters.
 * @return The new instance.
 */
- (id) initWithGeoExtent:(TTBBox*)geoExtent zoomLevel:(NSInteger)zoom pixelExtent:(TTBBox*)pixelExtent 
	   trafficModelId:(NSNumber *)trafficModelId optionalParameters:(NSString*)optional;
 
#endif

/**
 * Returns the same as the super -(NSObject *)data method.
 * This is basically a helper method to avoid doing casts.
 * @return The parsed data.
 */
- (TTAPITrafficData *) data;

@end
