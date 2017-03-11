//
//  NSArray+CSV.m
//  Utility
//
//  Created by lipeng on 2017/3/11.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import "NSArray+CSV.h"

@implementation NSArray (CSV)

+ (NSArray *)arrayWithContentOfSimpleCsvFile:(NSString *)path{

    @autoreleasepool {
        NSString * content = [[NSString alloc] initWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
        NSArray * rows = [content componentsSeparatedByCharactersInSet:[NSCharacterSet newlineCharacterSet]];
        NSUInteger rowsCount = rows.count;
        NSMutableArray * result = [[NSMutableArray alloc] initWithCapacity:rowsCount];
        for (NSInteger idx = 0; idx < rowsCount; ++idx) {
            NSString * row = [rows objectAtIndex:idx];
            if ([row length] > 0) {
                @autoreleasepool {
                    NSArray * columns = [row componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@","]];
                    [result addObject:columns];
                }
            }
        }
        return result;
    }
}

@end
