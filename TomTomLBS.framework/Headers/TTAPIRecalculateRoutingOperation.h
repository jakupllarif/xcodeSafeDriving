//
//  @(#)TTAPIRecalculateRoutingOperation.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIBaseRoutingOperation.h"

/**
 * The recalculate route operation.
 * Called to recalculate a given route (previously obtained using, for example, the route operation).
 */
@interface TTAPIRecalculateRoutingOperation : TTAPIBaseRoutingOperation {

}

/**
 * Creates a new TTAPIRecalculateRoutingOperation instance.
 * Shortcut for the main init method initWithQuery: andOptionalParameters:.
 * @param routeId The route id of the route to be recalculated.
 * @param optional The optional parameters serialized in the format: ";paramA;paramB".
 * @return The new instance.
 */
- (id) initWithRouteId:(NSString *)routeId andOptionalParameters:(NSString*)optional;

@end
