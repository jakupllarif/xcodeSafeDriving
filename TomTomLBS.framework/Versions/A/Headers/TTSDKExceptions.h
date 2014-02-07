//
//  @(#)TTSDKExceptions.h 10/06/01
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>

/**
 * Exception passed by parameter when an operation is unable to connect to the host in a async communication.
 */
extern NSString * const TTSDKNetworkRequestException;

/**
 * Exception raised when there is an error while parsing a response from a host.
 */
extern NSString * const TTSDKResponseParsingException;

/**
 * Exception raised when trying to use a parameter with an invalid value.
 */
extern NSString * const TTSDKInvalidParameterException;

/**
 * Exception raised when a cache configuration object is used to try to configure a source's cache.
 */
extern NSString * const TTSDKCacheConfigurationException;;
