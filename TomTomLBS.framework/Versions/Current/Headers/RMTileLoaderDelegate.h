//
//  RMTileLoaderDelegate.h
//  MapView
//
//  Created by JJ Rojas on 11/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RMTileImage.h"

@interface RMTileLoaderDelegate : NSObject {
    RMTileImage *tileImage;
    NSURLRequest *myRequest;
    NSURLConnection *myConnection;
    NSMutableData *myData;
    int retries;
    NSString *url; // a saved copy of the URL
}

- (void)openConnection;
- (void)setTileImage: (RMTileImage *)image withRequest: (NSURLRequest*)request;
- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response;
- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data;
- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error;
- (void)connectionDidFinishLoading:(NSURLConnection *)connection;
- (void)releaseEverything;
@end
