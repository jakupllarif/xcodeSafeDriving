//
//  RMTileSource.h
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
#import <UIKit/UIKit.h>
#import "RMTile.h"
#import "RMLatLong.h"
#import "RMFoundation.h"

@class RMTileImage;
@class RMFractalTileProjection;
@class RMTileLoader;
@class RMTiledLayerController;
@class RMTileCache;
@protocol RMMercatorToTileProjection;
@class RMProjection;
@class RMTileImageSet;

@protocol RMTileSourceDelegate

- (void) tileSourceWillReset;
- (void) tileSourceDidReset;

@end


// TODO make this an abstract(ish) interface to allow better reuse and having instance variables
@protocol RMTileSource <NSObject>

/**
 * Gets a new tileImage or updates the one passed by parameter with an image.
 * @param tileImage the tile to update or to use as template, according to the situation.
 * @return nil if the tile couldn't be found or updated. A new tile or the one passed by parameter.
 */
-(RMTileImage*) updateTileImage:(RMTileImage*)tileImage;
-(NSMutableArray*) updateTileImages:(NSMutableArray*)tileImages;

/**
 * Gets a tile from a fast source - Memory cache
 * @param tileImage the tile information
 * @return nil if the the tile is not cached, a tile from the memory cache if the tile is found
 */
-(RMTileImage *) getTileImageFromFastCache:(RMTileImage*)tileImage;

-(NSString *) tileURL: (RMTile) tile;
-(NSString *) tileFile: (RMTile) tile;
-(NSString *) tilePath;
-(id<RMMercatorToTileProjection>) mercatorToTileProjection;
-(RMProjection*) projection;

-(float) minZoom;
-(float) maxZoom;

-(void) setMinZoom:(NSUInteger) aMinZoom;
-(void) setMaxZoom:(NSUInteger) aMaxZoom;

-(RMSphericalTrapezium) latitudeLongitudeBoundingBox;

-(void) didReceiveMemoryWarning;

-(NSString *)uniqueTilecacheKey;

-(NSString *)shortName;
-(NSString *)longDescription;
-(NSString *)shortAttribution;
-(NSString *)longAttribution;

/*! \brief clear all images from the in-memory and on-disk image caches
 \bug This method belongs on RMCachedTileSource, not on RMTileSource, because an RMTileSource doesn't have a cache.
 */
-(void)removeAllCachedImages;

-(void)dumpFastCacheToDB;

-(UIImage*) getTopZoomLevelDefaultTile:(RMTile)tile;

- (RMTileRect) normalizeBoundingBox: (RMTileRect) bbox; 

@required
- (id) getCacheConfiguration;
- (NSString*) getMemCacheKey;
- (void) setMemCacheKey: (NSString*) newCacheKey;
-(void) setParentImageSet:(RMTileImageSet*)parentImageSet;
- (NSInteger) getMaxConcurrentOperations;

/**
 * Lets the SDK know if it should create a new tiles set when loading a new screen.
 * @param create If set to NO the SDK will not create a new tiles set when loading a new screen.
 */
- (void) setCreateNewTileListOnLoad: (BOOL) create;

/**
 * Returns a BOOL indicating if the SDK is creating a new tiles set when loading a new screen.
 * @return Returns YES if the SDK is create a new tiles set when loading a new screen.
 */
- (BOOL) getCreateNewTileListOnLoad;

/**
 * Lets the SDK know if it should clear all tiles outside the screen when the screen is loaded.
 * @param clear If set to YES the SDK clear all tiles outside the screen when the screen is loaded
 */
- (void) setClearAllTilesOutsideScreenOnLoad: (BOOL) clear;

/**
 * Returns a BOOL indicating if the SDK is clearing all tiles outside the screen when the screen is loaded
 * @return Returns YES if the SDK clear all tiles outside the screen when the screen is loaded.
 */
- (BOOL) getClearAllTilesOutsideScreenOnLoad;

/**
 * Lets the SDK know if it should clear tiles below a loaded tile after it is loaded.
 * @param clear If set to NO the SDK will not clear tiles below a loaded tile after it is loaded.
 */
- (void) setClearPyramidBelowAfterLoad: (BOOL) clear;

/**
 * Returns a BOOL indicating if the SDK is clearing tiles below a loaded tile after it is loaded.
 * @return Returns YES if the SDK is clearing tiles below a loaded tile after it is loaded.
 */
- (BOOL) getClearPyramidBelowAfterLoad;

/**
 * Lets the SDK know if it should clear tiles outside the bounding box after loading.
 * @param clear If set to NO the SDK will not clear tiles outside the bounding box after loading.
 */
- (void) setClearOutsideBboxAfterLoad: (BOOL) clear;

/**
 * Returns a BOOL indicating if the SDK is clearing tiles outside the bounding box after loading a new screen.
 * @return Returns YES if the SDK is clearing tiles outside the bounding box after loading a new screen.
 */
- (BOOL) getClearOutsideBboxAfterLoad;

/**
 * Lets the SDK know if it should perform the outbounds pyramid cleaning before loading.
 * @param clear If set to NO the SDK will not perform the outbounds pyramid cleaning before loading.
 */
- (void) setPerformOutbondPyramidCleaningOnLoad: (BOOL) clear;

/**
 * Returns a BOOL indicating if the SDK is performing the outbounds pyramid cleaning before loading.
 * @return Returns YES if the SDK is performing the outbounds pyramid cleaning before loading.
 */
- (BOOL) getPerformOutbondPyramidCleaningOnLoad;

/**
 * Allows the developer to define if the tile source should display an error image when the 
 * connection to fetch a tile fails. The error image will be the one defined with the name "error_tile.png".
 * @param allow Set to true if the SDK should display the error image when a connection failure occurs.
 */
- (void) setAllowDisplayErrorTile: (BOOL) allow;

/**
 * Returns true of the SKD is displaying an error image when a connection failure 
 * occurs for the tile source, returns false if otherwise.
 * @return BOOL indicating if the SDK is display the error image.
 */
- (BOOL) getAllowDisplayErrorTile;

/**
 * Resets the caching of the souce tile, removing from cache all the tile images that were saved. 
 */
- (void) reset;

- (void) setDelegate:(id<RMTileSourceDelegate>)delegate;

- (void) setName:(NSString*)name;
- (NSString*) name;
@end
