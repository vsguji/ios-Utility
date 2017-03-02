//
//  CryptorTools.m
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//  摘录 http://www.cnblogs.com/liyy2015/p/5981472.html

// libopenssl库  、 Securiry.framework 都可以实现  libopenssl更加灵活

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1.生成RSA密钥
//
//生成RSA私钥
//openssl genrsa -out rsa_private_key.pem 1024
//生成RSA公钥
//openssl rsa -in rsa_private_key.pem -pubout -out rsa_public_key.pem
//pem文件可以直接文本编辑器打开
//将RSA私钥转换成PKCS8格式
//openssl pkcs8 -topk8 -inform PEM -in private_rsa.pem -outform PEM -nocrypt -out private_key.pem （后边一定要加-out private_key.pem将转换后的私钥保存在private_key.pem，不然得到的结果要设置密码且显示在终端中，这个和得到pem中的私钥有差异。）


// 2.
//在这里只介绍客户端如何对密码进行公钥加密和解密
//
//首先打开终端生成公钥和私钥（要有openSSL工具）
//
//openssl genrsa -out private_key.pem 1024
//
//openssl req -new -key private_key.pem -out rsaCertReq.csr
//
//openssl x509 -req -days 3650 -in rsaCertReq.csr -signkey private_key.pem -out rsaCert.crt
//
//openssl x509 -outform der -in rsaCert.crt -out public_key.der
//
//openssl pkcs12 -export -out private_key.p12 -inkey private_key.pem -in rsaCert.crt
//openssl rsa -in private_key.pem -out rsa_public_key.pem -pubout
//
//openssl pkcs8 -topk8 -in private_key.pem -out pkcs8_private_key.pem -nocrypt


//在第二步的时候输入密钥的信息，包括密码,请记住你输入的密码
//上面的命令会生成7个文件，IOS用到的是public_key.der和private_key.p12
//导入到项目中不要直接拖拽进去，而是点击Xcode右下角的+号，选择add files to ""
//新建项目后添加库：Security.framework


#import "CryptorToolsRSA.h"
#import <CommonCrypto/CommonCrypto.h>

// 填充模式
#define kTypeOfWrapPadding		kSecPaddingPKCS1

@interface CryptorToolsRSA(){
    SecKeyRef _publicKeyRef;                             // 公钥引用
    SecKeyRef _privateKeyRef;                            // 私钥引用
}

@end

@implementation CryptorToolsRSA

#pragma mark - RSA 加密/解密算法
- (void)loadPublicKeyWithFilePath:(NSString *)filePath; {
    
    NSAssert(filePath.length != 0, @"公钥路径为空");
    
    // 删除当前公钥
    if (_publicKeyRef) CFRelease(_publicKeyRef);
    
    // 从一个 DER 表示的证书创建一个证书对象
    NSData *certificateData = [NSData dataWithContentsOfFile:filePath];
    SecCertificateRef certificateRef = SecCertificateCreateWithData(kCFAllocatorDefault, (__bridge CFDataRef)certificateData);
    NSAssert(certificateRef != NULL, @"公钥文件错误");
    
    // 返回一个默认 X509 策略的公钥对象，使用之后需要调用 CFRelease 释放
    SecPolicyRef policyRef = SecPolicyCreateBasicX509();
    // 包含信任管理信息的结构体
    SecTrustRef trustRef;
    
    // 基于证书和策略创建一个信任管理对象
    OSStatus status = SecTrustCreateWithCertificates(certificateRef, policyRef, &trustRef);
    NSAssert(status == errSecSuccess, @"创建信任管理对象失败");
    
    // 信任结果
    SecTrustResultType trustResult;
    // 评估指定证书和策略的信任管理是否有效
    status = SecTrustEvaluate(trustRef, &trustResult);
    NSAssert(status == errSecSuccess, @"信任评估失败");
    
    // 评估之后返回公钥子证书
    _publicKeyRef = SecTrustCopyPublicKey(trustRef);
    NSAssert(_publicKeyRef != NULL, @"公钥创建失败");
    
    if (certificateRef) CFRelease(certificateRef);
    if (policyRef) CFRelease(policyRef);
    if (trustRef) CFRelease(trustRef);
}

