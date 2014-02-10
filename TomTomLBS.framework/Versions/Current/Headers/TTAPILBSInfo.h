//
//  @(#)TTAPILBSInfo.h 10/05/25
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTSDKUtils.h"
#import "TTAPILBSInfoDelegate.h"

/*
 * Defines the TTMapType the API accepts.
 * See TTMapType_toString for a way to convert into NSString*
 */
typedef enum {
	TTMapTypeBasic,
	TTMapTypeCommunity
} TTMapType;

/**
 * Convers a TTMapType into its String equivalent.
 */
__attribute__((visibility("default")))NSString * const TTMapType_toString[2];

/**
 * Defines the optional parameters for the ViewPort Description API.
 */
@interface TTAPIViewPortDescriptionOptionalParameters : NSObject {
    BOOL fullCopyright;
    TTMapType mapType;
}


/**
 * Whether to return the full copyright information or just a smaller version containing the labels (used in print page).
 */
@property BOOL fullCopyright;
/**
 * The map type. Can be basic or community.
 */
@property TTMapType mapType;

/**
 * Converts the parameters to a query string that can be added to the end of the URL that accesses the server.
 * Accounts for non initialized parameters.
 * @returns an NSString with the parameters in the format: ";fullCopyright;map=mapType"
 */
-(NSString*) stringValue;

@end




@class TTAPIInitializeData;
@class TTAPIViewportDescriptionData;
@class TTAPIInitializeOperation;
@class TTAPIViewportDescriptionOperation;
@class TTBBox;

/**
 * ViewPort Description and Initializer services API wrapper.
 *
 * If you feel the necessity to execute the API calls in background (using the new IOS4 features) be sure to check
 * the following link so that you can prepare your App to run the calls accordingly.
 *
 * https://developer.apple.com/iphone/library/documentation/iPhone/Conceptual/iPhoneOSProgrammingGuide/BackgroundExecution/BackgroundExecution.html
 */
@interface TTAPILBSInfo : NSObject<TTAPILBSInfoDelegate> {
	@private
	NSString *trafficModelId;
	double tmiListenerWaitInterval;
}

/**
 * Instance constructor.
 */
- (id) init;

/**
 * Makes a synchronous initialize request.
 * Makes a synchronous initialize request.
 * @return The service configurations.
 */
- (TTAPIInitializeData *) initialize;

/**
 * Makes an asynchronous initialize request.
 * Makes an asynchronous initialize request. Since this is an asynchronous call, a delegate is defined and notified 
 * at the end of the call.
 * @param delegate The initialize delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source 
 * when multiple similar requests are performed.
 */
- (void) initializeAndNotifyDelegate:(id<TTAPILBSInfoDelegate>)delegate withPayload:(id)payload;

/**
 * Creates an initialize operation.
 * Creates an initialize operation and returns it for later invocation via NSOperationQueue.
 * @return An initialize operation.
 */
- (TTAPIInitializeOperation*) getInitializeOperation;


/**
 * Makes a synchronous viewport description request.
 * Makes a synchronous viewport description request.
 * Defaults the Map Type to basic and gets the short version of the copyright information.
 * @param bbox The bounding box of the map viewport.
 * @param zoom The zoom level of the viewport.
 * @param oBbox The bounding box of the small overview map.
 * @param oZoom The zoom level of the small overview map.
 * @return The viewport description.
 */
- (TTAPIViewportDescriptionData*) getViewportDescription:(TTBBox*)bbox
                                            andZoomLevel:(NSInteger)zoom
                                         andOverviewBBox:(TTBBox*)oBbox 
                                    andOverviewZoomLevel:(NSInteger)oZoom;
    
/**
 * Makes a synchronous viewport description request.
 * Makes a synchronous viewport description request.
 * @param bbox The bounding box of the map viewport.
 * @param zoom The zoom level of the viewport.
 * @param oBbox The bounding box of the small overview map.
 * @param oZoom The zoom level of the small overview map.
 * @param optional The optional parameters as defined by class TTAPIViewPortDescriptionOptionalParameters. Can be nil.
 * @return The viewport description.
 */
