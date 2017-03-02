//
//  CryptorTools.h
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CryptorToolsRSA : NSObject
#pragma mark - RSA 加密/解密算法
///  加载公钥
///
///  @param filePath DER 公钥文件路径
- (void)loadPublicKeyWithFilePath:(NSString *)filePath;

///  加载私钥
///
///  @param filePath P12 私钥文件路径
///  @param password P12 密码
- (void)loadPrivateKey:(NSString *)filePath password:(NSString *)password;

///  RSA 加密数据
///
///  @param data 要加密的数据
///
///  @return 加密后的二进制数据
- (NSData *)RSAEncryptData:(NSData *)data;

///  RSA 加密字符串
///
///  @param string 要加密的字符串
///
///  @return 加密后的 BASE64 编码字符串
- (NSString *)RSAEncryptString:(NSString *)string;

///  RSA 解密数据
///
///  @param data 要解密的数据
///
///  @return 解密后的二进制数据
- (NSData *)RSADecryptData:(NSData *)data;

///  RSA 解密字符串
///
///  @param string 要解密的 BASE64 编码字符串
///
///  @return 解密后的字符串
- (NSString *)RSADecryptString:(NSString *)string;

@end
