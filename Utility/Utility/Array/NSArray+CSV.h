//
//  NSArray+CSV.h
//  Utility
//
//  Created by lipeng on 2017/3/11.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (CSV)
+ (NSArray *)arrayWithContentOfSimpleCsvFile:(NSString *)path;
@end
