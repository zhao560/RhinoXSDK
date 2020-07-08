//
//  RXInfoHelper.h
//  RhinoXCore_source
//
//  Created by daidai on 2020/5/23.
//  Copyright © 2020 daidia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXInfoHelper : NSObject

/**
 *  获取info.plist中的CFBundleDisplayName
 *
 *  @return 如果没有，返回CFBundleName
 */
+ (nullable NSString *)appDisplayName;

/**
 *  获取info.plist发布版本号
 *
 *  @return 可能为nil
 */
+ (nullable NSString *)versionName;

/**
 *  @return 获取plist中的CFBundleIdentifier
 */
+ (nullable NSString *)bundleIdentifier;

@end

NS_ASSUME_NONNULL_END
