//
//  @(#)TTAPIJSONParser.h 10/06/18
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTAPIParser.h"

/**
 * Base class for all JSON parsers.
 * Implements the strategy for parsing the JSON responses and defines a template method for specific data handling.
 */
@interface TTAPIJSONParser : TTAPIParser {

}

/**
 * The parse template method for concrete parsers to implement.
 * Converts a data object to the appropriate response object. It is the implementer's responsability to 
 * return the correct response object (data objects).
 * @param json The JSON data as pre-parsed by the parseNSData method.
 * @return The response object.
 */
- (id) parseNSDictionary:(NSDictionary*) json;

@end
