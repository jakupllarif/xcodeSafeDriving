//
//  @(#)RMWebTileLoaderOperation.h 10/07/27
//  
//  MapView
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "RMTile.h"
#import "RMConfiguration.h"

@class RMCachedTileSource;
@class RMTileImage;

@interface RMWebTileLoaderOperation : NSOperation {
    /** Parent queue */
    RMCachedTileSource* operationQueue;
    NSMutableArray* tileImages;
}

/**
 * Creates a new operation for loading a tile.
 * @param theTileImage the tile to fetch. Parameter is retained until the operation finishes.
 * @param queue the parent of the operation queue, controlling the operations. Parameter is retained until the operation finishes.
 * @return the new operation
 */
-(id) initWithTileList:(NSMutableArray*)list andQueue:(RMCachedTileSource*)queue;

-(void) cancelForbiddenLoading;

@end
