//
//  NSDta+DES.h
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//
#import <Foundation/Foundation.h>

@interface NSString(DES)

/*字符串加密
 *参数
 *plainText : 加密明文
 *key        : 密钥 64位
 */
+ (NSString *) encryptUseDES:(NSString *)plainText key:(NSString *)key; // 加密

/*字符串加密
 *参数
 *plainText : 加密暗文
 *key        : 密钥 64位
 */
+ (NSString *) decryptUseDES:(NSString*)cipherText key:(NSString*)key; // 解密

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//iOS des加密 转码16进制字符串

/*字符串加密
 *参数
 *plainText : 加密明文
 *key        : 密钥 64位
 */

+(NSString *) encryptUseDES2:(NSString *)plainText key:(NSString *)key; // 加密

/*字符串加密
 *参数
 *plainText : 加密暗文
 *key        : 密钥 64位
 */
+(NSString *) decryptUseDES2:(NSString *)plainText key:(NSString *)key; // 解密

@end
