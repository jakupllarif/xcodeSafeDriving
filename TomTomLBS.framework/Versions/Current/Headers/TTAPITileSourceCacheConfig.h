//
//  @(#)TTAPITileSourceCacheConfig.h 10/07/19
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "RMTileSourceCacheConfig.h"
#import "TTSDKUtils.h"

@interface TTAPITileSourceCacheConfig : NSObject {

	@private
	RMTileSourceCacheConfig *_impl;
	
}

/**
 * Inits and returns a cache source configuration object.
 * The elements of the caps array will have a direct corespondency to the elements of the types array.
 * @param cacheK Cached key to be used to uniquely identify the caches that are being initialized.
 * @param caps Capacities to be used by the caches that will be created with the tile source.
 * @param types Types of caches to be used by the tile sources. The only possible values are 'memory-cache' and 'db-cache'.
 * @return Returns the new cache configuration object.
 */
- (id) initwithCacheKey: (NSString *) cacheK andCapacities: (NSMutableArray*) caps andTypes: (NSMutableArray*) types;

/**
 * Getter method for the capacities of the cache configuration object.
 * @return Array with the capacities of the cache configuration object.
 */ 
- (NSMutableArray*) getCapacities;

/**
 * Setter method for the capacities of the cache configuration object.
 * @param cap Array with capacities for the cache configuration object.
 */ 
- (void) setCapacities: (NSMutableArray*) cap;

/**
 * Getter method for the types of the cache configuration object.
 * @return Array with the types of the cache configuration object.
 */ 
- (NSMutableArray*) getCacheTypes;

/**
 * Setter method for the types of the cache configuration object.
 * @param types Array with types for the cache configuration object.
 */ 
- (void) setCacheTypes: (NSMutableArray*) types;

/**
 * Getter method for the cache key of the cache configuration object.
 * @return Cache key.
 */ 
- (NSString*) getCacheKey;

/**
 * Setter method for the cache key of the cache configuration object.
 * @param key Key for the cache configuration object.
 */ 
- (void) setCacheKey: (NSString*) key;

/**
 * Getter method for the implementation object of the cache configuration object.
 * @return The implementation object of the cache configuration object.
 */
- (id) getCacheConfigurationImpl;

/**
 * Setter method for the purging strategy of the database cache of the cache configuration object.
 * @param strat Purging strategy of the database cache of the cache configuration object.
 */ 
- (void) setPurgingStrategy: (TTCachePurgeStrategy) strat;

/**
 * Getter method for the purging strategy of the cache configuration object used for the database cache.
 * @return The purging strategy used in the database cache of the cache configuration object.
 */ 
- (TTCachePurgeStrategy) getPurgingStrategy;

@end
