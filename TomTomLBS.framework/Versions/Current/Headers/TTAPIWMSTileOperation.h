//
//  @(#)TTAPIWMSTileOperation.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIOperation.h"
#import "TTSDKUtils.h"
@class TTBBox;
@class TTAPIWMSTileData;

/**
 * The WMS tile operation.
 * The operation calls the WMS service in order to obtain a tile.
 */
@interface TTAPIWMSTileOperation : TTAPIOperation {

}

/**
 * Creates a new TTAPIWMSTileOperation instance.
 * Creates a new TTAPIWMSTileOperation instance for a given set of parameters.
 * @param type The tile type.
 * @param format The tile image format (png or gif)
 * @param bbox The bounding box.
 * @param options The optional parameters query. Supports nil, meaning no optional parameters.
 * @return The new instance.
 */
-(id) initWithLayerType:(TTLayerType)type format:(TTImageFormat)format boundingBox:(TTBBox*)bbox optional:(NSString*)options;

/**
 * Returns the same as the super -(NSObject *)data method.
 * This is basically a helper method to avoid doing casts.
 * @return The parsed data.
 */
- (TTAPIWMSTileData *) data;
@end
