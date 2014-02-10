//
//  @(#)TTAPITrafficDelegate.h 10/06/08
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>

@class TTAPITrafficData;


/**
 * The Traffic API delegate.
 */
@protocol TTAPITrafficDelegate

/**
 * Handles a traffic response. 
 * This delegate is normally called after a traffic asynchronous request.
 * @param model The traffic response.
 * @param payload Object passed from the caller that is returned to allow data passing during assynchronous calls.
 */
-(void) handleTraffic:(TTAPITrafficData *)model withPayload:(id)payload;

@end
