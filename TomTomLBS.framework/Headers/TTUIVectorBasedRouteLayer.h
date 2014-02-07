//
//  TTPathBasedRouteLayer.h
//  TemplateViewBasedApp
//
//  Created by JJ Rojas on 12/23/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//
// This class is mostly based from RMPath in Route-me

#import <UIKit/UIKit.h>

#import "RMFoundation.h"
#import "RMLatLong.h"
#import "RMMapLayer.h"
#import "TTUIMapViewController.h"
#import "TTAPIRouting.h"
#import "TTAPIRoutingDelegate.h"

@class RMMapContents;
@class RMMapView;

@interface TTUIVectorBasedRouteLayer : RMMapLayer <RMMovingMapLayer,TTAPIRoutingDelegate>
{
	NSMutableArray *points;

	/// This is the first point.
	RMProjectedPoint projectedLocation;
	
	/// The color of the line, or the outline if a polygon
	UIColor *lineColor;
    
    // Color of the outline
    UIColor *outlineColor;
 
    // The transparency of the path ( NOT IMPLEMENTED )
    CGFloat transparency;
	
	CGMutablePathRef path;

	/// Width of the line, units unknown; pixels maybe?
	float lineWidth;
    
    // Line thickness, before the border. If this is not
    // specified, then only "lineWidth" will be used.
    // * Experimental *
    float borderThickness;
	
	/*! Drawing mode of the path; Choices are
	 kCGPathFill,
	 kCGPathEOFill,
	 kCGPathStroke,
	 kCGPathFillStroke,
	 kCGPathEOFillStroke */
	CGPathDrawingMode drawingMode;
	
	BOOL scaleLineWidth;
    BOOL enableDragging;
    BOOL enableRotation;
	
	float renderedScale;
	RMMapContents *contents;
    
    //Current Route Key for updates
    NSString *routeKey;
    
    //The Routing parameters
    TTAPIRoutingOptionalParameters *optionalParameters;
    
    //Current view controller
    TTUIMapViewController *controller;
    
    // Route Manager
    TTAPIRouting *routeManager;
    
}

- (id) initForController:(TTUIMapViewController*) controller key:(NSString *)route andParameters:(TTAPIRoutingOptionalParameters *)params;

@property float lineWidth;
@property float borderThickness;
@property BOOL	scaleLineWidth;
@property CGFloat transparency;
@property (nonatomic, assign) RMProjectedPoint projectedLocation;
@property (readwrite, assign) UIColor *lineColor;
@property (readwrite, assign) UIColor *outlineColor;

@property (assign) BOOL enableDragging;
@property (assign) BOOL enableRotation;

/*
- (void) moveToXY: (RMProjectedPoint) point;
- (void) moveToScreenPoint: (CGPoint) point;
- (void) moveToLatLong: (RMLatLong) point;
- (void) addLineToXY: (RMProjectedPoint) point;
- (void) addLineToScreenPoint: (CGPoint) point;
- (void) addLineToLatLong: (RMLatLong) point;
*/

/**
 * Set the current path for the layer. The array MUST contain TTCoordinates
 * and this coordinated must be in LAT / LON values. 
 */
- (void) setPath: (NSArray *) coordinates;

/**
 * Will call the  "recalculate" route in the current path.
 * This is used to update the new vector points in a new zoom level.
 */
- (void) updateZoomLevel:(int)zoom;

@end
