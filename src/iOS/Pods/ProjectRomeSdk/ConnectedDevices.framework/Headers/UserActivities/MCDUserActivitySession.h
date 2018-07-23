//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

__attribute__((visibility("default")))
@interface MCDUserActivitySession : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;
- (void)close;
@property(nonatomic, readonly, nonnull) NSString* activityId;
@end
