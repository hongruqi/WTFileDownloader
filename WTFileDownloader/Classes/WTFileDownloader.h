//
//  XYDownloader.h
//  XYDownloader
//
//  Created by hongru qi on 28/10/2017.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, WTDownloaderOptions) {
    WTDownloaderLowPriority = 1 << 0,
    
    WTDownloaderProgressiveDownload = 1 << 1,
    
    /**
     * By default, request prevent the use of NSURLCache. With this flag, NSURLCache
     * is used with default policies.
     */
    WTDownloaderUseNSURLCache = 1 << 2,
    
    /**
     * Call completion block with nil image/imageData if the image was read from NSURLCache
     * (to be combined with `SDWebImageDownloaderUseNSURLCache`).
     */
    WTDownloaderIgnoreCachedResponse = 1 << 3,
    
    /**
     * In iOS 4+, continue the download of the image if the app goes to background. This is achieved by asking the system for
     * extra time in background to let the request finish. If the background task expires the operation will be cancelled.
     */
    WTDownloaderContinueInBackground = 1 << 4,
    
    /**
     * Handles cookies stored in NSHTTPCookieStore by setting
     * NSMutableURLRequest.HTTPShouldHandleCookies = YES;
     */
    WTDownloaderHandleCookies = 1 << 5,
    
    /**
     * Enable to allow untrusted SSL certificates.
     * Useful for testing purposes. Use with caution in production.
     */
    WTDownloaderAllowInvalidSSLCertificates = 1 << 6,
    
    /**
     * Put the image in the high priority queue.
     */
    WTDownloaderHighPriority = 1 << 7,
    
    /**
     * Scale down the image
     */
    WTDownloaderScaleDownLargeImages = 1 << 8,
};

typedef NS_ENUM(NSInteger, WTDownloaderExecutionOrder) {
    /**
     * Default value. All download operations will execute in queue style (first-in-first-out).
     */
    WTDownloaderFIFOExecutionOrder,
    
    /**
     * All download operations will execute in stack style (last-in-first-out).
     */
    WTDownloaderLIFOExecutionOrder
};

FOUNDATION_EXPORT NSString * _Nonnull const WTDownloadStartNotification;
FOUNDATION_EXPORT NSString * _Nonnull const WTDownloadStopNotification;

typedef void(^WTDownloaderProgressBlock)(NSInteger receivedSize, NSInteger expectedSize, NSURL * _Nullable targetURL);

typedef void(^WTDownloaderCompletedBlock)(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error, BOOL finished);

typedef NSDictionary<NSString *, NSString *> WTHTTPHeadersDictionary;
typedef NSMutableDictionary<NSString *, NSString *> WTHTTPHeadersMutableDictionary;

typedef WTHTTPHeadersDictionary * _Nullable (^WTDownloaderHeadersFilterBlock)(NSURL * _Nullable url, WTHTTPHeadersDictionary * _Nullable headers);

/**
 *  A token associated with each download. Can be used to cancel a download
 */
@interface WTDownloadToken : NSObject

@property (nonatomic, strong, nullable) NSURL *url;
@property (nonatomic, strong, nullable) id downloadOperationCancelToken;

@end

@interface WTFileDownloader : NSObject
/**
 *  Singleton method, returns the shared instance
 *
 *  @return global shared instance of downloader class
 */
+ (nonnull instancetype)sharedDownloader;

/**
 *  Set the default URL credential to be set for request operations.
 */
@property (strong, nonatomic, nullable) NSURLCredential *urlCredential;
/**
 * Set username
 */
@property (strong, nonatomic, nullable) NSString *username;

/**
 * Set password
 */
@property (strong, nonatomic, nullable) NSString *password;
/**
 * Set filter to pick headers for downloading image HTTP request.
 *
 * This block will be invoked for each downloading image request, returned
 * NSDictionary will be used as headers in corresponding HTTP request.
 */
@property (nonatomic, copy, nullable) WTDownloaderHeadersFilterBlock headersFilter;
/**
 * Changes download operations execution order. Default value is `SDWebImageDownloaderFIFOExecutionOrder`.
 */
@property (assign, nonatomic) WTDownloaderExecutionOrder executionOrder;
/**
 *  The timeout value (in seconds) for the download operation. Default: 15.0.
 */
@property (assign, nonatomic) NSTimeInterval downloadTimeout;

- (nullable WTDownloadToken *)downloadFileWithURL:(nullable NSURL *)url
                                          options:(WTDownloaderOptions)options
                                         progress:(nullable WTDownloaderProgressBlock)progressBlock
                                        completed:(nullable WTDownloaderCompletedBlock)completedBlock;
@end
