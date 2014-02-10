//
//  RMTileCache.h
//
// Copyright (c) 2008-2009, Route-Me Contributors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#import <Foundation/Foundation.h>
#import "RMTile.h"
#import "RMTileSource.h"
#import "RMMapContents.h"

@class RMTileImage;

typedef enum {
	RMCachePurgeStrategyLRU,
	RMCachePurgeStrategyFIFO,
} RMCachePurgeStrategy;


@protocol RMTileCache<NSObject>

/// Returns the cached image if it exists. nil otherwise.
-(RMTileImage*) cachedImage:(RMTile)tile;
/// Returns the cached image if the source is a Memory cache and if the image exists on the cache. nil otherwise.
-(RMTileImage*) cachedImageFromMemoryCache:(RMTile)tile;
/// Updates the image on the tile passed by parameter if the source is a Database cache and if the image exists on the cache. Returns nil otherwise.
-(RMTileImage*) cachedImageFromDataBaseCache:(RMTileImage*)tileImage;
-(void)didReceiveMemoryWarning;

@optional

-(void)addTile: (RMTile)tile WithImage: (RMTileImage*)image;
/// removes all tile images from the memory and disk subcaches
-(void)removeAllCachedImages;
// This will copy all the memory(fast) cache images to the DB cache.
// In case the DB cache is disabled, the user can use this when closing the app.
-(void)dumpFastCacheToDB;
// The list of all the tiles in a Cache
-(NSEnumerator *) getEnumerator;
// add the Tile to the DB cache directly;
-(void) addTileDirectToDB:(RMTileImage *)image;
@end


@interface RMTileCache : NSObject<RMTileCache>
{
	NSMutableArray *caches;
	@protected
	RMMapContents *contents;
}

@property (nonatomic, retain) RMMapContents *contents;

-(id)initWithTileSource: (id<RMTileSource>) tileSource andMapContents: (RMMapContents*) contents;

+(NSNumber*) tileHash: (RMTile)tile;

/// Add tile to cache
/*! 
 \bug Calls -makeSpaceInCache for every tile/image addition. -makeSpaceInCache does a linear scan of its contents at each call.

 \bug Since RMTileImage has an RMTile ivar, this API should be simplified to just -addImage:.
 */
-(void)addTile: (RMTile)tile WithImage: (RMTileImage*)image;

/// Add another cache to the chain
-(void)addCache: (id<RMTileCache>)cache;

-(void)didReceiveMemoryWarning;

@end
