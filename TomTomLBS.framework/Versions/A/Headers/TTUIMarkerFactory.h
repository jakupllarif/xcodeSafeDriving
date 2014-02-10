//
//  @(#)TTUIMarkerFactory.m 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTSDKUtils.h"
#import "TTUIMarker.h"

@class TTAPITrafficPoi;
@class TTAPIRouteInstruction;

/**
 * PIN Factory.
 * The factory has helper methods to return TTUIMarkers.
 */
@interface TTUIMarkerFactory : NSObject {

}

/**
 * Gets the currently set default offset for the marker type TTUIMarkerType_CurrentLocation.
 * @return The currently set default offset for the marker type TTUIMarkerType_CurrentLocation.
 */
+(TTPoint *) TTUIMarkerType_CurrentLocation_DefaultOffset;
/**
 * Gets the currently set default offset for the marker type TTUIMarkerType_RouteStart
 * @return The currently set default offset for the marker type TTUIMarkerType_RouteStart.
 */
+(TTPoint *) TTUIMarkerType_RouteStart_DefaultOffset;
/**
 * Gets the currently set default offset for the marker type TTUIMarkerType_RouteEnd.
 * @return The currently set default offset for the marker type TTUIMarkerType_RouteEnd.
 */
+(TTPoint *) TTUIMarkerType_RouteEnd_DefaultOffset;
/**
 * Gets the currently set default offset for the marker type TTUIMarkerType_SearchResults.
 * @return The currently set default offset for the marker type TTUIMarkerType_SearchResults.
 */
+(TTPoint *) TTUIMarkerType_SearchResults_DefaultOffset;
/**
 * Gets the currently set default offset for the marker type TTUIMarkerType_DroppedPIN.
 * @return The currently set default offset for the marker type TTUIMarkerType_DroppedPIN.
 */
+(TTPoint *) TTUIMarkerType_DroppedPIN_DefaultOffset;
/**
 * Gets the currently set default offset for the marker type TTUIMarkerType_Instruction.
 * @return The currently set default offset for the marker type TTUIMarkerType_Instruction.
 */
+(TTPoint *) TTUIMarkerType_Instruction_DefaultOffset;
/**
 * Gets the currently set default offset for the marker type TTUIMarkerType_Traffic.
 * @return The currently set default offset for the marker type TTUIMarkerType_Traffic.
 */
+(TTPoint *) TTUIMarkerType_Traffic_DefaultOffset;

/**
 * Gets the currently set default image file name for the marker type TTUIMarkerType_CurrentLocation.
 * @return The currently set default image file name for the marker type TTUIMarkerType_CurrentLocation.
 */
+(NSString*) TTUIMarkerType_CurrentLocation_DefaultImageName;
/**
 * Gets the currently set default image file name for the marker type TTUIMarkerType_RouteStart.
 * @return The currently set default image file name for the marker type TTUIMarkerType_RouteStart.
 */
+(NSString*) TTUIMarkerType_RouteStart_DefaultImageName;
/**
 * Gets the currently set default image file name for the marker type TTUIMarkerType_RouteEnd.
 * @return The currently set default image file name for the marker type TTUIMarkerType_RouteEnd.
 */
+(NSString*) TTUIMarkerType_RouteEnd_DefaultImageName;
/**
 * Gets the currently set default image file name for the marker type TTUIMarkerType_SearchResults.
 * @return The currently set default image file name for the marker type TTUIMarkerType_SearchResults.
 */
+(NSString*) TTUIMarkerType_SearchResults_DefaultImageName;
/**
 * Gets the currently set default image file name for the marker type TTUIMarkerType_DroppedPIN.
 * @return The currently set default image file name for the marker type TTUIMarkerType_DroppedPIN.
 */
+(NSString*) TTUIMarkerType_DroppedPIN_DefaultImageName;
/**
 * Gets the currently set default image file name for the marker type TTUIMarkerType_Instruction.
 * @return The currently set default image file name for the marker type TTUIMarkerType_Instruction.
 */
+(NSString*) TTUIMarkerType_Instruction_DefaultImageName;

