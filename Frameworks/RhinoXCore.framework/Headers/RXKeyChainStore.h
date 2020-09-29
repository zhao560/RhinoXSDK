//
//  RXKeyChainStore.h
//  RhinoXCore_source
//
//  Created by daidai on 2020/5/23.
//  Copyright © 2020 daidia. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXKeyChainStore : NSObject

/*!
 保存数据
 @data  要存储的数据
 @identifier 存储数据的标示
 */
+(BOOL)saveData:(id)data withIdentifier:(NSString *)identifier;
 
/*!
 读取数据
  */
+(id)readData:(NSString *)identifier;
 
/*!
 更新数据
 @data  要更新的数据
 */
+(BOOL)updata:(id)data withIdentifier:(NSString *)identifier;
 
/*!
 删除数据
 */
+(void)Delete:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
