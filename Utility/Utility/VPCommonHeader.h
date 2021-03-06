//
//  VPCommonHeader.h
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//


#ifndef VPCommonHeader_h
#define VPCommonHeader_h

/////////////////////////////////////////////////
// 经常用到的校验规则辅助类

/**
 * 手机号码
 * 移动：134[0-8],135,136,137,138,139,150,151,157,158,159,182,187,188
 * 联通：130,131,132,152,155,156,185,186
 * 电信：133,1349,153,180,189
 * 固话：010,020,021,022,023,024,025,027,028,029
 *  @return
 */
#define VP_Mobile  @"^((13[0-9])|(15[^4,\\D])|(18[0,0-9]))\\d{8}$"

// 中国移动：China Mobile
// 移动：134[0-8],135,136,137,138,139,150,151,157,158,159,182,187,188

#define VP_CM  @"^1(34[0-8]|(3[5-9]|5[017-9]|8[278])\\d)\\d{7}$"

// 中国联通：China Unicom
//  联通：130,131,132,152,155,156,185,186

#define VP_CU = @"^1(3[0-2]|5[256]|8[56])\\d{8}$"

// 中国电信：China Telecom
// 电信：133,1349,153,180,189

#define VP_CT = @"^1((33|53|8[09])[0-9]|349)\\d{7}$"

// 大陆地区固话及小灵通
// 移动：010,020,021,022,023,024,025,027,028,029
// 号码：七位或八位

#define VP_PHS = @"^0(10|2[0-5789]|\\d{3})\\d{7,8}$"

/**
 *  邮箱
 *
 *  @return
 */
#define VP_Email   @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}"

/**
 *  用户名
 *
 *  @return
 */
#define VP_UserName @"^[A-Za-z0-9]{6,20}+$"

/**
 *  密码
 *
 *  @return
 */
#define VP_PassWord  @"^[a-zA-Z0-9]{6,20}+$"

/**
 *  昵称
 *
 *  @return
 */
#define VP_NickName  @"^[\u4e00-\u9fa5]{4,8}$"

/**
 *  身份证号
 *
 *  @return
 */
#define VP_IDCard  @"^(\\d{14}|\\d{17})(\\d|[xX])$"

/**
 *  银行卡     ValidateImpl.h
 */

#endif /* VPCommonHeader_h */
