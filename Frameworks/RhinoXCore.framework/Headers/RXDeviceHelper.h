//
//  RXDeviceHelper.h
//  RhinoXCore_source
//
//  Created by daidai on 2020/5/23.
//  Copyright © 2020 daidia. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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

NS_ASSUME_NONNULL_END
