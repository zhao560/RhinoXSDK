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

extern NSString* const ADNAME_GDT;
extern NSString* const ADNAME_BU;
extern NSString* const ADNAME_BAIDU;

@interface RXAdConfig : NSObject
/**
 * 优量汇sdk注册接口，请在 app 初始化时调用。
 */
+(void)setGDTAdWithAppID:(NSString *)appId;
/**
 * 穿山甲sdk注册接口，请在 app 初始化时调用。
 */
+(void)setBUAdWithAppID:(NSString *)appId;

@end

NS_ASSUME_NONNULL_END
