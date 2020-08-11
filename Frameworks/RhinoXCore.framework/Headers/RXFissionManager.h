//
//  RXFissionManager.h
//  RhinoXCore_source
//
//  Created by daidai on 2020/7/22.
//  Copyright © 2020 daidia. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kFissionLoginOutNotification; // 退出登录
extern NSString *const kFissionAccountFlagUserDefaults; // string YES-结束 NO-未结束

@class RXFissionManager;
@class RXRedPacketView;

@protocol RXFissionManagerDelegate <NSObject>

@optional
/**
 * 请重新登录
 * 登录成功请调用 setOrUpdateUserInfoWithAccountId
 * 当前展示的ViewController
 */
- (void)rx_fissionManagerReLoginCallback:(RXFissionManager *)manager currentViewController:(UIViewController *)viewController;

@end


@interface RXFissionManager : NSObject
/**
 * singleton instance.
 */
+ (instancetype)sharedInstance;

/**
 * 代理
 */
@property (nonatomic, weak, nullable) id<RXFissionManagerDelegate> delegate;

/**
 * 不显示红包 比如登录页面 UIAlertController 等
 */
@property (nonatomic, copy, nullable) NSArray <NSString *> *classNameList;

/**
 * 红包弹框
 */
@property (nonatomic, strong, readonly) RXRedPacketView *redPacketView;

/**
 * 初始化设置
 * appID 由服务端提供
 * appName 由服务端提供
 * slotID 穿山甲激励视频id 请先导入穿山甲sdk
 */
-(void)setAppId:(nonnull NSString *)appID
    withAppName:(nonnull NSString *)appName
     withSlotID:(nonnull NSString *)slotID;

/**
 * 设置或重置用户信息
 * accountId 用户唯一标识
 * mobile 用户手机号
 */
-(void)setOrUpdateUserInfoWithAccountId:(nullable NSString *)accountId
                              andMobile:(nullable NSString *)mobile;


/**
 * 显示裂变活动弹框
 */
-(void)showFissionRedPacketView;
/**
 * 显示助力红包弹框
 * inviteCode 被助力人的邀请码
 */
-(void)showHelpRedPacketViewWithInviteCode:(nonnull NSString *)inviteCode;
/**
 * 常驻入口可直接进入活动webView页面
 */
-(void)gotoFissionWebViewController;

@end

NS_ASSUME_NONNULL_END
