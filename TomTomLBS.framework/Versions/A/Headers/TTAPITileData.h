//
//  @(#)TTAPITileData.h 10/08/09
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIBaseData.h"


/**
 * Represent a tile.
 */
@interface TTAPITileData : TTAPIBaseData {
@private
	NSData * tile;
}

/** The tile image data. */
@property (nonatomic, retain) NSData * tile;

@end
