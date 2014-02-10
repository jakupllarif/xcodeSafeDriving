//
//  @(#)TTUIMapViewController.h 10/05/24
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TTBBox.h"
#import "RMMarkerManager.h"
#import "RMMapViewDelegate.h"
#import "TTUIMapTouchInterceptorDelegate.h"
#import "TTUIMarker.h"
#import "TTAPIGenericTileSource.h"
#import "TTAPIBaseData.h"
#import "TTAPITileDelegate.h"
#import "TTSDKUtils.h"

@class TTUIMapView;
@class TTUIMarker;
@class TTAPIMapViewDelegate;

/**
 * The map delegate. Defines a set of notifications that a map can send.
 */
@protocol TTUIMapDelegate

@optional

/**
 * This is called before the map is moved.
 * This is called before the map is moved.
 * @param bbox The current screen bounding box.
 * @param zoomLevel The current zoom level.
 */
-(void) beforeMapMoved:(TTBBox *)bbox zoomLevel:(NSInteger)zoomLevel;

/**
 * This is called when the map is moving.
 * This is called when the map is moving.
 */
-(void) mapMoving;

/**
 * This is called after the map is moved.
 * This is called after the map is moved.
 * @param newBbox The new screen bounding box.
 * @param zoomLevel The current zoom level.
 */
-(void) afterMapMoved:(TTBBox *)newBbox zoomLevel:(NSInteger)zoomLevel;

/**
 * This is called before the map is zoomed.
 * This is called before the map is zoomed.
 * @param bbox The current screen bounding box.
 * @param zoomLevel The current zoom level.
 */
-(void) beforeMapZoomed:(TTBBox *)bbox zoomLevel:(NSInteger)zoomLevel;

/**
 * This is called when the map is zooming.
 * This is called when the map is zooming.
 */
-(void) mapZooming;

/**
 * This is called after the map is zoomed.
 * This is called after the map is zoomed.
 * @param newBbox The new screen bounding box.
 * @param newZoomLevel The new zoom level.
 */
-(void) afterMapZoomed:(TTBBox *)newBbox zoomLevel:(NSInteger)newZoomLevel;

/**
 * A marker was added to the map.
 * A marker was added to the map.
 * @param marker The added marker.
 */
-(void) markerAddedToMap:(TTUIMarker *)marker;

/**
 * A marker was removed from the map.
 * A marker was removed from the map.
 * @param marker The removed marker.
 */
-(void) markerRemovedFromMap:(TTUIMarker *)marker;

//-(void) didDragMarker:(TTUIMarker *)marker;


///**
// * Called before a marker is tapped.
// * Called before a marker is tapped.
// * @param marker The marker that will be papped.
// */
//-(void) beforeMarkerTapped:(TTUIMarker *)marker;

/**
 * A marker was tapped.
 * A marker was tapped.
 * @param marker The tapped marker.
 */
-(void) markerTapped:(TTUIMarker *)marker;

/**
 * A marker enters the map visible bounding box.
 * A marker enters the map visible bounding box
 * NOT YET IMPLEMENTED.
 * @param marker The visible marker.
 */
-(void) markerDisplayed:(TTUIMarker *)marker;

/**
 * A marker leaves the map visible bounding box.
 * A marker leaves the map visible bounding box
 * NOT YET IMPLEMENTED.
 * @param marker The hidden marker.
 */
-(void) markerHidden:(TTUIMarker *)marker;

/**
 * Double tap on the map.
 * Double tap on the map.
 * @param tapPoint Where the tap happened in latitude and longitude.
 */
-(void) doubleTap:(TTCoordinates *) tapPoint;


/**
 * This is called after the map is rotated
 * @param New Rotation Angle
 */
-(void) mapRotated:(float)angle;

/**
 * Informs the controller delegate that a layer will now be loaded.
 * @param source Source of the layer to be loaded.
 * @param bbox Bounding box that will be loaded in x,y tiles.
 * @param zoom Zoom level used for the load process.
 * @return If the return is NO, the load of the map will be cancelled. If it is YES the load will continue.
 */
- (BOOL) mapLayerWillLoad: (id<RMTileSource>) source withBoundingBox: (TTBBox*) bbox andZoomLevel: (NSInteger) zoom;

