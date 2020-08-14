//
//  RXRewardedVideoAd.h
//  TestAd
//
//  Created by daidai on 2020/6/29.
//  Copyright © 2020 daidia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class RXRewardedVideoModel;
@class RXRewardedVideoAd;

extern NSString *const kRXRewardedVideoAdName; // 开屏广告

@protocol RXRewardedVideoAdDelegate <NSObject>

@optional

/**
 * 广告数据加载成功回调
 * @param rewardedVideoAd RXRewardedVideoAd实例
 */
- (void)rx_rewardVideoAdDidLoad:(RXRewardedVideoAd *)rewardedVideoAd;

/**
 * 缓存成功时调用此方法
 */
-(void)rx_rewardedVideoAdDidDownLoadVideo:(RXRewardedVideoAd *)rewardedVideoAd;

/**
 * 此方法在成功呈现nativeExpressAdView时调用。
 */
- (void)rx_rewardedVideoAdViewRenderSuccess:(RXRewardedVideoAd *)rewardedVideoAd;

/**
 视频广告各种错误信息回调
 
 @param rewardedVideoAd RXRewardedVideoAd 实例
 @param error 具体错误信息
 */
- (void)rx_rewardVideoAd:(RXRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;


/**
 *  视频播放页即将展示回调
 * @param rewardedVideoAd RXRewardedVideoAd 实例
 */
-(void)rx_rewardVideoAdWillVisible:(RXRewardedVideoAd *)rewardedVideoAd;

/**
 视频播放页关闭回调
 
 @param rewardedVideoAd RXRewardedVideoAd 实例
 */
- (void)rx_rewardVideoAdDidClose:(RXRewardedVideoAd *)rewardedVideoAd;

/**
 * 视频广告播放达到激励条件回调
 * @param verify  验证是否成功
 * @param rewardedVideoAd RXRewardedVideoAd 实例
 */
- (void)rx_rewardVideoAdDidRewardEffective:(RXRewardedVideoAd *)rewardedVideoAd verify:(BOOL)verify;

/**
 * 此方法在视频广告播放完成时调用
 * @param rewardedVideoAd RXRewardedVideoAd 实例
 */
- (void)rx_rewardVideoAdDidPlayFinish:(RXRewardedVideoAd *)rewardedVideoAd;

@end


@interface RXRewardedVideoAd : NSObject
/**
 * 代理
 */
@property (nonatomic, weak, nullable) id<RXRewardedVideoAdDelegate> delegate;

/**
 * 设置激励视频是否静音
 */
@property (nonatomic, assign) BOOL videoMuted;
/**
 * 穿山甲广告位id
 */
@property (nonatomic, copy, nonnull) NSString *BUSlotID;

/**
 * 广点通广告位id
 */
@property (nonatomic, copy, nonnull) NSString *GDTSlotID;

/**
 * 谷歌广告位id
 */
@property (nonatomic, copy, nonnull) NSString *GADMobSlotID;

/**
 * 穿山甲激励视频可以携带信息
 */
@property (nonatomic, strong, nullable) RXRewardedVideoModel *rewardedVideoModel;

/**
 加载广告方法 支持 iOS8.1 及以上系统
 */
- (void)loadAdData;

/**
 展示广告方法
 
 @param rootViewController 用于 present 激励视频 VC
 @return 是否展示成功
 */
- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
