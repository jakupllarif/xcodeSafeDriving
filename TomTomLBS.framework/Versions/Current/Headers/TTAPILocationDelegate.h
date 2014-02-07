//
//  @(#)TTAPILocationDelegate.h 10/05/31
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <UIKit/UIKit.h>
@class TTAPIGeocodeData;
@class TTAPIReverseGeocodeData;

/**
 * The location API delegate.
 */
@protocol TTAPILocationDelegate

/**
 * Handles a geocode response. 
 * This delegate is normally called after a geocode asynchronous request.
 * @param geocode The geocode response.
 * @param payload Object passed from the caller that is returned to allow data passing during assynchronous calls.
 */
-(void) handleGeocode:(TTAPIGeocodeData *)geocode withPayload:(id)payload;

/**
 * Handles a reverse geocode response. 
 * This delegate is normally called after a reverse geocode asynchronous request.
 * @param reverseGeocode The reverse geocode response.
 * @param payload Object passed from the caller that is returned to allow data passing during assynchronous calls.
 */
-(void) handleReverseGeocode:(TTAPIReverseGeocodeData *)reverseGeocode withPayload:(id)payload;
@end

