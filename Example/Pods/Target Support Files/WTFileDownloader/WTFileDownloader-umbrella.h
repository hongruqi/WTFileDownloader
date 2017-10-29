#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "WTFileDownloader.h"
#import "WTFileDownloaderOperation.h"
#import "WTFileDownloadManager.h"
#import "XYDownloadManager.h"

FOUNDATION_EXPORT double WTFileDownloaderVersionNumber;
FOUNDATION_EXPORT const unsigned char WTFileDownloaderVersionString[];

