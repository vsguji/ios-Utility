//
//  NSString+JSONVALUE.m
//  Utility
//
//  Created by lipeng on 2017/3/11.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import "NSString+JSONVALUE.h"

@implementation NSString (JSONVALUE)

-(id)JSONValue;
{
    NSData* data = [self dataUsingEncoding:NSUTF8StringEncoding];
    __autoreleasing NSError* error = nil;
    id result = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
    if (error != nil) return nil;
    return result;
}

@end
