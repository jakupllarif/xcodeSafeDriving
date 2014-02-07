//
//  @(#)RMTileSourceCacheConfig.h 10/07/19
//  
//  MapView
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "RMTileCache.h"

@interface RMTileSourceCacheConfig : NSObject {
	@private
	NSString *cacheKey;
	NSMutableArray *capacities;
	NSMutableArray *cacheTypes;
	RMCachePurgeStrategy strategy;
}
@property(nonatomic, retain) NSString *cacheKey;
@property(nonatomic, retain) NSMutableArray *capacities;
@property(nonatomic, retain) NSMutableArray *cacheTypes;
@property(nonatomic, assign) RMCachePurgeStrategy strategy;
@end
