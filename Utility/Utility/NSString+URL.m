//
//  NSString+URL.m
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import "NSString+URL.h"

@implementation NSString (URL)

#pragma mark - 加密

+ (NSString *)encodeToPercentEscapeString: (NSString *) input

{
    NSString *outputStr =
    (__bridge NSString *)CFURLCreateStringByAddingPercentEscapes(
                                                                 NULL, /* allocator */
                                                                 (__bridge CFStringRef)input,
                                                                 NULL, /* charactersToLeaveUnescaped */
                                                                 (CFStringRef)@"!*'();:@&=+$,/?%#[]",
                                                                 kCFStringEncodingUTF8);
    
    return outputStr;
}

#pragma mark - 解码

+ (NSString *)decodeFromPercentEscapeString: (NSString *) input

{
    NSMutableString *outputStr = [NSMutableString stringWithString:input];
    [outputStr replaceOccurrencesOfString:@"+"
                               withString:@""
                                  options:NSLiteralSearch
                                    range:NSMakeRange(0,[outputStr length])];
    
    return [outputStr stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
}

@end
