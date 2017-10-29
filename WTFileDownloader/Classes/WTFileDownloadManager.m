//
//  WTFileDownloadManager.m
//  WTFileDownloader
//
//  Created by hongru qi on 29/10/2017.
//

#import "WTFileDownloadManager.h"

@implementation WTFileDownloadManager
//http://hybrid.xiaoying.tv/vcm/20171026/15351414/0x01000000000000BF.zip
//http://hybrid.xiaoying.tv/template/vivavideo/20170517/20180505/0x010000000000009D.zip
- (void)loadImageWithURL:(nullable NSURL *)url
                progress:(nullable WTDownloaderProgressBlock)progressBlock
               completed:(nullable SDInternalCompletionBlock)completedBlock {
    
    NSURL *loaderUrl = [NSURL URLWithString:@"http://hybrid.xiaoying.tv/vcm/20171026/15351414/0x01000000000000BF.zip"];
    
    [[WTFileDownloader sharedDownloader] downloadFileWithURL:loaderUrl options:WTDownloaderHighPriority progress:^(NSInteger receivedSize, NSInteger expectedSize, NSURL * _Nullable targetURL) {
        NSLog(@"receiveed size = %d", receivedSize);
    } completed:^(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error, BOOL finished) {
        
    }];
    
}

@end
