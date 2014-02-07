//
//  RMMercatorWebSource.h
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
#import "RMTileSource.h"
#import "RMTileLoaderDelegate.h"
#import "RMFractalTileProjection.h"

#pragma mark --- begin constants ---
#define kTileLoadingRetries 2
#define kDefaultTileSize 256
#define kDefaultMinTileZoom 0
#define kDefaultMaxTileZoom 18
#define kDefaultLatLonBoundingBox ((RMSphericalTrapezium){.northeast = {.latitude = 90, .longitude = 180}, .southwest = {.latitude = -90, .longitude = -180}})
#pragma mark --- end constants ---

@class RMTileImageSet;
@class NTReachability;

@protocol RMAbstractMercatorWebSource

-(NSString*) tileURL: (RMTile) tile;

@end

@interface RMAbstractMercatorWebSource : NSObject <RMTileSource> {
	RMFractalTileProjection *tileProjection;
	BOOL networkOperations;
	
	@private	
	NSString* memCacheKey;
    
    /** Route-me will clear all items outside the screen after the screen is loaded  **/
    BOOL clearOutsideBboxAfterLoad;
    /**  Route-me will attempt to clear all tiles being blocked (or potentially blocking) a tile when it is loaded **/
    BOOL clearPyramidBelowAfterLoad;
    /** Clears all tiles from the screen before loading a new screen. Similar behaviour to the one route-me used to have. **/
    BOOL clearAllTilesOutsideScreenOnLoad;
    /** Route-me will perform the outbound 3D pyramid clean up before loading a new screen 
     (can be overriden by createNewTileListOnLoad) **/
    BOOL performOutbondPyramidCleaningOnLoad;
    /** Route-me will create a new tiles set list when loading a new screen. Similar effect to clearAllTilesOutsideScreenOnLoad **/
    BOOL createNewTileListOnLoad;
    /** If the source can display an error tile when the tile isn't loaded from the network by some reason. */
	BOOL allowDisplayErrorTile;
    RMTileImageSet* parentImageSet;
    id<RMTileSourceDelegate, NSObject> delegate;
    NSString* name;
}

@property (nonatomic, retain) RMFractalTileProjection *tileProjection;
@property (nonatomic, retain) RMTileImageSet* parentImageSet;
@property (nonatomic, retain) id<RMTileSourceDelegate> delegate;
@property (nonatomic, retain) NSString* name;

-(id) init;

-(void) networkOperationsNotification: (NSNotification*) notification;

-(int) tileSideLength;
-(void) setTileSideLength: (NSUInteger) aTileSideLength;

-(float) minZoom;
-(float) maxZoom;

-(RMSphericalTrapezium) latitudeLongitudeBoundingBox;

-(NSString *)shortName;
-(NSString *)longDescription;
-(NSString *)shortAttribution;
-(NSString *)longAttribution;


@end
