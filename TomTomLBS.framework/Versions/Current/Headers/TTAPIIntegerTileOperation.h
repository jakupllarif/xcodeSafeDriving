//
//  @(#)TTAPIIntegerTileOperation.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIOperation.h"
#import "TTSDKUtils.h"
@class TTAPIIntegerTileData;

/**
 * The Integer tile operation.
 * The operation calls the Integer service in order to obtain a tile.
 */
@interface TTAPIIntegerTileOperation : TTAPIOperation {

}

/**
 * Creates a new TTAPIIntegerTileOperation instance.
 * Creates a new TTAPIIntegerTileOperation instance for a given set of parameters.
 * @param type The tile type.
 * @param x The x point for the tile.
 * @param y The y point for the tile.
 * @param zoom The zoom level for the tile.
 * @param options The optional parameters query. Supports nil, meaning no optional parameters.
 * @return The new instance.
 */
-(id) initWithLayerType:(TTLayerType)type x:(NSInteger)x y:(NSInteger)y zoom:(NSInteger)zoom optional:(NSString*)options;

/**
 * Returns the same as the super -(NSObject *)data method.
 * This is basically a helper method to avoid doing casts.
 * @return The parsed data.
 */
- (TTAPIIntegerTileData *) data;

@end
