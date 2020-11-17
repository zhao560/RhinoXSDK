//
//  RXSplashAdView.h
//  TestAd
//
//  Created by daidai on 2020/6/29.
//  Copyright © 2020 daidia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class RXSplashAdView;

@protocol RXSplashAdViewDelegate <NSObject>

@optional
/**
 *  开屏广告素材加载成功
 */
- (void)splashAdDidLoad:(RXSplashAdView *)splashAd;

/**
 *  开屏广告展示失败
 */
- (void)splashAdFailToPresent:(RXSplashAdView *)splashAd withError:(NSError *)error;

/**
 *  开屏广告曝光回调
 */
- (void)splashAdWillVisible:(RXSplashAdView *)splashAd;

/**
 *  开屏广告点击回调
 */
- (void)splashAdClicked:(RXSplashAdView *)splashAd;

/**
 * 打开appstore或打开网页页面关闭回调
 */
- (void)splashAdDidCloseOtherController:(RXSplashAdView *)splashAd;

/**
 *  开屏广告将要关闭回调
 */
- (void)splashAdWillClose:(RXSplashAdView *)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)splashAdDidClose:(RXSplashAdView *)splashAd;

@end


@interface RXSplashAdView : UIView
/**
 *  委托对象
 */
@property (nonatomic, weak) id<RXSplashAdViewDelegate> delegate;

/**
 *  拉取广告超时时间，默认为3秒
 *  详解：拉取广告超时时间，开发者调用loadAd方法以后会立即展示backgroundImage，然后在该超时时间内，如果广告拉
 *  取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) CGFloat fetchDelay;

/**
 * 广告位ID
 */
@property (nonatomic, copy) NSString *adIdentity;

/**
 * 加载的广告类型
 * csj - 穿山甲 ylh - 优量汇 zhike - 直客
 */
@property (nonatomic, copy, readonly) NSString *advertiserNo;

/**
 * 构造方法
 * rootViewController  用来跳转到广告页面
 * 详解：bottomView - 底部logo
 */
-(instancetype)initWithRootViewController:(UIViewController *)rootViewController WithBottomView:(UIView * _Nullable)bottomView;

/**
 *  请先此方法钱设置广告位ID 和 rootViewController
 *  发起拉取广告请求，只拉取不展示
 *  详解：广告素材及广告图片拉取成功后会回调splashAdDidLoad方法，当拉取失败时会回调splashAdFailToPresent方法
 */
- (void)loadAdData;

/**
 *  展示广告
 */
- (void)showAdInWindow:(UIWindow *)window;

@end

NS_ASSUME_NONNULL_END
