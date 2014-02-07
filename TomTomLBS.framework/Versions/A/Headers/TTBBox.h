//
//  @(#)TTBBox.h 10/06/09
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIGenericTileSource.h"

/**
 * A bounding box. 
 * Contains the coordinates of the south/west and north/east corners of the box.
 * These relate to minimum and maximum x and y coordinates.
 * Latitudes correspond to the  YY axis when using pixels. Longitudes correspond to the XX axis when using pixels.
 * It is up to the user to chose what she needs and know what is the format of the points in each instance.
 * This class also handles the conversion between coordinates and pixels, considering a zoom level.
 */
@interface TTBBox : NSObject {

@private
    NSNumber* latitudeSouth;
    NSNumber* latitudeNorth;
    NSNumber* longitudeWest;
    NSNumber* longitudeEast;
}

/**
 * South most latitude of the bounding box.
 */
@property (nonatomic, retain, readonly) NSNumber* latitudeSouth;
/**
 * North most latitude of the bounding box.
 */
@property (nonatomic, retain, readonly) NSNumber* latitudeNorth;
/**
 * West most longitude of the bounding box.
 */
@property (nonatomic, retain, readonly) NSNumber* longitudeWest;
/**
 * East most longitude of the bounding box.
 */
@property (nonatomic, retain, readonly) NSNumber* longitudeEast;

/**
 * Inititalizes the Bounding Box using a set of coordinates.
 * Inititalizes the Bounding Box using a set of coordinates.
 * @param ls The latitude south.
 * @param ln The latitude north.
 * @param lw The longitude west.
 * @param le The longitude east.
 * @return The initialized bounding box.
 **/
-(id) initWithLatitudeSouth:(NSNumber*)ls latitudeNorth:(NSNumber*) ln longitudeWest:(NSNumber*) lw longitudeEast:(NSNumber*) le;

/**
 * Inititalizes the Bounding Box using a CGXYRect.
 * @param rect Rectangle representing the bounding box.
 * @return The initialized bounding box.
 **/
-(id) initWithRect: (CGXYRect) rect;

/**
 * Creates a bounding box using a set of coordinates.
 * Creates a bounding box using a set of coordinates.
 * @param ls The latitude south.
 * @param ln The latitude north.
 * @param lw The longitude west.
 * @param le The longitude east.
 * @return The bounding box.
 */
+(TTBBox *) boxWithLatitudeSouth:(NSNumber*)ls latitudeNorth:(NSNumber*) ln longitudeWest:(NSNumber*) lw longitudeEast:(NSNumber*) le;

@end
