//
//  @(#)TTAPILBSInfoDelegate.h 10/05/31
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <UIKit/UIKit.h>
@class TTAPIInitializeData;
@class TTAPIViewportDescriptionData;

/**
 * The LBS Info API delegate.
 */
@protocol TTAPILBSInfoDelegate
/**
 * Handles an initialize response. 
 * This delegate is normally called after an initialize asynchronous request.
 * @param init The initialize response.
 * @param payload Object passed from the caller that is returned to allow data passing during assynchronous calls.
 */
-(void) handleInitialize:(TTAPIInitializeData *)init withPayload:(id)payload;

/**
 * Handles a viewport description response. 
 * This delegate is normally called after a viewport description asynchronous request.
 * @param viewport The viewport description response.
 * @param payload Object passed from the caller that is returned to allow data passing during assynchronous calls.
 */
-(void) handleViewportDescription:(TTAPIViewportDescriptionData *)viewport withPayload:(id)payload;
@end
