//
//  @(#)TTAPIInitializeOperation.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIOperation.h"

@class TTAPIInitializeData;

/**
 * The initialize operation.
 * The operation calls the initialize service to make the initialize request before any map location or viewport description 
 * call.
 */
@interface TTAPIInitializeOperation : TTAPIOperation {

}

/**
 * Returns the same as the super -(NSObject *)data method.
 * This is basically a helper method to avoid doing casts.
 * @return The parsed data.
 */
- (TTAPIInitializeData *) data;

@end
