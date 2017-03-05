//
//  VPFileManager.h
//  Utility
//
//  Created by lipeng on 2017/3/5.
//  Copyright © 2017年 lipeng. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface VPFileManager : NSObject

/**
 *  获取Documents路径
 *
 *  @return 
 */
- (NSString *)getDocumentsPath;

/**
 *  创建文件夹
 *
 *  @param dirName   文件夹名称
 *  @param attri   文件属性
 *
 *  @return YES|NO
 */
- (BOOL)createDirectory:(NSString *)dirName withAttri:(NSDictionary *)attri;

/**
 *  创建文件
 *
 *  @param fileName 文件名称
 *  @param attri    文件属性
 *
 *  @return YES|NO
 */
- (BOOL)createFile:(NSString *)fileName withAttri:(NSDictionary *)attri;

/**
 *  写入内容
 *
 *  @param fileName 文件名称
 *  @param content  内容
 *  @param atomical YES:1.全部写入成功 无错误；NO:支持部分写入
 *
 *  @return YES|NO
 */
- (BOOL)writeToFile:(NSString *)fileName withContent:(NSString *)content withAtomical:(BOOL)atomical;

/**
 *  读取内容
 *
 *  @param fileName 文件名称
 *
 *  @return 内容
 */
- (NSString *)readFileContent:(NSString *)fileName;

/**
 *  判断文件是否存在
 *
 *  @param filePath 文件路径
 *
 *  @return YES|NO
 */
- (BOOL)isSxistAtPath:(NSString *)filePath;

/**
 *  文件大小
 *
 *  @param filePath 文件路径
 *
 *  @return unsigned long long
 */
- (unsigned long long)fileSizeAtPath:(NSString *)filePath;

/**
 *  文件夹大小
 *
 *  @param folderPath 文件路径
 *
 *  @return unsigned long long
 */
- (unsigned long long)folderSizeAtPath:(NSString *)folderPath;

/**
 *  删除文件
 *
 *  @param fileName 文件名称
 *
 *  @return YES|NO
 */
- (BOOL)deleteFile:(NSString *)fileName;

/**
 *  移动文件
 *
 *  @param fromPath 当前路径
 *  @param toPath 目标路径
 *
 *  @return YES|NO
 */
- (BOOL)moveFileName:(NSString*)fromPath toPath:(NSString*)destPath;

/**
 *  文件重命名
 *
 *  @param fromFile 旧文件名
 *  @param newFile  新文件名
 *
 *  @return YES|NO
 */
- (BOOL)renameFileName:(NSString *)oldFile toNewFile:(NSString *)newFile;

@end

NS_ASSUME_NONNULL_END
