//
//  @(#)TTAPIRoutingDelegate.h 10/05/31
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <UIKit/UIKit.h>
@class TTAPIRoutingData;

/**
 * The Routing API delegate.
 */
@protocol TTAPIRoutingDelegate

/**
 * Handles a route response. 
 * This delegate is normally called after a route asynchronous request.
 * @param route The route response.
 * @param payload Object passed from the caller that is returned to allow data passing during assynchronous calls.
 */
-(void) handleRoute:(TTAPIRoutingData *)route withPayload:(id)payload;

/**
 * Handles a route recalculation response. 
 * This delegate is normally called after a route recalculation asynchronous request.
 * @param route The recalculated route response.
 * @param payload Object passed from the caller that is returned to allow data passing during assynchronous calls.
 
-(void) handleRecalculatedRoute:(TTAPIRoutingData *)route withPayload:(id)payload;*/
@end
