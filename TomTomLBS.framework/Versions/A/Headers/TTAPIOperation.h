//
//  @(#)TTAPIOperation.h 10/05/27
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTSDKExceptions.h"

@class TTAPIParser;
@class TTAPIBaseData;

/**
 * The base API operation.
 */
@interface TTAPIOperation : NSOperation {

@protected
	NSString * url;
	id delegate;
	id payload;
    // Use for metrics
    id logKey;
	NSObject * _data;
}

/* The operation request URL. */
@property (nonatomic, retain, readonly) NSString * url;
/* The operation delegate for asynchronous notifications. */
@property (nonatomic, retain) id delegate;
@property (nonatomic, retain) id payload;
@property (nonatomic, retain) id logKey;
/**
 * Creates a new TTAPIOperation instance.
 * Creates a new TTAPIOperation instance for a given query.
 * @param query Mandatory parameters query.
 * @return The new instance.
 */
- (id) initWithQuery:(NSString *)query;

/**
 * Creates a new TTAPIOperation instance.
 * Creates a new TTAPIOperation instance for a given query and options.
 * @param query Mandatory parameters query.
 * @param optional The optional parameters query. Supports nil, meaning no optional parameters
 * @return The new instance.
 */
- (id) initWithQuery:(NSString *)query andOptionalParameters:(NSString *)optional;

/**
 * Template method to get the concrete parser that each operations uses.
 * This is part of the strategy method main.
 * @returns The concrete parser.
 */
-(TTAPIParser*) getParser;

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

/**
 * Method called by the strategy method main to invoke the delegate after the data.
 */
-(void) callDelegate;

/**
 * Template method to get the template URL.
 * The URL must contain a tag ${apiKey} to be replaced by the SDK's key.
 * @return The template URL
 */
-(NSString*) getTemplateUrl;

/**
 * Template method to replace any extra parameters in the URL.
 * By default replaces ${query} with the value in query.
 * If the query is nil it does not perform any replacement. An empty string can be used as input.
 * @param request String in which the replacement will take place. Already has the SDK's api key.
 * @param query The query value passed by parameter to the init method.
 * @return The concrete URL, fully parameterized.
 */
-(NSString*) replaceExtraParameters:(NSString*)request withQuery:(NSString*)query;

@end
