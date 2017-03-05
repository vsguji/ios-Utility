//
//  VPConstants.h
//  Utility
//
//  Created by lipeng on 2017/3/5.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#ifndef VPConstants_h
#define VPConstants_h

// 快速创建单例模式

#define DECLARE_SINGLETON_FOR_CLASSS(classname)\
+(classname *)shared##classname;

#define DEFINE_SINGLETON_FOR_CLASS(classname)\
\
+(classname *)shared##classname \
{\
static classname *share##classname = nil;\
static dispatch_once_t onceToken;  \
dispatch_once(&onceToken,^{\
share##classname = [[classname alloc] init];\
}); \
return share##classname;\
}




#endif /* VPConstants_h */
