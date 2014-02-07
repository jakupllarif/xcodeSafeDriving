//
//  @(#)TTAPITileSourceWms.h 10/05/28
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import "TTAPIGenericTileSource.h"



/**
 * LBS WMS specific tile source object.
 * Represents a specific tile source object that fetches data from TomTom's WMS API.
 */
@interface TTAPITileSourceWms : TTAPIGenericTileSource<TTAPIGenericTileSource> {
	
}
//CGFloat DegreesToRadians(CGFloat degrees) ; 
//CGFloat RadiansToDegrees(CGFloat radians) ; 

@end
