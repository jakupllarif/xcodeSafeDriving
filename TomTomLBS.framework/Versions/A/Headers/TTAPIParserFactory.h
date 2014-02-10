//
//  @(#)TTAPIParserFactory.h 10/05/31
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
@class TTAPIParser;

/**
 * The response parser factory.
 * Contains the methods that return the concrete, adequate parsers for parsin each type of responses from the LBS services.
 * Internally, it could return XML or JSON parsers.
 */
@interface TTAPIParserFactory : NSObject {

}

/**
 * Returns the geocode parser.
 * Returns the geocode parser.
 * @return The geocode parser.
 */
+ (TTAPIParser *) geocodeParser;

/**
 * Returns the reverse-geocode parser.
 * Returns the reverse-geocode parser.
 * @return The reverse-geocode parser.
 */
+ (TTAPIParser *) reverseGeocodeParser;

/**
 * Returns the routing parser.
 * Returns the routing parser.
 * @return The routing parser.
 */
+ (TTAPIParser *) routingParser;

/**
 * Returns the traffic parser.
 * Returns the traffic parser.
 * @return The traffic parser.
 */
+ (TTAPIParser *) trafficParser;

/**
 * Returns the ViewPort Description parser.
 * Returns the ViewPort Description parser.
 * @return The ViewPort Description parser.
 */
+ (TTAPIParser *) viewportDescriptionParser;

/**
 * Returns the Initialize parser.
 * Returns the Initialize parser.
 * @return The Initialize parser.
 */
+ (TTAPIParser *) initializeParser;

@end
