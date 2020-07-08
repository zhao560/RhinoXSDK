//
//  RXRewardedVideoModel.h
//  TestAd
//
//  Created by daidai on 2020/6/29.
//  Copyright © 2020 daidia. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXRewardedVideoModel : NSObject

@property (nonatomic, copy) NSString *userId;

//optional. reward name.
@property (nonatomic, copy) NSString *rewardName;

//optional. number of rewards.
@property (nonatomic, assign) NSInteger rewardAmount;

//optional. serialized string.
@property (nonatomic, copy) NSString *extra;

@end

NS_ASSUME_NONNULL_END
