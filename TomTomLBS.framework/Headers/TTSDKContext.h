//
//  @(#)TTSDKContext.h 10/05/24
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import "TTSDKUtils.h"
#import "NTReachability.h"
#import "RMConfiguration.h"

/**
 * The SDK context.
 * Serves to share general application data between different classes of the SDK and application, like for example the Developer Key.
 * On application initialization, this context must be set with the Developer Key before any SDK usage.
 */
@interface TTSDKContext : NSObject {
	@private
	NSString *key;
	// TODO this should be temporary - sould be relocated to a better place
    NSString *tileStyle;	
    
    NSString *geocodeVersion;
    
	NSOperationQueue * sharedOperationQueue;
    
    NTReachability* ntReachability;
	
	NSMutableArray *wmsTilesServerUrlArray;
	NSMutableArray *integerTilesServerUrlArray;
	NSString *lbsURL;
    
    // Dictionary to hold the POIs Categories.
    NSDictionary *poiCategories;
}

/* The application operation queue. Each time the application needs to execute code in an async way, it
 does so using a NSOperation object dispatched to this queue. Check the dispatchOperation method. */
@property (nonatomic, retain) NSOperationQueue * sharedOperationQueue;

/* Property used to check if we have network reachability or not */
@property (nonatomic, retain) NTReachability* ntReachability;

/* Property used to keep the WMS Tile server URLs */
@property (nonatomic, retain) NSMutableArray *wmsTilesServerUrlArray;

/* Property used to keep the Intger Tile server URLs */
@property (nonatomic, retain) NSMutableArray *integerTilesServerUrlArray;

/* Property used to keep the LBS API server URL */
@property (nonatomic, retain) NSString *lbsURL;

/* Property to store the POIs categories. They are read from a text file
 * and it is initialized only when used the first time
 */
@property (nonatomic, retain) NSDictionary *poiCategories;

/**
 * Returns the SDK shared context.
 * The context is lazy loaded. It will be created at first get.
 * @return The SDK shared context.
 */
+ (TTSDKContext *) sharedContext;

/**
 * Checks if we have network connection to the host and what type of connection.
 * @param hostName The destination Host Name.
 * @return The status of the reachability.
 */
- (NTReachabilityStatus) getRemoteServerReachabilityStatus:(NSString*)hostName;

/**
 * Checks how do we connect to the internet.
 */
- (NTReachabilityStatus) getInternetConnectionStatus;

/**
 * Sets the developer key.
 * Sets and validates the developer key. If the key is invalid, an exception is raised.
 * @param aKey The developer key.
 */
- (void) setDeveloperKey:(NSString *)aKey;

/**
 * Sets the tile style.
 * Sets and construct the parameter to be appended to the URL.
 * @param aStyle The Tile Style.
 */
- (void) setTileStyle:(int)aStyle;

/**
 * Sets the Geocode version for geocode operations
 */
- (void) setGeocodeVersion:(int)version;

/**
 * Gets the current geocode version.
 * By default is "1"
 */
-(NSString *) getGeocodeVersion;

/**
 * Gets the developer key.
 * @return The developer key.
 */
- (NSString *) getDeveloperKey;

/**
 * Gets the Current Tile Style , S1 or S2.
 * @return The Style string to be appended to the URL : ";s=s1" or ";s=s2"
 */
- (NSString *) getCurrentTileStyle;

/**
 * Gets the base URL of the LBS services. There is no '/' in the end of the returned URL.
 * @return The base URL of the LBS services, with no '/' at the end.
 */
-(NSString*) getLBSBaseURL;

/**
 * Dispatch an operation to the shared queue.
 * Each time the application needs to execute code in an async way, it
 * does so using a NSOperation object dispatched to the queue. This method does that.
 * @param operation The operation to execute.
 */
- (void) dispatchOperation:(NSOperation *) operation;

/**
 * Set the maximum number of concurrent operations that can be executed when using the SDK's default operations queue. -1 is the default value which
 * lets the iOS manage the number of operations.
 * @param maxConcOperations The maximum number of concurrent operations.
 */
- (void) setMaximumConcurrentOperations: (NSInteger) maxConcOperations;

/**
 * Returns the maximum number of concurrent operations for the default operations queue of the SDK. -1 is the default value which
 * lets the iOS manage the number of operations.
 * @return The maximum number of concurrent operations.
 */
- (NSInteger) getMaximumConcurrentOperations;

/*
 Set is the developer wants to disable the DB cache
 */
- (void) setDisableDBCache: (BOOL) disable;

/**
 * Return the dictionary of Poi Categories.
 */
-(NSDictionary*) getPoiCategories;

/*
 Return if the DB cache is disabled.
 */
- (BOOL) getDisableDBCache;

- (double) getDBCacheAvgTime;

@end
