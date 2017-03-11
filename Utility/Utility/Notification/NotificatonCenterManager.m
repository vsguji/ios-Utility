//
//  NotificatonCenterManager.m
//  Utility
//
//  Created by lipeng on 2017/3/11.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import "NotificatonCenterManager.h"

@implementation NotificatonCenterManager(Push)

+ (NSString *)data2hexStr:(NSData *)data
{
    Byte *bytes = (Byte *)[data bytes];
    NSMutableString *hexStr = [NSMutableString stringWithFormat:@"%@", @""];
    for (int i = 0; i < [data length]; i++)
    {
        NSString *newHexStr = [NSString stringWithFormat:@"%02x", bytes[i]]; ///16进制数
        [hexStr appendFormat:@"%@", newHexStr];
    }
    return hexStr;
}

@end

NSString * const kApnsDeviceToken = @"DeviceToken";

@implementation NotificatonCenterManager

DEFINE_SINGLETON_FOR_CLASS(NotificatonCenterManager);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 推送通知
// 注册推送通知
+(void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions withBlock:(deviceBlock)block{
    
    // 清除Badge（应用程序Icon上的数字标示）
    [[UIApplication sharedApplication] setApplicationIconBadgeNumber:0];
    
    // 从存储中取出之前保存的DeviceToken
    NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
    NSString *deviceTokenStr = [ud stringForKey:kApnsDeviceToken];
    if (![[UIApplication sharedApplication]isRegisteredForRemoteNotifications]
        || deviceTokenStr == nil
        || [deviceTokenStr length] == 0) {
        // Register for push notifications
        UIUserNotificationType types = (UIUserNotificationType) (UIUserNotificationTypeBadge |
                                                                 UIUserNotificationTypeSound | UIUserNotificationTypeAlert);
        UIUserNotificationSettings *notificationSettings = [UIUserNotificationSettings settingsForTypes:types categories:nil];
        [application registerUserNotificationSettings:notificationSettings];
        [application registerForRemoteNotifications];
        // Registering Your Actionable Notification Types
    }
    else{
        if (block) {
            block(deviceTokenStr);
        }
    }
}

// 返回 通知设置
+(void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings{
    
}

// 已注册推送,返回 deviceToken
+ (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken withBlock:(deviceBlock)block{
    NSString *deviceTokenStr = [self data2hexStr:deviceToken];
    // 持久化deviceToken
    NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
    [ud setObject:deviceTokenStr forKey:kApnsDeviceToken];
    [ud synchronize];
    if (block) {
        // 将DeviceToken发送到服务端
        block(deviceTokenStr);
    }
}

// 推送注册失败,返回 失败结果
+ (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    NSLog(@"Error in registration. Error: %@", error);
}

// 处理收到的消息   仅仅可用于设备处于前端
+ (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    
    NSString *msg = @"";
    @try {
        id objAlert = [[userInfo objectForKey:@"aps"] objectForKey:@"alert"];
        if ([objAlert isKindOfClass:[NSString class]]) {
            msg = objAlert;
        } else if ([objAlert isKindOfClass:[NSDictionary class]]) {
            id objBody = [objAlert objectForKey:@"body"];
            if ([objBody isKindOfClass:[NSString class]]) {
                msg = objBody;
            }
        }
    }
    @catch(NSException *exception) {
        
    }
}

// 处理收到的消息  处于前端或后台都可以,后台可以处理下载等任务
+ (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler {
    
}

// 可提供本地通知快速处理等
+ (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 处于活跃状态

+ (void)applicationWillEnterForeground:(UIApplication *)application{
    
}

+ (void)applicationDidBecomeActive:(UIApplication *)application{
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 处于非活动状态

+(void)applicationWillResignActive:(UIApplication *)application {
    
}

+ (void)applicationDidEnterBackground:(UIApplication *)application{
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 内存警告

+ (void)applicationWillTerminate:(UIApplication *)application{
    
}

@end
