//
//  WTViewController.m
//  WTFileDownloader
//
//  Created by Walter on 10/29/2017.
//  Copyright (c) 2017 Walter. All rights reserved.
//

#import "WTViewController.h"
#import "WTFileDownloadManager.h"

@interface WTViewController ()
@property (nonatomic, strong) WTFileDownloadManager *manager;
@end

@implementation WTViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.manager = [[WTFileDownloadManager alloc] init];
    [self.manager loadImageWithURL:@"" progress:^(NSInteger receivedSize, NSInteger expectedSize, NSURL * _Nullable targetURL) {
        
    } completed:^(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error, int cacheType, BOOL finished, NSURL * _Nullable imageURL) {
        
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
