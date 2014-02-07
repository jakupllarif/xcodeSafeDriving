//
//  RMCachedTileSource.h
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

#import <UIKit/UIKit.h>
#import "RMTileSource.h"
#import "RMMapContents.h"

@class RMTileCache;
@class RMTileImageSet;

/// Simple wrapper around a tilesource which checks the image cache first.
@interface RMCachedTileSource : NSObject<RMTileSource, RMTileSourceDelegate>
{
	id <RMTileSource> tileSource;
	RMTileCache *cache;
	
	NSString* memCacheKey; 
    
    
    NSOperationQueue* operationQueue;
    long maxScreenRefreshCounter;
    /** 
     * Counts the number of operations inside the queue or still working. Cannot use operationCount from the queue 
     * because it is only available from iOS 4
     */
    NSUInteger opCounter;
	
    RMTileImageSet* parentImageSet;
	
	@private
	RMMapContents *contents;
}


@property (nonatomic, retain) NSString* memCacheKey; 
@property (nonatomic, retain) RMTileImageSet* parentImageSet;
@property (nonatomic, assign) long maxScreenRefreshCounter;
@property (readonly) id<RMTileSource> tileSource;
@property (nonatomic, retain) RMMapContents *contents;

- (id) initWithSource: (id<RMTileSource>) source andMapContents: (RMMapContents*) contents;
- (void) didReceiveMemoryWarning;

/// Bleah ugly name.
+ (RMCachedTileSource*) cachedTileSourceWithSource: (id<RMTileSource>) source andMapContents: (RMMapContents*) _contents;

- (id<RMTileSource>) underlyingTileSource;

-(NSString *) tileURL: (RMTile) tile;
-(NSString *) tileFile: (RMTile) tile;
-(NSString *) tilePath;

-(NSString *)shortName;
-(NSString *)longDescription;
-(NSString *)shortAttribution;
-(NSString *)longAttribution;

-(void)dumpFastCacheToDB;

/**
 * Operations must call this to decrement the operations counter
 */
-(void) notifyOperationDoneForScreenRefreshCounter:(long)screenRefreshCounter;

-(BOOL) canLoadTilesForScreenRefreshCounter:(long)refreshCounter;

/**
 * Gets a tile from a slow source - DB cache
 * @param tileImage the tile to fill with the image from cache
 * @return nil if the the tile is not cached, the same tileImage received by parameter with the image set, if the image is cached.
 */
-(RMTileImage *) updateTileImageFromSlowCache:(RMTileImage*)tileImage;

/**
 * Gets a tile from the source - WEB
 * @param tileImage the tile to fill with the image from cache
 * @return nil if the the tile cannot be retrieved, the same tileImage received by parameter with the image set, if the image can be retrieved
 */
-(RMTileImage *) updateTileImageFromSource:(RMTileImage*)tileImage;

/**
 * Checks if the current cache still has ongoing operations
 */
- (BOOL) operationsFinished;

/**
 * Removes any circular dependencies that would otherwise cause dealloc not to be called.
 **/
- (void) prepareToDealloc;

@end
