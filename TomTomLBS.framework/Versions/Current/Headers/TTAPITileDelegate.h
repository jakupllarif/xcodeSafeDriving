//
//  @(#)TTAPITileDelegate.h 10/05/31
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <UIKit/UIKit.h>
@class TTAPIWMSTileData;
@class TTAPIIntegerTileData;

/**
 * The tile API delegate.
 */
@protocol TTAPITileDelegate

/**
 * Handles a WMS tile response. 
 * This delegate is normally called after a WMS tile asynchronous request.
 * @param tile The tile response.
 * @param payload Object passed from the caller that is returned to allow data passing during assynchronous calls.
 */
-(void) handleWMSTile:(TTAPIWMSTileData *)tile withPayload:(id)payload;

/**
 * Handles an integer tile response. 
 * This delegate is normally called after an integer tile asynchronous request.
 * @param tile The tile response.
 * @param payload Object passed from the caller that is returned to allow data passing during assynchronous calls.
 */
-(void) handleIntegerTile:(TTAPIIntegerTileData *)tile withPayload:(id)payload;

@end