/**
 * Overrides the currently set image and offset for the specified marker type.
 * @param fileName The new image filename.
 * @param theOffset The new default offset.
 * @param theType The type we are changing.
 */
+(void) setDefaultMarkerImageName:(NSString*)fileName andOffset:(TTPoint *)theOffset forMarkerType:(TTUIMarkerType)theType;

/**
 * Creates a new TTUIMarker.
 * Creates a new TTUIMarker specifying the offset and the coordinates. The returned TTUIMarker will use the 
 * image provided by the developer.
 * @param aCoordinates The coodinates of the marker.
 * @param image The name of the image of the marker. 
 * @param anOffset The offset. The offset is defined in the scale from 0 to 1. This means, for example, that
 * 0.5 in both x and y will make the offset half the width and height.
 * @param type The marker's type.
 * @return The new TTUIMarker.
 */

+ (TTUIMarker*) getMarkerWithCoordinates: (TTCoordinates*)aCoordinates 
							andImageName: (NSString*) image 
							   andOffset: (TTPoint *)anOffset 
								 andType: (TTUIMarkerType) type;


/**
 * Creates a new TTUIMarker containing a traffic incident.
 * Creates a new TTUIMarker specifying the offset and the coordinates. The returned TTUIMarker will get the 
 * image from the bundled resources - style 1.
 * @param poi the traffic POI that the icon will represent
 * @return The new TTUIMarker.
 */
+ (TTUIMarker*) getBundledTrafficIncidentMarkerForPOI : (TTAPITrafficPoi*) poi;

/**
 * Creates a new TTUIMarker containing a route instruction.
 * Creates a new TTUIMarker specifying the offset and the coordinates. The returned TTUIMarker will get the 
 * image from the bundled resources.
 * @param instruction the route instruction POI that the icon will represent
 * @return The new TTUIMarker.
 */
+ (TTUIMarker*) getBundledRouteInstructionMarkerForPOI:(TTAPIRouteInstruction*) instruction;

/**
 * Creates a new TTUIMarker containing a traffic incident.
 * Creates a new TTUIMarker specifying the offset and the coordinates. The returned TTUIMarker will use the 
 * image of the traffic incident from the LBS server.
 * @param aCoordinates The coodinates of the marker.
 * @param category The Icon category. 
 * @param iconType The Icon type
 * @param clusterSize  The number of incidents in this icon.
 * @param anOffset The offset. The offset is defined in the scale from 0 to 1. This means, for example, that
 * 0.5 in both x and y will make the offset half the width and height.
 * @return The new TTUIMarker.
 */
+ (TTUIMarker*) getTrafficIncidentMarkerWithCoordinates: (TTCoordinates*)aCoordinates
                                            andCategory: (int) category
                                                andType: (int) iconType
										andClusterSize : (int) clusterSize
                                              andOffset: (TTPoint *)anOffset;

/**
 * Creates a new TTUIMarker containing a traffic incident.
 * Creates a new TTUIMarker specifying the offset and the coordinates. The returned TTUIMarker will use the 
 * image of the traffic incident from the LBS server.
 * @param poi the traffic POI that the icon will represent
 * @return The new TTUIMarker.
 */
+ (TTUIMarker*) getTrafficIncidentMarkerForPOI:(TTAPITrafficPoi*) poi;


/**
 * Creates a new location marker with default image.
 * Creates a new location maker with a specific location.
 * @param aCoordinates The coordinates of the marker.
 * @return The new location marker.
 */
+ (TTUIMarker*) getLocationMarkerWithCoordinates: (TTCoordinates*)aCoordinates;

/**
 * Creates a new location marker with default image.
 * Creates a new location maker with a specific location.
 * Changing its type will cause the specific image and offset to be lost.
 * @param aCoordinates The coordinates of the marker.
 * @param image The name of the image of the marker. 
 * @param anOffset The offset. The offset is defined in the scale from 0 to 1. This means, for example, that
 * 0.5 in both x and y will make the offset half the width and height.
 * @return The new location marker.
 */
+ (TTUIMarker*) getLocationMarkerWithCoordinates:(TTCoordinates*)aCoordinates 
									andImageName:(NSString*)image 
									   andOffset:(TTPoint *)anOffset;