/**
 * Informs the controller delegate that a layer finished loading.
 * @param source Source of the layer to be loaded.
 */
- (void) mapLayerDidLoad: (TTAPIGenericTileSource*) source;

/**
 * Informs the controller delegate that the loading of images will now be suppressed.
 * @return If the return is NO, the suppressing of loads will be cancelled. If it is YES the suppressing will continue.
 */
- (BOOL) willSuppressScreenRefreshing;

/**
 * Informs the controller delegate that the loading of images will now be resumed.
 * @return If the return is NO, the SDK will not resume the loading of images. 
 * If it is YES the SDK will resume the loading of images.
 */
- (BOOL) willResumeScreenRefreshing;

@end

/**
 * The map view controller.
 * This class will allow us to control a map view that can be obtain by calling the instance method "view".
 */
@interface TTUIMapViewController : NSObject {
	@private
	TTUIMapView *_view;
	id<TTUIMapDelegate> delegate;
	NSMutableArray *sources;
	
	TTAPIGenericTileSource* defaultMapTileSource;
}

/**
 * The marker delegate.
 * The delegate that will receive notifications for when a marker gets added, removed, tapped, displayed and hidden.
 */
@property (nonatomic, retain) id<TTUIMapDelegate> delegate;

@property (nonatomic, retain) TTAPIGenericTileSource* defaultMapTileSource;

/**
 * Creates a controller instance.
 * @return The initialiazed object.
 */
- (id) init;

/**
 * Creates a controller instance.
 * @param frame Frame that defines the size of the map.
 * @return The initialiazed object.
 */
- (id) initWithFrame: (CGRect) frame;

/**
 * Creates a controller instance.
 * @param frame Frame that defines the size of the map.
 * @param maxConc Maximum number of concurrent operations for the initial map view layer.
 * @return The initialiazed object.
 */
- (id) initWithFrame: (CGRect) frame andInitialMaxConcurrentOperations: (NSInteger) maxConc;

/**
 * Returns the touch interceptor delegate.
 * Returns the touch interceptor delegate. Please see TTUIMapTouchInterceptorDelegate for more details on the touch 
 * interceptor delegate.
 * @return The touch interceptor delegate or nil if not set.
 */
- (id<TTUIMapTouchInterceptorDelegate>)touchInterceptorDelegate;

/**
 * Sets the touch interceptor delegate.
 * Sets the touch interceptor delegate. Please see TTUIMapTouchInterceptorDelegate for more details on the touch 
 * interceptor delegate.
 * @param interceptor The touch interceptor delegate.
 */
- (void) setTouchInterceptorDelegate:(id<TTUIMapTouchInterceptorDelegate>)interceptor;

/**
 * Returns the map view.
 * Returns the map view that can be placed on a cocoa touch container component, like a window or other view.
 * @return The map view.
 */
- (UIView *) view;

/**
 * Move the map by a delta of pixels.
 */
-(void)moveBy: (CGSize)delta;

/**
 * Center the map on a given latitude and longitude.
 * @param latitude The designated latitude.
 * @param longitude The designated longitude.
 */
- (void) centerOnLatitude:(NSNumber*)latitude andLongitude:(NSNumber*)longitude;

/**
 * Center the map on a given latitude and longitude and zoom to the specified level.
 * @param latitude The designated latitude.
 * @param longitude The designated longitude.
 * @param aZoomLevel The desired zoom level.
 */
- (void) centerOnLatitude:(NSNumber*)latitude andLongitude:(NSNumber*)longitude withZoomLevel:(NSInteger)aZoomLevel;

/**
 * Center the map on a given point and zoom to the specified level.
 * @param newZoomLevel The desired zoom level. 
 * @param pivot The new center point of the map view.
 */
- (void) zoomToLevel:(NSInteger)newZoomLevel near: (CGPoint) pivot;

/**
 * Zoom the map to the specified level.
 * @param newZoomLevel The desired zoom level.
 */
- (void) zoomToLevel:(NSInteger)newZoomLevel;

/**
 * Zooms the map in.
 * The zoom is calculated by incrementing the current level in one level. Zoom will be near the map center.
 * @return The new zoom level.
 */
- (NSInteger) zoomIn;

/**
 * Zooms the map in.
 * The zoom is calculated by incrementing the current level in one level. Zoom will be near the map center.
 * @param animated True if the zoom in is expected to be animated.
 * @return The new zoom level.
 */
