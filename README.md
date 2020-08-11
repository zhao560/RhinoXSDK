## 使用CocoaPods安装

要使用CocoaPods将RhinoXSDK集成到您的Xcode项目中，请在您的`Podfile`中指定

```ruby
pod 'RhinoXSDK', '~> 1.0.4'
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

如果要使用穿山甲(Bytedance-UnionAD) 请在您的`Podfile`中指定

```ruby
pod 'Bytedance-UnionAD'
```

如果要使用优量汇广告(GDTMobSDK) 请在您的`Podfile`中指定

```ruby
pod 'GDTMobSDK'
```

SDK 需要在 AppDelegate 的方法 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 里进行初始化

```objective-c
// 穿山甲设置 appID 
[RXAdConfig setBUAdWithAppID: @""];
// 优量汇设置 appID 
[RXAdConfig setGDTAdWithAppID: @""];
```

### 开屏广告

类型说明：开屏广告主要是 APP 启动时展示的全屏广告视图，开发只要按照接入标准就能够展示设计好的视图。

RXSplashAdView接口说明

```objective-c
@interface RXSplashAdView : UIView
/**
 *  委托对象
 */
@property (nonatomic, weak) id<RXSplashAdViewDelegate> delegate;

/**
 * 穿山甲广告位id
 */
@property (nonatomic, copy, nonnull) NSString *BUSlotID;

/**
 * 广点通广告位id
 */
@property (nonatomic, copy, nonnull) NSString *GDTSlotID;

/**
 *  拉取广告超时时间，默认为3秒
 *  详解：拉取广告超时时间，开发者调用loadAd方法以后会立即展示backgroundImage，然后在该超时时间内，如果广告拉
 *  取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) CGFloat fetchDelay;

/**
 * 用于处理ad操作的根视图控制器
 */
@property (nonatomic, weak) UIViewController *rootViewController;

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
- (void)showAdInWindow:(UIWindow *)window skipView:(UIView * _Nullable)skipView;

@end
```

RXSplashAdView回调

```objective-c

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
 *  开屏广告将要关闭回调
 */
- (void)splashAdWillClose:(RXSplashAdView *)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)splashAdDidClose:(RXSplashAdView *)splashAd;

@end
```

开屏示例

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    // 穿山甲设置 appID
    [RXAdConfig setBUAdWithAppID: @""];
    // 优量汇设置 appID
    [RXAdConfig setGDTAdWithAppID: @""];
  
    // 初始化开屏
    self.splashAdView = [[RXSplashAdView alloc] initWithRootViewController:self.window.rootViewController
                                                            WithBottomView:nil];
    // 拉取广告超时时间 默认为3秒
    self.splashAdView.fetchDelay = 5;
    // 代理
    self.splashAdView.delegate = self;
    // 穿山甲广告位id 不填则不加载穿山甲开屏
    self.splashAdView.BUSlotID = @"";
    // 优量汇广告位id 不填则不加载优量汇开屏
    self.splashAdView.GDTSlotID = @"";
    // 发起拉取广告请求
    [self.splashAdView loadAdData];
}

#pragma mark - RXSplashAdViewDelegate
/**
 *  开屏广告素材加载成功
 */
- (void)splashAdDidLoad:(RXSplashAdView *)splashAd
{
    [self.splashAdView showAdInWindow:self.window skipView:nil];
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
    // 穿山甲广告位id 不填则不加载穿山甲开屏
    self.rewardedVideoAd.BUSlotID = @"";
    // 优量汇广告位id 不填则不加载优量汇开屏
    self.rewardedVideoAd.GDTSlotID = @"";
    // 设置代理
    self.rewardedVideoAd.delegate = self;
    // 发起拉取广告请求
    [self.rewardedVideoAd loadAdData];
}

#pragma mark - RXRewardedVideoAdDelegate
/**
 * 此方法在成功呈现nativeExpressAdView时调用。
 */
-(void)rx_rewardedVideoAdViewRenderSuccess:(RXRewardedVideoAd *)rewardedVideoAd
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

