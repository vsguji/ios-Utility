//
//  VPFileManager+Extension.h
//  Utility
//
//  Created by lipeng on 2017/3/5.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import "VPFileManager.h"

@interface VPFileManager (Extension)

/**
 *  获取缓存目录
 *
 *  @return
 */
- (NSString *)dirCache;

/**
 *  获取临时目录
 *
 *  @return
 */
- (NSString *) dirTmp;

/**
 *  获取根目录
 *
 *  @return
 */
- (NSString *) dirHome;

@end
    