- (NSInteger) zoomIn:(BOOL)animated;

/**
 * Zooms the map in.
 * The zoom is calculated by incrementing the current level in one level.
 * @param pivot Point of the zoom, it can be the center of the touch or the center of the map.
 * @return The new zoom level.
 */
- (NSInteger) zoomInOnPoint:(CGPoint)pivot;

/**
 * Zooms the map in.
 * The zoom is calculated by incrementing the current level in one level.
 * @param pivot Point of the zoom, it can be the center of the touch or the center of the map.
 * @param animated True if the zoom in is expected to be animated.
 * @return The new zoom level.
 */
- (NSInteger) zoomInOnPoint:(CGPoint)pivot withAnimation:(BOOL)animated;

/**
 * Zooms the map out.
 * The zoom is calculated by decrementing the current level in one level. Zoom will be near the map center.
 * @return The new zoom level.
 */
- (NSInteger) zoomOut;

/**
 * Zooms the map out.
 * The zoom is calculated by decrementing the current level in one level. Zoom will be near the map center.
 * @param animated True if the zoom out is expected to be animated.
 * @return The new zoom level.
 */
- (NSInteger) zoomOut:(BOOL)animated;

/**
 * Zooms the map out.
 * The zoom is calculated by decrementing the current level in one level.
 * @param pivot Point of the zoom, it can be the center of the touch or the center of the map.
 * @return The new zoom level.
 */
- (NSInteger) zoomOutOnPoint:(CGPoint)pivot;

/**
 * Zooms the map out.
 * The zoom is calculated by decrementing the current level in one level.
 * @param pivot Point of the zoom, it can be the center of the touch or the center of the map.
 * @param animated True if the zoom out is expected to be animated.
 * @return The new zoom level.
 */
- (NSInteger) zoomOutOnPoint:(CGPoint)pivot withAnimation:(BOOL)animated;

/**
 * Adds a marker to the map at the location specified in the marker's coordinates attribute.
 * The marker is retained to assure that the reference isn't lost.
 * @param marker The marker to add.
 */
- (void) addMarker:(TTUIMarker *)marker;

/**
 * Adds an array of markers to the map at the locations specified in the markers' coordinates attribute.
 * @param markers The array of markers.
 */
- (void) addMarkers:(NSArray *)markers;

/**
 * Moves a marker to a new position.
 * Moves a marker to a new position specified by latitude and longitude.
 * @param marker The marker to move.
 * @param coordinates The new position.
 */
- (void) moveMarker:(TTUIMarker *)marker toCoordinates:(TTCoordinates*)coordinates ;

/**
 * Removes a marker from the map.
 * @param marker The marker to remove.
 */
- (void) removeMarker:(TTUIMarker *)marker;

/**
 * Removes an array of markers from the map.
 * @param markers The array of markers to remove.
 */
- (void) removeMarkers:(NSArray *)markers;

/**
 *Removes all markers that don't have the type passed as parameter.
 *@param type Type of the markers that will remain in the map view.
 */
- (void) removeMarkersWithTypeDifferent: (TTUIMarkerType) type;

/**
 * Removes all markers from the map.
 */
- (void) removeAllMarkers;

/**
 * Removes all the markers from the map that have a specific type.
 * @param type The type of the markers that will be removed from the map.
 */
- (void) removeAllMarkersWithType: (TTUIMarkerType) type;

/**
 * Removes all the markers from the map that have a specific parent ID.
 * @param parent The ID of the markers that will be removed from the map.
 */
- (void) removeAllMarkersWithParentID: (long)parent;

/**
 * Removes all the markers from the map that have a specific type but none of the types of the template marker.
 * @param type The type of the markers to remove
 * @param templateMarker A marker with the exact types of the marker we don't want to remove
 */
- (void) removeAllMarkersWithType:(TTUIMarkerType)type andNoneOf:(TTUIMarker*)templateMarker;

/**
 * Finds the first marker of the passed type.
 * @param type The TTUIMarkerType of marker to find
 * @return The first marker of the correct type that is found or nil if none is found.
 */
- (TTUIMarker*) findMarkerOfType:(TTUIMarkerType)type;

