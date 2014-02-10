//
//  TTSDKMetrics.h
//  MobileSDK
//
//  Created by JJ Rojas on 1/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RMConfiguration.h"
#import "TTSDKLogRecord.h"
#import <sqlite3.h>

@class FMDatabase;

typedef enum {
    RecordType_User = 0,
    RecordType_Cache = 1,
    RecordType_Geocode = 2,
    RecordType_ReverseGeocode = 3,
    RecordType_Traffic = 4,
    RecordType_Route = 5,
    RecordType_Map_Tile = 6,
    RecordType_Traffic_Tile = 7,
    RecordType_Route_Tile = 8,
    RecordType_Network = 9,
    RecordType_Parser = 10,
    RecordType_FPS = 11,
    RecordType_Layer = 12
} TTSDK_RECORD_TYPE;

/**
* Convers a TTSDK_RECORD_TYPE into its String equivalent.
*/
__attribute__((visibility("default")))NSString * const TTLogType_toString[13];

@interface TTSDKMetricsKeyWrapper: NSObject {
    id object;
}
@property (nonatomic,retain) id object;
@end

/**
 * TTSDKMetrics. Class to access the log and measurements of different functions of the SDK.
 * It contains access to a SQLite database which store the different results of operations
 * specified by the user.
 *
 * All methods must accessed using the singleton.
 *
 */
@interface TTSDKMetrics : NSObject <RMLogCacheDelegate> {
    BOOL active;
    int  totalRecordCount;
    
    // Database variables
	NSString *databaseName;
	NSString *databasePath;
    NSString *device;
    NSString *appid;
    NSString *network;
    NSString *udid;
    
    // APP Logs in process.
    NSMutableDictionary *appLogs;
    
    sqlite3 *database;
    
}

@property (nonatomic,assign) BOOL active;
@property (nonatomic,retain) NSString *databaseName;
@property (nonatomic,retain) NSString *databasePath;
@property (nonatomic,retain) NSString *device;
@property (nonatomic,retain) NSString *appid;
@property (nonatomic,retain) NSString *network;
@property (nonatomic,retain) NSString *udid;
@property (nonatomic,retain) NSMutableDictionary *appLogs;
@property (nonatomic)        sqlite3 *database;

// Returns the current singleton of the TTSDKMetrics.
+ (TTSDKMetrics *) currentInstance;

// NO DESCRIPTION
-(void) checkAndCreateDatabase;

/**
 * Will start a log to record with a type. It will return the unique key that 
 * you must use to stop the log.
 */
- ( id ) startLogWithType: (TTSDK_RECORD_TYPE)type  andDescription:(NSString *)desc;
- ( id ) startLogWithType: (TTSDK_RECORD_TYPE)type  andDescription:(NSString *)desc andKey:(id)key;

/**
 * Stop the log and create the record in the DB for this key.
 */
- (void) stopLogWithKey: (id) key;

/**
 * Get all the records from the DB. Can be big, so be careful.
 */
- (NSArray *) getRecords;

/**
 * Generates the XML data for the given records.
 */
- (NSString*) generateXMLString:(NSArray*)records;

/**
 * Compress the NSDATA to ZIP.
 */
- (NSData *) compressToZip:(NSData *)source;

/**
 * Dump all the records from the database to the console in a formatted manner.
 */
- ( void ) dumpDB2Console;

/**
 * This will connect to "sdk.metrics.server" and upload the DB file
 */
- (void) uploadDB;

/**
 * Delete all records in the DB
 */
- (void ) purgeDB;

/**
 * Save all records to DB
 */
- (void) saveRecords;
- (void) storeRecordInLog:( TTSDKLogRecord *)record;
- (void) setNetworkValue;

/*
// NS URL CONNECTION DELEGATE
- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response;
- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error;
- (void)connection:(NSURLConnection *)connection didSendBodyData:(NSInteger)bytesWritten totalBytesWritten:(NSInteger)totalBytesWritten totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite;
- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data;
- (void)connectionDidFinishLoading:(NSURLConnection *)connection;
*/

- (void) receiveNetworkNotification:(NSNotification *) notification;

- (NSString*) getPlatformString;

@end

#if METRICS_ENABLED
/////
// category to work around self-signed certificates
// WARNING: this is private API, should be enabled just
// for the PERFORMANCE METRICS TEST
@interface NSURLRequest (IgnoreSSL)

+ (BOOL)allowsAnyHTTPSCertificateForHost:(NSString*)host;

@end

#endif