- (void)loadPrivateKey:(NSString *)filePath password:(NSString *)password {
    
    NSAssert(filePath.length != 0, @"私钥路径为空");
    
    // 删除当前私钥
    if (_privateKeyRef) CFRelease(_privateKeyRef);
    
    NSData *PKCS12Data = [NSData dataWithContentsOfFile:filePath];
    CFDataRef inPKCS12Data = (__bridge CFDataRef)PKCS12Data;
    CFStringRef passwordRef = (__bridge CFStringRef)password;
    
    // 从 PKCS #12 证书中提取标示和证书
    SecIdentityRef myIdentity;
    SecTrustRef myTrust;
    const void *keys[] = {kSecImportExportPassphrase};
    const void *values[] = {passwordRef};
    CFDictionaryRef optionsDictionary = CFDictionaryCreate(NULL, keys, values, 1, NULL, NULL);
    CFArrayRef items = CFArrayCreate(NULL, 0, 0, NULL);
    
    // 返回 PKCS #12 格式数据中的标示和证书
    OSStatus status = SecPKCS12Import(inPKCS12Data, optionsDictionary, &items);
    
    if (status == noErr) {
        CFDictionaryRef myIdentityAndTrust = CFArrayGetValueAtIndex(items, 0);
        myIdentity = (SecIdentityRef)CFDictionaryGetValue(myIdentityAndTrust, kSecImportItemIdentity);
        myTrust = (SecTrustRef)CFDictionaryGetValue(myIdentityAndTrust, kSecImportItemTrust);
    }
    
    if (optionsDictionary) CFRelease(optionsDictionary);
    
    NSAssert(status == noErr, @"提取身份和信任失败");
    
    SecTrustResultType trustResult;
    // 评估指定证书和策略的信任管理是否有效
    status = SecTrustEvaluate(myTrust, &trustResult);
    NSAssert(status == errSecSuccess, @"信任评估失败");
    
    // 提取私钥
    status = SecIdentityCopyPrivateKey(myIdentity, &_privateKeyRef);
    NSAssert(status == errSecSuccess, @"私钥创建失败");
    CFRelease(items);
}

- (NSString *)RSAEncryptString:(NSString *)string {
    NSData *cipher = [self RSAEncryptData:[string dataUsingEncoding:NSUTF8StringEncoding]];
    
    return [cipher base64EncodedStringWithOptions:0];
}

- (NSData *)RSAEncryptData:(NSData *)data {
    OSStatus sanityCheck = noErr;
    size_t cipherBufferSize = 0;
    size_t keyBufferSize = 0;
    
    NSAssert(data, @"明文数据为空");
    NSAssert(_publicKeyRef, @"公钥为空");
    
    NSData *cipher = nil;
    uint8_t *cipherBuffer = NULL;
    
    // 计算缓冲区大小
    cipherBufferSize = SecKeyGetBlockSize(_publicKeyRef);
    keyBufferSize = data.length;
    
    if (kTypeOfWrapPadding == kSecPaddingNone) {
        NSAssert(keyBufferSize <= cipherBufferSize, @"加密内容太大");
    } else {
        NSAssert(keyBufferSize <= (cipherBufferSize - 11), @"加密内容太大");
    }
    
    // 分配缓冲区
    cipherBuffer = malloc(cipherBufferSize * sizeof(uint8_t));
    memset((void *)cipherBuffer, 0x0, cipherBufferSize);
    
    // 使用公钥加密
    sanityCheck = SecKeyEncrypt(_publicKeyRef,
                                kTypeOfWrapPadding,
                                (const uint8_t *)data.bytes,
                                keyBufferSize,
                                cipherBuffer,
                                &cipherBufferSize
                                );
    
    NSAssert(sanityCheck == noErr, @"加密错误，OSStatus == %d", sanityCheck);
    
    // 生成密文数据
    cipher = [NSData dataWithBytes:(const void *)cipherBuffer length:(NSUInteger)cipherBufferSize];
    
    if (cipherBuffer) free(cipherBuffer);
    
    return cipher;
}

- (NSString *)RSADecryptString:(NSString *)string {
    NSData *keyData = [self RSADecryptData:[[NSData alloc] initWithBase64EncodedString:string options:0]];
    
    return [[NSString alloc] initWithData:keyData encoding:NSUTF8StringEncoding];
}

- (NSData *)RSADecryptData:(NSData *)data {
    OSStatus sanityCheck = noErr;
    size_t cipherBufferSize = 0;
    size_t keyBufferSize = 0;
    
    NSData *key = nil;
    uint8_t *keyBuffer = NULL;
    
    SecKeyRef privateKey = _privateKeyRef;
    NSAssert(privateKey != NULL, @"私钥不存在");
    
    // 计算缓冲区大小
    cipherBufferSize = SecKeyGetBlockSize(privateKey);
    keyBufferSize = data.length;
    
    NSAssert(keyBufferSize <= cipherBufferSize, @"解密内容太大");
    
    // 分配缓冲区
    keyBuffer = malloc(keyBufferSize * sizeof(uint8_t));
    memset((void *)keyBuffer, 0x0, keyBufferSize);
    
    // 使用私钥解密
    sanityCheck = SecKeyDecrypt(privateKey,
                                kTypeOfWrapPadding,
                                (const uint8_t *)data.bytes,
                                cipherBufferSize,
                                keyBuffer,
                                &keyBufferSize
                                );
    
    NSAssert1(sanityCheck == noErr, @"解密错误，OSStatus == %d", sanityCheck);
    
    // 生成明文数据
    key = [NSData dataWithBytes:(const void *)keyBuffer length:(NSUInteger)keyBufferSize];
    
    if (keyBuffer) free(keyBuffer);
    
    return key;
}

@end
