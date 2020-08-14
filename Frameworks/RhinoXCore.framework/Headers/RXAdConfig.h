//
//  RXAdConfig.h
//  TestAd
//
//  Created by daidai on 2020/7/7.
//  Copyright © 2020 daidia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RXSplashAdView.h"
#import "RXRewardedVideoAd.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString* const ADNAME_GDT; // 广点通
extern NSString* const ADNAME_BU; // 穿山甲
extern NSString* const ADNAME_BAIDU; // 百度
extern NSString* const ADNAME_GADMOBILEAD; // 谷歌

@interface RXAdConfig : NSObject

/**
 * 优量汇sdk注册接口，请在 app 初始化时调用。
 */
+(void)setGDTAdWithAppID:(NSString *)appId;

/**
 * 穿山甲sdk注册接口，请在 app 初始化时调用。
 */
+(void)setBUAdWithAppID:(NSString *)appId;

/**
 * 初始化移动广告
 * 请在您的应用的 Info.plist 文件中，添加一个字符串值为您的 AdMob 应用 ID 的 GADApplicationIdentifier 键
 * 请参考 https://developers.google.cn/admob/ios/quick-start
 */
+ (void)startGADMobileAdWithCompletionHandler:(void (^)(id status))handler;

@end

NS_ASSUME_NONNULL_END
