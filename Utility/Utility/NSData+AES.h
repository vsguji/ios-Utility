//
//  NSData+AED.h
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (AES)

- (NSData *)AES256EncryptWithKey:(NSString *)key;   //加密
- (NSData *)AES256DecryptWithKey:(NSString *)key;   //解密

@end
