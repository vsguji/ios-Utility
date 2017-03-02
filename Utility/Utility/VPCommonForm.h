//
//  VPCommonForm.h
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#ifndef VPCommonForm_h
#define VPCommonForm_h

/////////////////////////////////////////////////
// 画面字段校验的正则表达式

// Sample
// （对于输入中文的字段，由于输入法的特殊机制，所以不要设置编辑过程中的长度限制，否则可能还没输到最大长度就不让输了）
#define RegexAndErrStr_ [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"", @"", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:0], @"", nil], \
/* 内容为空时的提示语 */ \
@"", \
nil]\

// 用户名
#define RegexAndErrStr_UserName [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^[A-Za-z\\d_]*$", @"只允许英文、数字、下划线！", nil], \
[NSArray arrayWithObjects:@"^.{4,16}$", @"请输入4-16位用户名！", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^[A-Za-z\\d_\\s]*$"/*中文输入法时会产生临时的空格*/, @"只允许英文、数字、下划线！", nil], \
[NSArray arrayWithObjects:@"(^.{0}$)|(^[A-Za-z_]{1}.*$)", @"不能以数字开头！", nil], \
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:16], @"最多16位用户名！", nil], \
/* 内容为空时的提示语 */ \
@"用户名不能为空！", \
nil]\

// 密码
#define RegexAndErrStr_Password [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^.{4,16}$", @"请输入4-16位密码！", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^[A-Za-z\\d_]*$", @"密码应由英文、数字、下划线组成！", nil], \
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:16], @"最多16位密码！", nil], \
/* 内容为空时的提示语 */ \
@"密码不能为空！", \
nil]\

// 电子邮箱
#define RegexAndErrStr_Email [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^(\\w)+(\\.\\w+)*@(\\w)+((\\.\\w+)+)$", @"请您填写符合邮件的书写规范！", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^[\\w@.\\s]*$"/*中文输入法时会产生临时的空格*/, @"请您填写符合邮件的书写规范！", nil], \
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:0], @"", nil], \
/* 内容为空时的提示语 */ \
@"请输入Email！", \
nil]\

// 手机号
#define RegexAndErrStr_MobilePhone [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^.{11}$", @"请输入正确的手机号！", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"(^.{0}$)|(^[1]$)|(^[1][3-8][\\d]*$)", @"请输入正确的手机号！", nil], \
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:11], @"", nil], \
/* 内容为空时的提示语 */ \
@"请输入手机号！", \
nil]\

// 固定电话号
#define RegexAndErrStr_Telephone [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^[\\d\-]*$", @"请输入正确的电话号！", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^[\\d\-\\s]*$"/*中文输入法时会产生临时的空格*/, @"请输入正确的电话号！", nil], \
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:13], @"", nil], \
/* 内容为空时的提示语 */ \
@"请输入电话号！", \
nil]\

// 姓名
// （对于输入中文的字段，由于输入法的特殊机制，所以不要设置编辑过程中的长度限制，否则可能还没输到最大长度就不让输了）
#define RegexAndErrStr_Name [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^[A-Za-z.\\u4e00-\\u9fa5]*$", @"请输入英文或汉字！", nil], \
[NSArray arrayWithObjects:@"^.{0,16}$", @"最多16位姓名！", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^[A-Za-z.\\u4e00-\\u9fa5\\s]*$"/*中文输入法时会产生临时的空格*/, @"请输入英文或汉字！", nil], \
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:16], @"", nil], \
/* 内容为空时的提示语 */ \
@"姓名不能为空！", \
nil]\

// 激活码
#define RegexAndErrStr_ActiveCode [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:0], @"", nil], \
/* 内容为空时的提示语 */ \
@"请输入激活码！", \
nil]\

// 在线咨询
// （对于输入中文的字段，由于输入法的特殊机制，所以不要设置编辑过程中的长度限制，否则可能还没输到最大长度就不让输了）
#define RegexAndErrStr_Content [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^.{0,250}$", @"咨询内容不能超过250字！", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:0], @"", nil], \
/* 内容为空时的提示语 */ \
@"请输入咨询内容！", \
nil]\

// 通讯地址
#define RegexAndErrStr_Address [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:0], @"", nil], \
/* 内容为空时的提示语 */ \
@"请输入通讯地址！", \
nil]\

// 邮政编码
#define RegexAndErrStr_ZipCode [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^[\\d]{6}$", @"请输入正确的邮政编码！", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"^[\\d]*$", @"", nil], \
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:6], @"", nil], \
/* 内容为空时的提示语 */ \
@"请输入邮政编码！", \
nil]\

// 证件号码
#define RegexAndErrStr_IDCard [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"(^[\\d]{15}$)|(^[\\d]{17}[\\da-zA-Z]{1}$)", @"请输入正确的证件号码！", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"(^[\\d]{0,17}$)|(^[\\d]{17}[\\da-zA-Z].*$)", @"请输入正确的证件号码！", nil], \
nil], \
/* 最大长度，及超限时的提示语 */ \
[NSArray arrayWithObjects:[NSNumber numberWithInt:18], @"", nil], \
/* 内容为空时的提示语 */ \
@"请输入证件号码！", \
nil]\

// 其他证件号码
#define RegexAndErrStr_OtherIDCards [NSArray arrayWithObjects:\
/* 最终提交时的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"(^.{4,}$)", @"请输入至少4位证件号！", nil], \
nil], \
/* 编辑过程中的校验条件 */ \
[NSArray arrayWithObjects:\
[NSArray arrayWithObjects:@"(^.*$)", @"", nil], \
nil], \
/* 最大长度，及提示语 */ \
[NSArray arrayWithObjects:@"[NSNumber numberWithInt:100]", @"", nil], \
/* 内容为空时的提示语 */ \
@"请输入证件号码！", \
nil]\

#endif /* VPCommonForm_h */
