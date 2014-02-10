//
//  @(#)TTAPITileSourceInteger.h 10/05/28
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIGenericTileSource.h"
#import "TTSDKContext.h"
/**
 * LBS Integer specific tile source object.
 * Represents a specific tile source object that fetches data from TomTom's Integer API.
 */
@interface TTAPITileSourceInteger : TTAPIGenericTileSource<TTAPIGenericTileSource> {
    NSString *cachedParameters;
    NSString *tileStyle;
}
@property (nonatomic, retain) NSString *cachedParameters;
@property (nonatomic, retain) NSString *tileStyle;
@end