/**
 * Finds all markers of the passed type.
 * @param type The TTUIMarkerType of the markers to find.
 * @return An array of markers witht he type passed as argument or an empty array if none is found.
 */
- (NSArray *) findMarkersOfType:(TTUIMarkerType)type;

/**
 * Finds the first marker of the TTUIMarkerType_CurrentLocation type.
 * @return the first marker of the TTUIMarkerType_CurrentLocation type that is found or nil if none is found.
 */
- (TTUIMarker*) findCurrentLocationPin;

/**
 * Finds the first marker of the TTUIMarkerType_RouteStart type.
 * @return the first marker of the TTUIMarkerType_RouteStart type that is found or nil if none is found.
 */
- (TTUIMarker*) findStartPin;

/**
 * Finds the first marker of the TTUIMarkerType_RouteEnd type.
 * @return the first marker of the TTUIMarkerType_RouteEnd type that is found or nil if none is found.
 */
- (TTUIMarker*) findEndPin;

/**
 * Get marker.
 * Gets the markers currently being displayed by the application.
 * @return List of markers.
 */
- (NSMutableArray *) getMarkers;

/**
 * Get zoom level. 
 * Returns the current zoom level the application is using.
 * @return Current zoom level.
 */
- (NSInteger) getZoomLevel;

/**
 * Determines if a marker is visible in the screen.
 * @param marker The marker that will be tested for presence in the screen.
 * @return True if the marker is visible, false if it is not.
 */
- (BOOL)isMarkerWithinScreenBounds: (TTUIMarker*) marker;

/**
 * Hides all the markers currently being shown in the map.
 */
- (void) hideMarkers;

/**
 * Shows all the markers currently set by the developer.
 */
- (void) showMarkers;

/**
 * Returns the minimum zoom of the SDK
 * @return The minimum zoom of the SDK
 */
- (NSInteger) getMinZoom;

/**
 * Returns the maximum zoom of the SDK
 * @return The maximum zoom of the SDK
 */
- (NSInteger) getMaxZoom;

/**
 * Suppresses further loading of tiles.
 * If set to YES, prevents the SDK from loading image tiles while the map is being 
 * moved or zoomed.
 * @param suppress Indicates whether the SDK should prevent loading of new tiles or not.
 */
- (void) suppressLoading:(BOOL) suppress;


/**
 * Hides a layer.
 * If set to true, the received layer won't be displayed but it will remain in memory.
 * @param hidden If the layer should be hidden.
 * @param source The source object reference that should be hidden or visible.
 */
- (void) setLayerHidden:(BOOL)hidden withSource: (TTAPIGenericTileSource*) source ;

/**
 * Add a layer to the map view.
 * Adds the specified source to the last position of the layers array.
 * @param source The source object reference that should be added to the map view.
 */
- (void) addLayer: (TTAPIGenericTileSource*) source;

/**
 * Add a layer to the map view in the specified index location.
 * Add a layer to the map view in the specified index location. If the index is greater than the total amount of sources already 
 * in the map view, the source will be added in the last position of the array, preventing empty indexes in the array.
 * @param source The source object reference that should be added to the map view.
 * @param index Index where the new source should be added in the map view.
 */
- (void) addLayer: (TTAPIGenericTileSource*) source atIndex: (NSInteger) index;


/**
 * Add a vector path based layer ( like a route or a path )
 * 
 */
- (void) addVectorBasedLayer: (id)layer;

/**
 * Remove the specified layer from the map.
 */
- (void) removeVectorBasedLayer: (id)layer;

/**
 * Removes the specied source from the map view.
 * @param source The source object reference that should be removed from the map view.
 */
- (void) removeLayer: (TTAPIGenericTileSource*) source;

/**
 * Removes the source present in the specified index.
 * @param index The index of the source that should be removed from the map view.
 */
- (void) removeLayerAtIndex: (NSInteger) index;

/**
 * Removes all layers with the specified type from the map view.
 * @param sourceType The source type of the sources that should be removed from the map view.
 */
- (void) removeLayersWithType: (TTMapLayerType) sourceType;

/**
 * Moves a layer one position forward in the map view layer array.
 * Moves a layer one position forward in the map view layer array. This will cause the layer to be on top of the layer immediatly
 * above it so it will be drawn above it.
 * @param source The source that should be moved.
 */
