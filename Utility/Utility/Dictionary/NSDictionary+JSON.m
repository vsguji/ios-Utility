//
//  NSDictionary+JSON.m
//  Utility
//
//  Created by lipeng on 2017/3/11.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import "NSDictionary+JSON.h"

@implementation NSDictionary (JSON)
+ (NSData *)toJSONData{
    
    NSError *error = nil;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:self
                                                       options:NSJSONWritingPrettyPrinted
                                                         error:nil];
    
    if ([jsonData length] && error == nil){
        return jsonData;
    }else{
        return nil;
    }
}

@end
