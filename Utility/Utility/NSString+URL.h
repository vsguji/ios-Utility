//
//  NSString+URL.h
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (URL)
+ (NSString *)encodeToPercentEscapeString:(NSString *)input; //加密
+ (NSString *)decodeFromPercentEscapeString:(NSString *)input; // 解密
@end