- (void) sendLayerForward: (TTAPIGenericTileSource*) source;

/**
 * Moves a layer one position backward in the map view layer array.
 * Moves a layer one position backward in the map view layer array. This will cause the layer to be below the layer immediatly
 * below it so it will be draw below it.
 * @param source The source that should be moved.
 */
- (void) sendLayerBackward: (TTAPIGenericTileSource*) source;

/**
 * Changes a layer's position in the layers array.
 * This method will move the given layer in the layers array so it is now placed under or above a new set of layers. This will 
 * change the visibility of the layers since the drawing order used by the iPhone's SDK will now be different.
 * @param source Source that will be moved in the array. The isEqual method will be used when comparing the sources.
 * @param index New index of the source, if the index is greater then the number of layers in the array, the layer will be 
 * placed in the last position of the array.
 */
- (void) moveLayer: (TTAPIGenericTileSource*) source toIndex: (NSInteger) index;

/**
 * Returns the total of sources currently being kept in memory by the SDK.
 * @return Current number of sources.
 */
- (NSInteger) getTotalSources;

/**
 * Returns the source present at the given index.
 * If the given index is greater than the current number of sources an exception will be raised.
 * @param index Index for which the SDK will try to find a tile source.
 * @return Source at the given index.
 */
- (TTAPIGenericTileSource*) getSourceAtIndex: (NSInteger) index;

/**
 * Returns the index of the given source.
 * Returns the index of the given source. The search will be doen by reference.
 * @param source Source to be searched for in the SDK. 
 * @return The index of the source passed as parameter, -1 if the source is not found.
 */
- (NSInteger) getSourceIndex: (TTAPIGenericTileSource*) source;

/**
 * Activates and deactivates the hability to drag the map.
 * @param active Defines if map dragging should be active or not.
 */
- (void) setMapDraggingActive: (BOOL) active;

/**
 * Activates and deactivates the hability to zoom the map.
 * @param active Defines if map zooming should be active or not.
 */
- (void) setMapZoomingActive: (BOOL) active;

/**
 * Activates and deactivates the hability to rotate the map.
 * @param active Defines if map rotations should be active or not.
 */
- (void) setMapRotationsActive: (BOOL) active;

/**
 * Activates the inertia effect in the map
 */
- (void) setDecelerationActive: (BOOL) active;


/**
 * Set the inertia factor for the inertia effect.
 */
- (void) setDecelerationFactor: (float) factor;

/**
 * Set the minimum Inertia Delta. Default is 0.01 so be careful.
 */
- (void) setMinDecelerationDelta: (float) delta;


/**
 * Gets the coordinates of the central point of the map view being displayed.
 * @return Object with the latitude and longitude coordinates of the central position of the map view.
 */
- (TTCoordinates*) getMapCenterLocation;


/**
 * Clears layer cache.
 * Clears the cached images for all layers.
 */
- (void) clearCache;

/**
 * Save the whole memory cache to DB.
 */
-(void) saveCache;

/**
 * Gets the screen bounding box in the mercator projection.
 * Gets the screen bounding box in the mercator projection.
 * @return The screen bounding box in the mercator projection.
 */
- (TTBBox *) screenBBox;

/**
 * Gets the screen bounding box in the WGS Lat/Long.
 * Gets the screen bounding box in the WGS Lat/Long..
 * @return The screen bounding box in the WGS Lat/Long..
 */
- (TTBBox *) screenWGSBBox;

/**
 * Converts a pair of coordinates to a screen point.
 * Converts a pair of coordinates to a screen point.
 * @param coordinates The coordinates to convert.
 * @return A screen point corespondent to the coordinates passed as parameter.
 */
- (TTPoint *) coordinatesToScreenPoint:(TTCoordinates *)coordinates;

/**
 * Converts a screen point in mercator coordinates.
 * Converts a screen point in coordinates.
 * @param point The point in the map.
 * @return The corresponding mercator coordinates.
 */
- (TTCoordinates*) screenTTPointToCoordinates:(TTPoint*)point;

/**
 * Converts a screen point in mercator coordinates.
 * Converts a screen point in coordinates.
 * @param point The point in the map.
 * @return The corresponding mercator coordinates.
 */
- (TTCoordinates*) screenCGPointToCoordinates:(CGPoint)point;

