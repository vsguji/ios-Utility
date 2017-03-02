//
//  VPCommonImpl.h
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//
//  经常用到的校验规则实现

#import <Foundation/Foundation.h>

@interface ValidateImpl : NSObject

/**
 *  手机号
 *
 *  @param number 手机号码
 *
 *  @return
 */
+ (BOOL) IsPhoneNumber:(NSString *)number;

/**
 *  三大运行商号码
 *
 *  @param phone 手机号
 *
 *  @return
 */
+ (BOOL) IsPhone:(NSString *)phone;

/**
 *  邮箱
 *
 *  @param Email 邮箱
 *
 *  @return
 */
+ (BOOL) IsEmailAdress:(NSString *)Email;


/**
 *  手机号,邮箱,用户名,密码,昵称 统一验证规则
 *
 *  @param text      文本
 *  @param predicate 各自验证规则
 *
 *  @return
 */
+ (BOOL) IsRightPredicate:(NSString *)text withPredicate:(NSString *)predicate;

/**
 *  身份证
 *
 *  @param IDCardNumber 身份证号
 *
 *  @return
 */
+ (BOOL) IsIdentityCard:(NSString *)IDCardNumber;

/**
 *  银行卡
 *
 *  @param cardNumber 银行卡号
 *
 *  @return
 */
+ (BOOL) IsBankCard:(NSString *)cardNumber;



@end
