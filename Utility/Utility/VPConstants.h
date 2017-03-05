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


// 强|弱引用
#define LRWeakSelf(type)  __weak typeof(type) weak##type = type;
#define LRStrongSelf(type)  __strong typeof(type) type = weak##type;


// 使用 ARC 还是 MRC
#if __has_feature(objc_arc)
// ARC
#else
// MRC
#endif


// 程序版本
#define APP_VERSION                 [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

// 系统版本
#define SYSTEM_VERSION                             ([[[UIDevice currentDevice] systemVersion] floatValue])
#define SYSTEM_VERSION_EQUAL_TO(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_HIGHER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_EQUAL_TO_OR_HIGHER_THAN(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LOWER_THAN(v)               ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_EQUAL_TO_OR_LOWER_THAN(v)   ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

// 设备屏幕
#define SCREEN_SIZE                 [[UIScreen mainScreen] bounds].size
#define SCREEN_WIDTH                [[UIScreen mainScreen] bounds].size.width
#define SCREEN_HEIGHT               [[UIScreen mainScreen] bounds].size.height

// 字体颜色
#define FONT_SOFIA_MEDIUM(s)        [UIFont fontWithName:@"SofiaProSoft-Medium" size:s]
#define FONT_SOFIA_SOFT(s)          [UIFont fontWithName:@"SofiaProSoft" size:s]

// 空间颜色
#define RGB(r,g,b)                  [UIColor colorWithRed:r / 255.f green:g / 255.f blue:b / 255.f alpha:1.f]
#define RGBA(r,g,b,a)               [UIColor colorWithRed:r / 255.f green:g / 255.f blue:b / 255.f alpha:a]
#define RGB_HEX(hex)                RGBA((float)((hex & 0xFF0000) >> 16),(float)((hex & 0xFF00) >> 8),(float)(hex & 0xFF),1.f)
#define RGBA_HEX(hex,a)             RGBA((float)((hex & 0xFF0000) >> 16),(float)((hex & 0xFF00) >> 8),(float)(hex & 0xFF),a)

#define COLOR_LIGHT_BLUE            RGB_HEX(0x7f8b97)
#define COLOR_DEEP_BLUE             RGB_HEX(0x00b3d6)

// 当前语言
#define CURRENT_LANGUAGE            ([[NSLocale preferredLanguages] objectAtIndex:0])
#define IS_LANGUAGE(l)              [CURRENT_LANGUAGE hasPrefix:l]
#define IS_LANGUAGE_EN              IS_LANGUAGE(@"en")

//GCD - 一次性执行
#define kDISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);

//GCD - 在Main线程上运行
#define kDISPATCH_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

//GCD - 开启异步线程
#define kDISPATCH_GLOBAL_QUEUE_DEFAULT(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);

#endif /* VPConstants_h */
