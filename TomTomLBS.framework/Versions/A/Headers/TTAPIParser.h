//
//  @(#)TTAPIParser.h 10/05/28
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <UIKit/UIKit.h>

@class TTAPIBaseData;

/**
 * The API parser protocol.
 * Every parser is expected to comply with this protocol. It defines the parser method.
 */
@interface TTAPIParser : NSObject {
}

/**
 * The parse method strategy.
 * Converts a data object into a response object.
 * @param data The response data.
 * @param error The error holder. If there's an error parsing the data, this pointer will reference an error instance.
 * @return The response object.
 */
- (id) parseNSData:(NSData*)data error:(NSError**)error;

/**
 * Builds the concrete data object that the client is expecting, allowing to return the correct data type instead
 * of just the base class. The success field should be set to NO.
 * @param errorCode The error code to be set in the data object.
 * @param errorMessage The error message to be set in the data object.
 * @return The concrete data object with success=NO and the correct error message and code.
 */
-(TTAPIBaseData*) getConcreteDataObjectWithErrorCode:(NSInteger)errorCode andMessage:(NSString*)errorMessage;

/**
 * Builds the concrete data object that the client is expecting, allowing to return the correct data type instead
 * of just the base class. The success field should be set to NO.
 * @param theException The exception to be set in the data object.
 * @param theExceptionError The exception error to be set in the data object.
 * @return The concrete data object with success=NO and the correct exception and error.
 */
-(TTAPIBaseData*) getConcreteDataObjectWithException:(NSException*)theException andError:(NSError*)theExceptionError;

@end