- (TTAPIViewportDescriptionData*) getViewportDescription:(TTBBox*)bbox
                                            andZoomLevel:(NSInteger)zoom
                                         andOverviewBBox:(TTBBox*)oBbox 
                                    andOverviewZoomLevel:(NSInteger)oZoom
                                   andOptionalParameters:(TTAPIViewPortDescriptionOptionalParameters*)optional;

/**
 * Makes an asynchronous viewport description request.
 * Makes an asynchronous viewport description request. Since this is an asynchronous call, a delegate is defined 
 * and notified at the end of the call.
 * Defaults the Map Type to basic and gets the short version of the copyright information.
 * @param bbox The bounding box of the map viewport.
 * @param zoom The zoom level of the viewport.
 * @param oBbox The bounding box of the small overview map.
 * @param oZoom The zoom level of the small overview map.
 * @param delegate The viewport description delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getViewportDescription:(TTBBox*)bbox
                   andZoomLevel:(NSInteger)zoom
                andOverviewBBox:(TTBBox*)oBbox 
           andOverviewZoomLevel:(NSInteger)oZoom
              andNotifyDelegate:(id<TTAPILBSInfoDelegate>)delegate withPayload:(id)payload;

/**
 * Makes an asynchronous viewport description request.
 * Makes an asynchronous viewport description request. Since this is an asynchronous call, a delegate is defined 
 * and notified at the end of the call.
 * @param bbox The bounding box of the map viewport.
 * @param zoom The zoom level of the viewport.
 * @param oBbox The bounding box of the small overview map.
 * @param oZoom The zoom level of the small overview map.
 * @param optional The optional parameters as defined by class TTAPIViewPortDescriptionOptionalParameters. Can be nil.
 * @param delegate The viewport description delegate.
 * @param payload The payload object to deliver to the delegate. Might be usefull to help identifying the source, 
 * when multiple similar requests are performed
 */
- (void) getViewportDescription:(TTBBox*)bbox
                   andZoomLevel:(NSInteger)zoom
                andOverviewBBox:(TTBBox*)oBbox 
           andOverviewZoomLevel:(NSInteger)oZoom
          andOptionalParameters:(TTAPIViewPortDescriptionOptionalParameters*)optional 
              andNotifyDelegate:(id<TTAPILBSInfoDelegate>)delegate withPayload:(id)payload;

/**
 * Creates a viewport description operation.
 * Creates a viewport description operation and returns it for later invocation via NSOperationQue.
 * @param bbox The bounding box of the map viewport.
 * @param zoom The zoom level of the viewport.
 * @param oBbox The bounding box of the small overview map.
 * @param oZoom The zoom level of the small overview map.
 * @param optional The optional parameters as defined by class TTAPIViewPortDescriptionOptionalParameters. Can be nil.
 * @return A viewport description operation.
 */
- (TTAPIViewportDescriptionOperation*) getViewportDescriptionOperation:(TTBBox*)bbox
                                                          andZoomLevel:(NSInteger)zoom
                                                       andOverviewBBox:(TTBBox*)oBbox 
                                                  andOverviewZoomLevel:(NSInteger)oZoom
                                                 andOptionalParameters:(TTAPIViewPortDescriptionOptionalParameters*)optional;

/**
 * Starts updating the TMI, periodically.
 * Updates will be notified using the global notification: TTSDKUtils.TTSDKTrafficModelIdChangedNotification
 * @param seconds the update period
 */
- (void) startUpdatingTrafficModelID:(double)seconds;

/**
 * Stops updating the TMI.
 */
- (void) stopUpdatingTrafficModelID;

/**
 * Gets the Current Traffic Model ID 
 * @return The Traffic Model ID string
 */
- (NSString *) getCurrentTrafficModelId;
@end
