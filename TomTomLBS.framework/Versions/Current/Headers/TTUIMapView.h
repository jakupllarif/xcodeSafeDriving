//
//  @(#)TTUIMapView.h 10/05/24
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <UIKit/UIKit.h>
#import "RMMapView.h"
#import "TTAPIGenericTileSource.h"
#import "TTAPITileSourceFactory.h"
#import "TTUIMapViewController.h"
#import "TTUIMarker.h"
#import "TTUIMapTouchInterceptorDelegate.h"
#import "TTSDKUtils.h"
/*
 * Defines the map move event states.
 */
typedef enum {
	TTMapInteractionStateIdle,
	TTMapInteractionStateBeforeMove,
	TTMapInteractionStateMoving,
	TTMapInteractionStateAfterMove,
	TTMapInteractionStateBeforeZoom,
	TTMapInteractionStateZooming,
	TTMapInteractionStateAfterZoom
} TTMapInteractionState;


/**
 * This class allows the SDK to access the Route-me functions present in the RMMapView class.
 */
@interface TTUIMapView : RMMapView<RMMapViewDelegate> {
	@private

    
	/** The move event timer. helps to fire the correct (or our) after move event. */
	NSTimer *moveTimer;
	/** The move event state. */
	TTMapInteractionState moveState;
	/** The zoom event timer. helps to fire the correct (or our) after zoom event. */
	NSTimer *zoomTimer;
	/** The zoom event state. */
	TTMapInteractionState zoomState;
	
	/**
	 * Array with the markers that are currently present in the screen.
	 */
	NSMutableArray *markers;
	/**
	 * Map view controller to allow the map view access to the delegate methods defined by the developer.
	 */
	TTUIMapViewController* controller;
	
	/**
	 * Interceptor delegate that will intercept the route-me events, invoke an application method and according to the returned 
	 * value continue executing the route-me handler or not.
	 */
	id<TTUIMapTouchInterceptorDelegate> touchInterceptorDelegate;
    
#ifdef METRICS_ENABLED
    id movingLogKey;
#endif
}

@property(nonatomic, retain) NSMutableArray *markers;
@property(nonatomic, retain) TTUIMapViewController* controller;
@property(nonatomic, assign) TTMapInteractionState moveState;
@property(nonatomic, assign) TTMapInteractionState zoomState;
@property(nonatomic, retain) id<TTUIMapTouchInterceptorDelegate> touchInterceptorDelegate;

/**
 * Class main constructor.
 * Constructor that prepares the MapView and sets up the needed objects, including the tile sources according to the initial
 * configuration from the developer.
 * @param frame CGRect representing the size and position of the MapView in the window.
 * @param cont SDK controller that will allow the map view to access the delegate methods defined by the developer.
 * @param sources Array with the initial sources for the map view.
 * @return TTUIMapView object.
 */
- (id)initWithFrame:(CGRect)frame andController: (TTUIMapViewController*) cont withSources: (NSMutableArray*) sources;

/**
 * Delegate method for marker taps.
 * This method will be invoked by the Route-me library when the user taps a marker. 
 * It will allow for extra features to be added. This function will simply call the appropriate 
 * delegate functions of the SDK's TTUIMapDelegate protocol. Those functions will be defined 
 * by the developer and allow the execution of custom code.
 * @param marker The marker the user tapped.
 * @param map The RMMapView the marker is placed on.
 */
- (void) tapOnMarker: (RMMarker*) marker onMap: (RMMapView*) map;

/**
 * Delegate method for double taps on the map.
 * This method is invoked by the RouteMe library when a double tap is done on the map. 
 * The SDK will always execute the zoom in of the map and then will invoke the application delegate method.
 * @param map The RMMapView the marker is placed on.
 * @param point The point in which the tap occurred.
 */
- (void) doubleTapOnMap: (RMMapView*) map At: (CGPoint) point;

//- (void) mapView:(RMMapView *)map didDragMarker:(RMMarker *)marker withEvent:(UIEvent *)event;

/**
 * Returns the projected bounding box.
 * Returns the projected bounding box.
 * @return The projected bounding box.
 */
- (TTBBox *) projectedBbox;

/**
 * Returns the projected bounding box in lat/lon 
 */
- (TTBBox *) projectedBboxInLatLon;

/**
 * original method to draw on top of the map view
 
- (void)drawRect:(CGRect)rect;
*/

/**
 * Set the perspective angle in the Z AXIS
 */
- (void) rotateMapLayer: (CGPoint)point withPerspective:(BOOL)perspective;

/** set the rotation back to the identity */
- (void) rotateReset;
- (void) beforeMapRotate: (RMMapView*) map toAngle: (CGFloat) angle;

- (void) afterMapRotate: (RMMapView*) map toAngle: (CGFloat) angle;
@end
