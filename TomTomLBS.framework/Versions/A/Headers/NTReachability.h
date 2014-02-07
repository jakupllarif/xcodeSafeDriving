#import <SystemConfiguration/SystemConfiguration.h>

@class NTReachability;

/**
 * The reachability interface.
 */
@interface NTReachability : NSObject {
        
	BOOL networkStatusNotificationsEnabled;
 	
	NSString * hostname;
   	NSString * address;

	NSMutableDictionary * reachabilityQueries;
}

/**
 * An enumeration that defines the return values of the network state of the device.
 */
typedef enum {
	NotReachable 						= 0,
	ReachableViaCarrierDataNetwork 		= 1,
	ReachableViaWiFiNetwork				= 2
} NTReachabilityStatus;

/**
 * Set to YES to register for changes in network status. Otherwise reachability queries
 * will be handled synchronously.
 */ 
@property BOOL networkStatusNotificationsEnabled;

/** 
 * The remote host whose reachability will be queried.
 * Either this or 'ipAddress' must be set.
 */
@property (nonatomic, copy) NSString * hostname;

/**
 * The IP address of the remote host whose reachability will be queried.
 * Either this or 'hostName' must be set.
 */ 
@property (nonatomic, copy) NSString * address;

/**
 * A cache of ReachabilityQuery objects, which encapsulate SCNetworkReachabilityRef, 
 * a host or address, and a run loop. The keys are host names or addresses. 
 */
@property (nonatomic, assign) NSMutableDictionary * reachabilityQueries;

/**
 * Single shared instance of the NTReachability class.This class is meant be used as a singleton.
 *
 * Clients of Reachability should call @code[[Reachability sharedReachability] setHostName:]@endcode
 * before invoking other methods.
 * @return The NTReachability shared instance.
 */
+ (NTReachability *)sharedReachability;

/**
 * Is self.hostname is not nil, determines its reachability.
 * If self.hostname is nil and self.address is not nil, determines the reachability of self.address.
 * @return The remote reachability status.
 */
- (NTReachabilityStatus)remoteHostStatus;

/*!
 Is the device able to communicate with Internet hosts? 
 If so, through which network interface?
 * @return The internet reachability status.
 */
- (NTReachabilityStatus)internetConnectionStatus;

/**
 * Is the device able to communicate with hosts on the local WiFi network? 
 * (Typically these are Bonjour hosts).
 * @return The local wifi reachability status.
 */
- (NTReachabilityStatus)localWiFiConnectionStatus;

/**
 * When reachability change notifications are posted, the callback method 'ReachabilityCallback' is 
 * called and posts a notification that the client application can observe to learn about changes.
 * ReachabilityCallback is registered as the callback for network state changes in 
 * %startListeningForReachabilityChanges method.
 * @param target The reachability target.
 * @param flags The reachability flags.
 * @param info Info passed to the callback.
 */
static void ReachabilityCallback(SCNetworkReachabilityRef target, 
                                 SCNetworkReachabilityFlags flags, 
                                 void *info);

@end 	// end of NTReachability interface

/**
 * Represents a reachability query.
 */
@interface ReachabilityQuery : NSObject {
    
@private
	SCNetworkReachabilityRef 	reachabilityRef;
	CFMutableArrayRef 			runLoops;
	NSString * 					hostnameOrAddress;
};

/** 
 * Keep around each network reachability query object so that we can
 * register for updates.
 */
@property (nonatomic) SCNetworkReachabilityRef reachabilityRef;

/**
 * Hostname or IP address that this query is polling.
 * Will act as the dictionary key.
 */
@property (nonatomic, retain) NSString * hostnameOrAddress;

/**
 * An array of run loops.
 */
@property (nonatomic) CFMutableArrayRef runLoops;

/**
 * Set this query to be scheduled to run in a loop.
 * Set this query to be scheduled to run in a loop.
 * @param inRunLoop The run loop.
 */
- (void)scheduleOnRunLoop:(NSRunLoop *)inRunLoop;

@end
