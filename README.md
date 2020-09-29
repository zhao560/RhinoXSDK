## 使用CocoaPods安装

要使用CocoaPods将RhinoXSDK集成到您的Xcode项目中，请在您的`Podfile`中指定

```ruby
pod 'RhinoXSDK', '~> 1.0.6'
```

## 工具使用

### 加解密

```objective-c
// AES加解密
@interface RXSecurityUtil : NSObject
/**
 * 加密方法
 * @string  需要加密的字符串
 * @key  密码
 */
+(nullable NSString *) encryptAESString:(NSString *)string key:(NSString *)key;

/**
 * 解密方法
 * @string  需要解密的字符串
 * @key  密码
 */
+(nullable NSString *) decryptAESString:(NSString *)string key:(NSString *)key;
@end
```

### 获取设备信息相关

```objective-c
@interface RXDeviceHelper : NSObject

/// 获取idfa
+ (nullable NSString *)idfaString;

/// 获取idfv
+ (nullable NSString *)idfvString;

/// 获取uuid
+ (NSString *)uuid;

/// 获取系统版本号
+ (NSString *)OSVersion;

/// 手机型号
+ (NSString *)deviceModel;

/// 是否是模拟器
+ (BOOL)isSimulator;

@end
```

## 广告用法

如果要使用穿山甲(Bytedance-UnionAD) 请在您的`Podfile`中指定 不用可不导入

```ruby
pod 'Bytedance-UnionAD'
```

如果要使用优量汇广告(GDTMobSDK)  请在您的`Podfile`中指定 不用可不导入

```ruby
pod 'GDTMobSDK'
```

如果要使用谷歌广告  请在您的`Podfile`中指定 不用可不导入

```cpp
pod 'Google-Mobile-Ads-SDK'
```

SDK 需要在 AppDelegate 的方法 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 里进行初始化

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    /**
    * 广告注册接口，请在app初始化时调用。
    */
    [RXAdSDKConfig initWithAppId:@"app id" completionBlock:^(NSError * _Nonnull error) {

    }];
}
```

### 开屏广告

类型说明：开屏广告主要是 APP 启动时展示的全屏广告视图，开发只要按照接入标准就能够展示设计好的视图。

开屏示例

```objective-c
/// 加载开屏广告
-(void)addSplashAd
{
    // 显示底部logo等
    UIView *BottomView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, 120)];
    
    // 初始化开屏
    self.splashAdView = [[RXSplashAdView alloc] initWithRootViewController:self.window.rootViewController WithBottomView: BottomView];
    // 拉取广告超时时间 默认为3秒
    self.splashAdView.fetchDelay = 5;
    // 代理
    self.splashAdView.delegate = self;
    // 发起拉取广告请求
    [self.splashAdView loadAdData];
}

#pragma mark - RXSplashAdViewDelegate
/**
 *  开屏广告素材加载成功
 */
- (void)splashAdDidLoad:(RXSplashAdView *)splashAd
{
    [self.splashAdView showAdInWindow:self.window];
}
/**
 *  开屏广告展示失败
 */
- (void)splashAdFailToPresent:(RXSplashAdView *)splashAd withError:(NSError *)error
{
    [self removeSplashAd];
}
/**
 *  开屏广告将要关闭回调
 */
- (void)splashAdWillClose:(RXSplashAdView *)splashAd
{
    [self removeSplashAd];
}
// 移除开屏广告
-(void)removeSplashAd
{
    [self.splashAdView removeFromSuperview];
    self.splashAdView.delegate = nil;
    self.splashAdView = nil;
}
```

### 激励视频

这类广告的长度为 15-30 秒，不可跳过，且广告的结束画面会显示结束页面，引导用户进行后续动作。

RXRewardedVideoAd 激励视频示例

```objective-c
-(void)loadRewardedVideoAd
{
    // 初始化激励视频广告
    self.rewardedVideoAd = [[RXRewardedVideoAd alloc] init];
    // 设置代理
    self.rewardedVideoAd.delegate = self;
    // 发起拉取广告请求
    [self.rewardedVideoAd loadAdData];
}

#pragma mark - RXRewardedVideoAdDelegate
/**
 * 此方法在成功呈现nativeExpressAdView时调用。
 */
-(void)rx_rewardVideoAdDidLoad:(RXRewardedVideoAd *)rewardedVideoAd
{
    [self.rewardedVideoAd showAdFromRootViewController:self];
}
/**
 * 视频广告播放达到激励条件回调
 * @param verify  验证是否成功
 * @param rewardedVideoAd RXRewardedVideoAd 实例
 */
- (void)rx_rewardVideoAdDidRewardEffective:(RXRewardedVideoAd *)rewardedVideoAd verify:(BOOL)verify
{

}
// 关闭
- (void)rx_rewardVideoAdDidClose:(RXRewardedVideoAd *)rewardedVideoAd
{
    
}
// 加载错误
- (void)rx_rewardVideoAd:(RXRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error
{
    
}
// 播放完成
-(void)rx_rewardVideoAdDidPlayFinish:(RXRewardedVideoAd *)rewardedVideoAd
{

}
```

