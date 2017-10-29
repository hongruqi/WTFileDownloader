//
//  XYDownloadManager.h
//  XYDownloader
//
//  Created by hongru qi on 29/10/2017.
//

#import <Foundation/Foundation.h>
#import "WTFileDownloader.h"

typedef void(^SDInternalCompletionBlock)(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error, int cacheType, BOOL finished, NSURL * _Nullable imageURL);

@interface WTFileDownloadManager : NSObject

- (void)loadImageWithURL:(nullable NSURL *)url
                progress:(nullable XYDownloaderProgressBlock)progressBlock
               completed:(nullable SDInternalCompletionBlock)completedBlock;

@end
