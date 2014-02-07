//
//  @(#)TTAPIRoutingOperation.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIBaseRoutingOperation.h"
#import "TTAPIRouting.h"

@class TTAPIRoutingData;
@class TTCoordinates;

/**
 * The route operation.
 * Called to obtain the directions from a starting point to an end point.
 */
@interface TTAPIRoutingOperation : TTAPIBaseRoutingOperation {

}

/**
 * Creates a new TTAPIRoutingOperation instance.
 * Creates a new TTAPIRoutingOperation instance for a given query and options.
 * @param startPoint The start coordinates.
 * @param endPoint The end coordinates.
 * @param routeType The route type as defined by the RouteType enum.
 * @param optional The optional parameters.
 * @return The new instance.
 */
- (id) initWithStartPoint:(TTCoordinates*)startPoint AndEndPoint:(TTCoordinates*)endPoint 
                            AndRouteType:(TTRouteType)routeType andOptionalParameters:(NSString*)optional;

@end
