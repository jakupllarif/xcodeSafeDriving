//
//  @(#)TTAPIViewportDescriptionOperation.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIOperation.h"

@class TTAPIViewportDescriptionData;

/**
 * The viewport description operation.
 * The operation calls the service in order to obtain the viewport description.
 */
@interface TTAPIViewportDescriptionOperation : TTAPIOperation {

}

/**
 * Returns the same as the super -(NSObject *)data method.
 * This is basically a helper method to avoid doing casts.
 * @return The parsed data.
 */
- (TTAPIViewportDescriptionData *) data;

@end
