//
//  @(#)TTAPITileMosaicOperation.h 10/08/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTSDKUtils.h"
#import "TTAPIOperation.h"
@class TTAPIOperation;
@class TTAPITileData;
@class TTAPIRoutingData;

/**
 * The Tile Mosaic operation.
 * The operation calls either the WMS or Integer tile service to obtain 4 tiles and form an image. The image
 * is created based on the passed coordinates (that will define the center point) and zoom level.
 */
@interface TTAPITileMosaicOperation : TTAPIOperation {
	@private
	TTCoordinates * coordinates;
	NSInteger zoomLevel;
	TTLayerType type;
	TTTileSourceType sourceType;
	TTImageFormat format;
	TTAPIRoutingData * routingData;
	NSString * optionalParameters;
}

/**
 * Creates a new TTAPITileMosaicOperation instance.
 * Creates a new TTAPITileMosaicOperation instance for a given set of parameters.
 * @param aCoordinates The center coordinates.
 * @param aZoomLevel The zoom level.
 * @param aType The layer type (basic, traffic or route).
 * @param aSourceType The source (WMS or Integer).
 * @param aFormat The format (png or gif)
 * @param aRoutingData The routing data. Supports nil, meaning no optional parameters.
 * @param optns The extra options. An example would be the output of the stringValue method of a 
 * TTAPIWMSTileOptionalParameters object.Supports nil, meaning no optional parameters.
 * @return The new instance.
 */
- (id)initWithPoint:(TTCoordinates *)aCoordinates 
		 zoomeLevel:(NSInteger)aZoomLevel 
		  layerType:(TTLayerType)aType 
		 sourceType:(TTTileSourceType)aSourceType
			 format:(TTImageFormat)aFormat
		routingData:(TTAPIRoutingData*)aRoutingData 
andOptionalParameters:(NSString *)optns;

/**
 * Returns the same as the super -(NSObject *)data method.
 * This is basically a helper method to avoid doing casts.
 * @return The parsed data.
 */
- (TTAPITileData *) data;

@end
