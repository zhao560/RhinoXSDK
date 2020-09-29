//
//  RXSecurityUtil.h
//  RhinoXCore_source
//
//  Created by daidai on 2020/6/24.
//  Copyright © 2020 daidia. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXSecurityUtil : NSObject

/**
 * 加密
 * @string  加密字符串
 * @key  密码
 */
+(nullable NSString *) encryptAESString:(NSString *)string key:(NSString *)key;

/**
 * 解密
 * @string  解密字符串
 * @key  密码
 */
+(nullable NSString *) decryptAESString:(NSString *)string key:(NSString *)key;

/**
 * json 转 数组or字典
 * @json  json字符串
 * @return 数组or字典
 */
+ (id)jsonToObject:(NSString *)json;

/**
 * 数组or字典转json
 * @obj  数组or字典
 * @return json字符串
 */
+ (nullable NSString *)objectToJson:(id)obj;

@end

NS_ASSUME_NONNULL_END
