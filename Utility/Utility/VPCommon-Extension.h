//
//  VPCommon-Extension.h
//  Utility
//
//  Created by lipeng on 2017/3/2.
//  Copyright © 2017年 lipeng. All rights reserved.
//


#ifndef VPCommon_Extension_h
#define VPCommon_Extension_h


/////////////////////////////////////////////////
// 经常用到的校验规则辅助 扩展类

/**
 *  URL
 *
 *  @param https?:\\/\\/ 访问路径
 *
 *  @return
 */

#define VP_URL @"^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w \\.-]*)*\\/?$"

/**
 *  IP
 *
 *  @param ?:25
 *
 *  @return
 */

#define VP_IP @"^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"

/**
 *  车牌号
 *
 *  @return
 */
#define VP_Card    @"^[\u4E00-\u9FFF]+$"

#endif /* VPCommon_Extension_h */
