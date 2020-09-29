//
//  RXADMobSDKConfig.h
//  RhinoXCore_source
//
//  Created by  zz on 2020/9/3.
//  Copyright © 2020 daidia. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXAdSDKConfig : NSObject

/**
 注册SDK
 
 @param appId 给定的唯一appid
 @param completion 失败原因
 */
+ (void)initWithAppId:(NSString *)appId completionBlock:(void (^)(NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
