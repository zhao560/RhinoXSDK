## 使用CocoaPods安装

要使用CocoaPods将RhinoXSDK集成到您的Xcode项目中，请在您的`Podfile`中指定

```ruby
pod 'RhinoXSDK', '~> 1.0.0'
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

应用开启后全屏展现的广告样式

```objective-c
// 初始化开屏广告
self.splashAdView = [[RXSplashAdView alloc] initWithRootViewController:self.window.rootViewController WithBottomView:nil];
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

// 更多使用方式可以参见 SDK Demo 工程
```

### 激励视频

这类广告的长度为 15-30 秒，不可跳过，且广告的结束画面会显示结束页面，引导用户进行后续动作。

```objective-c
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

// 更多使用方式可以参见 SDK Demo 工程
```