/**
 * Creates a new dropped marker with default image.
 * Creates a new dropped maker with a specific location.
 * @param aCoordinates The coordinates of the marker.
 * @return The new dropped marker.
 */
+ (TTUIMarker*) getDroppedMarkerWithCoordinates: (TTCoordinates*)aCoordinates;


/**
 * Creates a new dropped marker with default image.
 * Creates a new dropped maker with a specific location.
 * Changing its type will cause the specific image and offset to be lost.
 * @param aCoordinates The coordinates of the marker.
 * @param image The name of the image of the marker. 
 * @param anOffset The offset. The offset is defined in the scale from 0 to 1. This means, for example, that
 * 0.5 in both x and y will make the offset half the width and height.
 * @return The new dropped marker.
 */
+ (TTUIMarker*) getDroppedMarkerWithCoordinates:(TTCoordinates*)aCoordinates 
                                   andImageName:(NSString*)image 
                                      andOffset:(TTPoint *)anOffset;
    
/**
 * Creates a new marker with the current location icon.
 * Creates a new current location maker with a specific location.
 * @param aCoordinates The coordinates of the marker.
 * @return The new current location marker.
 */
+ (TTUIMarker*) getCurrentLocationMarkerWithCoordinates: (TTCoordinates*)aCoordinates;

/**
 * Creates a new marker with the current location icon.
 * Creates a new current location maker with a specific location.
 * Changing its type will cause the specific image and offset to be lost.
 * @param aCoordinates The coordinates of the marker.
 * @param image The name of the image of the marker. 
 * @param anOffset The offset. The offset is defined in the scale from 0 to 1. This means, for example, that
 * 0.5 in both x and y will make the offset half the width and height.
 * @return The new current location marker.
 */
+ (TTUIMarker*) getCurrentLocationMarkerWithCoordinates:(TTCoordinates*)aCoordinates 
										   andImageName:(NSString*)image 
											  andOffset:(TTPoint *)anOffset;

/**
 * Creates a new marker with the start location icon.
 * Creates a new start location maker with a specific location.
 * @param aCoordinates The coordinates of the marker.
 * @return The new start location marker.
 */
+ (TTUIMarker*) getStartLocationMarkerWithCoordinates: (TTCoordinates*)aCoordinates;

/**
 * Creates a new marker with the start location icon.
 * Creates a new start location maker with a specific location.
 * Changing its type will cause the specific image and offset to be lost.
 * @param aCoordinates The coordinates of the marker.
 * @param image The name of the image of the marker. 
 * @param anOffset The offset. The offset is defined in the scale from 0 to 1. This means, for example, that
 * 0.5 in both x and y will make the offset half the width and height.
 * @return The new start location marker.
 */
+ (TTUIMarker*) getStartLocationMarkerWithCoordinates:(TTCoordinates*)aCoordinates 
										   andImageName:(NSString*)image 
											  andOffset:(TTPoint *)anOffset;

/**
 * Creates a new marker with the end location icon.
 * Creates a new end location maker with a specific location.
 * @param aCoordinates The coordinates of the marker.
 * @return The new end location marker.
 */
+ (TTUIMarker*) getEndLocationMarkerWithCoordinates: (TTCoordinates*)aCoordinates;

/**
 * Creates a new marker with the end location icon.
 * Creates a new end location maker with a specific location.
 * Changing its type will cause the specific image and offset to be lost.
 * @param aCoordinates The coordinates of the marker.
 * @param image The name of the image of the marker. 
 * @param anOffset The offset. The offset is defined in the scale from 0 to 1. This means, for example, that
 * 0.5 in both x and y will make the offset half the width and height.
 * @return The new end location marker.
 */
+ (TTUIMarker*) getEndLocationMarkerWithCoordinates:(TTCoordinates*)aCoordinates 
										 andImageName:(NSString*)image 
											andOffset:(TTPoint *)anOffset;

/**
 * Get a template marker. The image of the marker is nil. Coordinates and offset are void values. The marker has no types.
 * @returns A clean marker with no types, image, coordinates or offset.
 */
+ (TTUIMarker*) getTemplateMarker;

@end
