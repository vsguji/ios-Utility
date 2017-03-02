//
//  VPIdentityCard.m
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import "VPIdentityCard.h"

@implementation VPIdentityCard


- (NSString *)birthdayFromIdentityCard:(NSString *)IDStr;
{
    NSMutableString *result = [NSMutableString stringWithCapacity:0];
    NSString *year = nil;
    NSString *month = nil;
    
    BOOL isAllNumber = YES;
    NSString *day = nil;
    if([IDStr length]<14)
        return result;
    
    //**截取前14位
    NSString *fontNumer = [IDStr substringWithRange:NSMakeRange(0, 13)];
    
    //**检测前14位否全都是数字;
    const char *str = [fontNumer UTF8String];
    const char *p = str;
    while (*p!='\0') {
        if(!(*p>='0'&&*p<='9'))
            isAllNumber = NO;
        p++;
    }
    if(!isAllNumber)
        return result;
    
    year = [IDStr substringWithRange:NSMakeRange(6, 4)];
    month = [IDStr substringWithRange:NSMakeRange(10, 2)];
    day = [IDStr substringWithRange:NSMakeRange(12,2)];
    
    [result appendString:year];
    [result appendString:@"-"];
    [result appendString:month];
    [result appendString:@"-"];
    [result appendString:day];
    return result;
}


- (NSString *)getSexIdentityCard:(NSString *)IDStr;
{
    int sexInt=[[IDStr substringWithRange:NSMakeRange(16,1)] intValue];
    
    if(sexInt %2!=0 )
    {
        return @"1";
    }
    else
    {
        return @"2";
    }
}

@end
