//
//  @(#)TTSDKImageUtils.h 10/08/09
//  
//  MobileSDK
//
//  Copyright (c) 2010 TomTom International B.V. All rights reserved. TomTom
//  PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface TTSDKImageUtils : NSObject {

}

/*
 * Returns a mosaic with the images passed by argument.
 * Assumes all images have the same size.
 * @param imageList List of image that should be joined together.
 * @param nCols Number of columns in the rectangle that should be formed by the list of images passed by parameter.
 * @param nRows Number of row in the rectangle that should be formed by the list of images passed by parameter.
 * @param croppedTo Rectangle that will be used to determine the part of the resulting image (from the union of 
 * the images passed by parameter) that will be cut and returned.
 * @return A part of the image that resulted from the union of all images passed by parameter. That part is defined by 
 * the croppedBy parameter.  
 */
+(NSData*) getMosaicWithImages:(NSMutableArray*)imagesList andNCols:(NSInteger)nCols andNRows:(NSInteger)nRows croppedTo:(CGRect)cropRect;

@end
