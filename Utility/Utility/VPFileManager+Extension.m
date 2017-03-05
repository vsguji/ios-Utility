//
//  VPFileManager+Extension.m
//  Utility
//
//  Created by lipeng on 2017/3/5.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import "VPFileManager+Extension.h"

@implementation VPFileManager (Extension)

- (NSString *)dirCache {
    NSArray * cacPath = NSSearchPathForDirectoriesInDomains(NSCachesDirectory,NSUserDomainMask,YES);
    NSString * cachePath = [cacPath objectAtIndex:0];
    return cachePath;
}

- (NSString *) dirTmp {
    NSString * tmpDirectory = NSTemporaryDirectory();
    return  tmpDirectory;
}

- (NSString *) dirHome {
    NSString * dirHome = NSHomeDirectory();
    return dirHome;
}

@end
