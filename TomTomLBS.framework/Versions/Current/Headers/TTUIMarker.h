//
//  @(#)TTUIMarker.h 10/05/26
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TTSDKUtils.h"

/**
 * Enumeration for the types of pins.
 */
enum TTUIMarkerType {
    
	/* Pin indicating the current location of the device. */
	TTUIMarkerType_CurrentLocation,
    
	/* The route start pin. */
	TTUIMarkerType_RouteStart,
	/* The route end pin. */
	TTUIMarkerType_RouteEnd,
    
	/* The location pin sould be the most generic one and the one used when developing custom pins. */
	TTUIMarkerType_SearchResults,
    
	/* A dropped pin. */
	TTUIMarkerType_DroppedPIN,
    
	/* A traffic pin. */
	TTUIMarkerType_Traffic,
	
	/* An instruction pin. */
	TTUIMarkerType_Instruction,
    
    /*An 3rd party Pin */
    TTUIMarkerType_another
};
typedef NSUInteger TTUIMarkerType;

#define TTUIMarkerTypes_COUNT 5

/**
 * This class represent a map marker (sometimes known as pin).
 */
@interface TTUIMarker : NSObject {

@package
	id _impl;
	
@private
    
	/**
	 * Image that will represent the marker in the map view.
	 */
	UIImage *image;
	/**
	 * Image offset, used to adjust the image positioning. Should be a pair of values between 0.0 and 1.0 .
	 */
	TTPoint *offset;
	/**
	 * Position of the marker in the map view in latitude and longitude.
	 */
	TTCoordinates* coordinates;
	/**
	 * Types of the pin.
     * Use setType and removeType to control the the marker's types.
	 */
    BOOL types[TTUIMarkerTypes_COUNT];
	/** The current z position of the marker layer. */
	float zPosition;
    
    /**
     * The ID from the parent tile source. Is it is -1 then it belongs to the MapViewController
     */
    long parentID;
    
    /**
     * Tells if this marker is currently visible in the viewport.
     */
    BOOL isVisible;
}

@property (nonatomic, retain) TTCoordinates* coordinates;
@property (nonatomic, assign) long parentID;
@property (nonatomic, assign) BOOL isVisible;

/**
 * Initializes a new marker using the default type: TTUIMarkerType_SearchResults
 * @param anImage Image that will represent the marker in the map view.
 * @param anOffset Offset to be used when placing the marker in the map view so the correct position of the image is directly
 * above the marker's coordinates.
 * @param aCoordinates Coordinates where the marker will be positioned in latitude and longitude.
 * @param someData Data defined by the developer which will be used by the application in any way the developer defines.
 * @return A new marker.
 */
- (id)initWithImage:(UIImage *)anImage andOffset:(TTPoint *)anOffset andCoordinates:(TTCoordinates*)aCoordinates 
            andData:(NSObject *)someData;

/**
 * Initializes a new marker.
 * @param anImage Image that will represent the marker in the map view.
 * @param anOffset Offset to be used when placing the marker in the map view so the correct position of the image is directly
 * above the marker's coordinates.
 * @param aCoordinates Coordinates where the marker will be positioned in latitude and longitude.
 * @param type The type of the marker.
 * @param someData Data defined by the developer which will be used by the application in any way the developer defines.
 * @return A new marker.
 */
- (id)initWithImage:(UIImage *)anImage andOffset:(TTPoint *)anOffset andCoordinates:(TTCoordinates*)aCoordinates 
            andType:(TTUIMarkerType)type andData:(NSObject *)someData;

/**
 * Defines the image of the marker.
 * Defines the image of the marker updating it if the marker is already being displayed.
 * @param im New image for the marker.
 * @param anOffset The image offset.
 */
- (void) setImage:(UIImage *)im offset:(TTPoint *)anOffset;

/**
 * Returns the marker image.
 * @return The marker image.
 */
- (UIImage*) image;

/**
 * Updates the marker's image with another image appropriate for its dominant type.
 * Route start and end types precede the current location and that precedes all the rest.
 */
-(void) updateImageAccordingToDominantType;

/**
 * Returns the marker image offset.
 * @return The marker image offset.
 */
- (TTPoint *) offset;

/**
 * Returns the data object of the marker.
 * @return The data object of the marker.
 */
- (NSObject *)data;

/**
 * Sets the data object of the marker.
 * @param data The data object of the marker.
 */
- (void) setData: (NSObject*) data;

/**
 * Adds a type to the marker.
 * A marker can have more than one type. This method also updates the marker's image.
 * @param type The type to add
 */
-(void) setType:(TTUIMarkerType) type;

/**
 * Removes a type from the marker.
 * A marker can have more than one type. This method also updates the marker's image.
 * @param type The type to remove
 */
-(void) clearType:(TTUIMarkerType) type;

/**
 * Removes all types from the marker.
 * A marker can have more than one type. This method also updates the marker's image.
 */
-(void) clearAllTypes;

/**
 * Removes all type from the marker, except the specified type.
 * Note that if the marker is not already of the specified type, it will NOT be set to that type.
 * A marker can have more than one type. This method also updates the marker's image. 
 */
-(void) clearAllTypesExcept:(TTUIMarkerType) type;

/**
 * Checks if the marker has any types defined other than the type specified.
 * @return YES if the marker has any other type defined, NO if the marker has no more types. It will also return YES if the marker is not of the specified type.
 */
-(BOOL) isOtherTypeThan:(TTUIMarkerType) type;

/**
 * Checks if the marker has any types defined.
 * @return YES if the marker has any type defined, NO otherwise
 */
-(BOOL) hasAnyTypeDefined;

/**
 * Checks if the marker is of the type passed as parameter.
 * @param type The type to check.
 * @return YES when the marker is of the type passed by argument.
 */
-(BOOL) isType:(TTUIMarkerType) type;

/**
 * Checks if this marker has the same exact types as the types on the template passed by parameter.
 * Any difference on the types causes the method to return NO.
 * @param templateMarker A template marker for comparing with this marker.
 * @return YES when the marker has only and all the types as the ones set on the template.
 */
-(BOOL) isSameType:(TTUIMarker*)templateMarker;

/**
 * Checks if this marker has any of the types on the template passed by parameter.
 * @param templateMarker A template marker for comparing with this marker.
 * @return YES if this marker has any of the types of the template.
 */
-(BOOL) hasAnyType:(TTUIMarker*)templateMarker;

/**
 * Attach a view to the marker.
 * The attached view will stick to the marker, meaning that if you move the map, the view will move along with the 
 * marker on the map.
 * Use clearView to remove the attached view.
 * @param view The view to attach.
 */
- (void) attachView:(UIView *)view;

/** 
 * Hides the label of the marker.
 * @param hide True if the label is to be hidden, false if it should be displayed.
 */
- (void) hideView :(BOOL) hide;

/**
 * Indicates if the label of the marker is hidden.
 * @return True if the layer is hidden, false if it is visible.
 */
- (BOOL) isViewHidden;

/**
 * Clears the attached view.
 * Clears the attached view.
 */
- (void) clearView;

@end