/**
 * Takes a snapshot of the map.
 * Takes a snapshot of the map visible area.
 * @return A snapshot image.
 */
- (UIImage *) takeSnapshot;

/**
 * Takes a snapshot from an area of the map.
 * Takes a snapshot from an area of the map.
 * @param area The snapshot area.
 * @return A snapshot image of the designated area.
 */
- (UIImage *) takeSnapshot:(CGRect)area;

/**
 * Rotates the map view.
 * Rotates the map view. For this method to work properly, the rotation of the map view needs to be enabled first, otherwise 
 * this call will be ignored.
 * @param angle Rotation angle in radians.
 */
- (void) setRotationAngle: (CGFloat) angle;

/**
 * Lets the SDK know if it should handle memory warnings for the developer or if all memory issues should be 
 * handled by the application.
 * @param handle If set to NO the SDK will no longer handle memory warning.
 */
- (void) setHandleMemoryWarnings: (BOOL) handle;

/**
 * Returns a BOOL indicating if the SDK is handling memory warnings.
 * @return Returns YES if the SDK is handling memory warnings.
 */
- (BOOL) getHandleMemoryWarning;

/**
 * Lets the SDK know if it should suppress loadings on memory warnings.
 * @param suppress If set to NO the SDK will no longer suppress loadings on memory warnings.
 */
- (void) setSuppressLoadingOnMemoryWarnings: (BOOL) suppress;

/**
 * Returns a BOOL indicating if the SDK is suppressing loadings on memory warnings.
 * @return Returns YES if the SDK is suppressing loadings on memory warnings.
 */
- (BOOL) getSuppressLoadingOnMemoryWarning;

/**
 * Lets the SDK know if it should remove invisible tiles on memory warnings.
 * @param remove If set to NO the SDK will no longer remove invisible tiles on memory warnings.
 */
- (void) setRemoveInvisibleTilesOnMemoryWarnings: (BOOL) remove;

/**
 * Returns a BOOL indicating if the SDK is removing invisible tiles on memory warnings.
 * @return Returns YES if the SDK is removing invisible tiles on memory warnings.
 */
- (BOOL) getRemoveInvisibleTilesOnMemoryWarnings;

/**
 * Lets the SDK know if it should clear the memory cache on memory warnings.
 * @param clear If set to NO the SDK will not clear the cache memory on memory warnings.
 */
- (void) setClearMemoryCacheOnMemoryWarnings: (BOOL) clear;

/**
 * Returns a BOOL indicating if the SDK is clearing the memory cache on memory warnings.
 * @return Returns YES if the SDK is clearing the memory cache on memory warnings.
 */
- (BOOL) getClearMemoryCacheOnMemoryWarnings;

/**
 * Lets the SDK know if it should clear all tiles on memory warnings.
 * @param clear If set to NO the SDK will not clear all tiles on memory warnings.
 */
- (void) setClearAllTilesOnMemoryWarning: (BOOL) clear;

/**
 * Returns a BOOL indicating if the SDK is clearing all tiles on memory warnings.
 * @return Returns YES if the SDK is clearing all tiles on memory warnings
 */
- (BOOL) getClearAllTilesOnMemoryWarning;

/**
 * Set the delay to start the tile loading. Increasing this value can improve performance since it will 
 * prevent the SDK from starting the load of tiles that will not be needed, but it can damage the user experience. 
 * Check kDefaultTileLoadDelay for the default value.
 * @param delay Float value with the delay that will now be used for the source.
 */
- (void) setTileLoadDelay: (NSNumber*) delay;

/**
 * Get the current tile load delay.
 * @return The source's delay.
 */
- (NSNumber*) getTileLoadDelay;

/**
 * Set the max counter value when dragging the map.
 * It specifies the number of cycles to wait for a updating tiles.
 * a ZERO value will make sure the updates ONLY happens when the dragging stops
 */
- (void) setMaxDragMapCounter: (int)value;

/**
 * This method will try to fetch the current Map Version using the STATUS REST API
 * if there is a new version ( as specified in the user preferences : MAP_VERSION
 * it will update it and clear the cache ( If the parameter is set )
 * Returns YES if the Map Tile Version has changed and it needs to be updated.
 */
- (BOOL) checkMapVersion: (BOOL)clearCache;

@end
