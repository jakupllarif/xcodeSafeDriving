//
//  @(#)TTAPIBaseData.h 10/07/07
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>

/**
 * Defines the base class for all data objects used to contain the data fetched from the LBS.
 * Defines common error handling methods.
 */
@interface TTAPIBaseData : NSObject {
    BOOL success;
    NSString* errorMessage;
    NSInteger errorCode;
    
    NSException* exception;
    NSError* exceptionError;
}

/** 
 * If the operation was a success or not. 
 * Default value when success is YES, is 0.
 */
@property ( nonatomic ) BOOL success;
/**
 * When success == NO, this will contain the error message retrieved from the server.
 * Default value when success is YES, is nil.
 */
@property (nonatomic, retain) NSString* errorMessage;
/**
 * When success == NO, this will contain the error code retrieved from the server.
 * Default value when success is YES, is nil.
 */
@property NSInteger errorCode;
/**
 * When success == NO, this will contain the exception generated accessing the server.
 * Default value when success is YES, is nil.
 */
@property (nonatomic, retain) NSException* exception;
/**
 * When success == NO, this will contain the error associated with the exception.
 * Default value when success is YES, is nil.
 */
@property (nonatomic, retain) NSError* exceptionError;


/**
 * Inits the class and sets the success to YES.
 * @return the new instance.
 */
-(id) init;

/**
 * Inits the class and sets the success to NO.
 * @param theException The exception with which to init the instance.
 * @param theExceptionError The error associated with the exception.
 * @return the new instance
 */
-(id) initWithException:(NSException*)theException andError:(NSError*)theExceptionError;

/**
 * Inits the class and sets the success to NO.
 * @param theErrorCode The error code with which to init the instance.
 * @param theErrorMessage The error message with which to init the instance.
 * @return the new instance
 */
-(id) initWithErrorCode:(NSInteger)theErrorCode andErrorMessage:(NSString*)theErrorMessage;

/**
 * Copies the errors, if any, to the data object passed by argument.
 * @param otherDataObject The receiver of the errors.
 **/
-(void) copyErrorsTo:(TTAPIBaseData*) otherDataObject;

@end

