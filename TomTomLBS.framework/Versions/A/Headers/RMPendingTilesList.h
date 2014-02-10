//
//  RMPendingTilesList.h
//  MapView
//
//  Created by Ian Maia on 4/26/11.
//  Copyright 2011 TomTom Places. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RMTile.h"


@interface RMPendingTilesList : NSObject {
    
}

+ (RMPendingTilesList*) sharedInstance;
- (void) addPendingTileInList:(RMTile *)tile;
- (BOOL) isTileInPendingList:(RMTile *)tile;
- (void) removePendingTileFromList:(RMTile *)tile;


@end
