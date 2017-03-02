//
//  VPIdentityCard.h
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VPIdentityCard : NSObject


/**
 *  根据身份证号获取生日
 *
 *  @param numberStr 身份证
 *
 *  @return
 */
- (NSString *)birthdayFromIdentityCard:(NSString *)IDStr;

/**
 *  根据身份证号性别
 *
 *  @param numberStr 身份证
 *
 *  @return 1:男 2:女
 */
- (NSString *)getSexIdentityCard:(NSString *)IDStr;

@end
