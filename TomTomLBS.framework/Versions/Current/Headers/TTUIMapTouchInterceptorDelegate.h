//
//  @(#)TTUIMapTouchInterceptorDelegate.h 10/06/30
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <UIKit/UIKit.h>


/**
 * Defines the Map touch interceptor delegate.
 * This delegate gives the oportunity to intercept the map touch events before they occur and cancel them (or not) by 
 * returning YES or NO in each method.
 */
 @protocol TTUIMapTouchInterceptorDelegate

/**
 * Touches began event.
 * Fired before the map touches began event. For more detail on the touch events check the UIResponder class or point your
 * browser at http://developer.apple.com/iphone/library/documentation/UIKit/Reference/UIResponder_Class/Reference/Reference.html.
 * @param touches A set of UITouch instances that represent the touches for the starting phase of the event represented by event.
 * @param event An object representing the event to which the touches belong.
 * @return YES to propagate the event to the map and NO if you don't want the touches began to be executed.
 */
- (BOOL)interceptTouchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;

/**
 * Touches moved event.
 * Fired before the map touches moved event. For more detail on the touch events check the UIResponder class or point your
 * browser at http://developer.apple.com/iphone/library/documentation/UIKit/Reference/UIResponder_Class/Reference/Reference.html.
 * @param touches A set of UITouch instances that represent the touches that are moving during the event represented by event.
 * @param event An object representing the event to which the touches belong.
 * @return YES to propagate the event to the map and NO if you don't want the touches moved to be executed.
 */
- (BOOL)interceptTouchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;

/**
 * Touches ended event.
 * Fired before the map touches ended event. For more detail on the touch events check the UIResponder class or point your
 * browser at http://developer.apple.com/iphone/library/documentation/UIKit/Reference/UIResponder_Class/Reference/Reference.html.
 * @param touches A set of UITouch instances that represent the touches for the ending phase of the event represented by event.
 * @param event An object representing the event to which the touches belong.
 * @return YES to propagate the event to the map and NO if you don't want the touches ended to be executed.
 */
- (BOOL)interceptTouchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;

/**
 * Touches cancelled event.
 * Fired before the map touches cancelled event. For more detail on the touch events check the UIResponder class or point your
 * browser at http://developer.apple.com/iphone/library/documentation/UIKit/Reference/UIResponder_Class/Reference/Reference.html.
 * @param touches A set of UITouch instances that represent the touches for the ending phase of the event represented by event.
 * @param event An object representing the event to which the touches belong.
 * @return YES to propagate the event to the map and NO if you don't want the touch began to be executed.
 */
- (BOOL)interceptTouchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;

@end
