//
//  @(#)TTAPIBaseRoutingOperation.h 10/06/09
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIOperation.h"

@class TTAPIRoutingData;

/**
 * Base class for the routing related operations.
 * Contains common code and cannot be instantiated.
 */
@interface TTAPIBaseRoutingOperation : TTAPIOperation {

}

/**
 * Returns the same as the super -(NSObject *)data method.
 * This is basically a helper method to avoid doing casts.
 * @return The parsed data.
 */
- (TTAPIRoutingData *) data;

@end
