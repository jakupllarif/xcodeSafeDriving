#import <Foundation/Foundation.h>

//
//got from http://www.cocoadev.com/index.pl?NSDataCategory
//
@interface NSDataCompressionWrapper : NSObject {
	NSData *data;
}


@property (nonatomic, retain) NSData *data;


//the data to be used as base
- (id) initWithData:(NSData*)_data;


// Returns range [start, null byte), or (NSNotFound, 0).
- (NSRange) rangeOfNullTerminatedBytesFrom:(int)start;

/*// Canonical Base32 encoding/decoding.
+ (NSData *) dataWithBase32String:(NSString *)base32;
- (NSString *) base32String;
*/

// COBS is an encoding that eliminates 0x00.
- (NSData *) encodeCOBS;
- (NSData *) decodeCOBS;

// ZLIB
- (NSData *) zlibInflate;
- (NSData *) zlibDeflate;

// GZIP
- (NSData *) gzipInflate;
- (NSData *) gzipDeflate;

//CRC32
- (unsigned int)crc32;

- (NSString *) base64Encoding;
- (NSString *) base64EncodingWithLineLength:(NSUInteger)lineLength;

/*
// Hash
- (NSData*) md5Digest;
- (NSString*) md5DigestString;
- (NSData*) sha1Digest;
- (NSString*) sha1DigestString;
- (NSData*) ripemd160Digest;
- (NSString*) ripemd160DigestString;
*/
@end