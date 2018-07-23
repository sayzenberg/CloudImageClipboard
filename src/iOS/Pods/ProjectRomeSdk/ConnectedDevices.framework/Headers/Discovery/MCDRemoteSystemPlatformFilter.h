//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "MCDRemoteSystem.h"
#import "MCDRemoteSystemFilter.h"

// clang-format off
__attribute__((visibility("default"))) 
@interface MCDRemoteSystemPlatformFilter : NSObject<MCDRemoteSystemFilter> 
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)filterWithPlatform:(MCDRemoteSystemPlatform)platformType;
- (nullable instancetype)initWithPlatform:(MCDRemoteSystemPlatform)platformType;

@property(nonatomic, readonly) MCDRemoteSystemPlatform type;

@end
