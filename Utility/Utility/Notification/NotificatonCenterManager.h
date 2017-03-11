//
//  NotificatonCenterManager.h
//  Utility
//
//  Created by lipeng on 2017/3/11.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VPConstants.h"

typedef void (^deviceBlock)(NSString *deviceToken);

UIKIT_EXTERN  NSString * const kApnsDeviceToken;

@interface NotificatonCenterManager : NSObject

DECLARE_SINGLETON_FOR_CLASSS(NotificatonCenterManager);

// 远程推送
+ (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions withBlock:(deviceBlock)block;

// method of your app delegate. The first time you register your settings, iOS waits for the user’s response before calling this method, but on subsequent calls it returns the existing user settings.
// The user can change the notification settings for your app at any time using the Settings app. Because settings can change, always call the registerUserNotificationSettings: at launch time and use the application:didRegisterUserNotificationSettings: method to get the response. If the user disallows specific notification types, avoid using those types when configuring local and remote notifications for your app
+ (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings NS_AVAILABLE_IOS(8_0);

// method to receive the device token needed to deliver remote notifications. Use the application:didFailToRegisterForRemoteNotificationsWithError: method to process errors.
+ (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken withBlock:(deviceBlock)block NS_AVAILABLE_IOS(3_0);
+ (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error NS_AVAILABLE_IOS(3_0);

// which is called only when your app is running in the foreground
+ (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo NS_AVAILABLE_IOS(3_0);

// the system calls this method when your app is running in the foreground or background
+ (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler NS_AVAILABLE_IOS(7_0);

// 本地通知
+ (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification NS_AVAILABLE_IOS(4_0);

// backgroundqueue
+ (void)applicationWillResignActive:(UIApplication *)application;
+ (void)applicationDidEnterBackground:(UIApplication *)application;
+ (void)applicationWillEnterForeground:(UIApplication *)application;
+ (void)applicationDidBecomeActive:(UIApplication *)application;
+ (void)applicationWillTerminate:(UIApplication *)application;

@end
