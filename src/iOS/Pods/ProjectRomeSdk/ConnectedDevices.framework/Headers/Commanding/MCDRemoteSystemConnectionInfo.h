//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import "Commanding/MCDAppServiceConnection.h"

// clang-format off
__attribute__((visibility("default")))
@interface MCDRemoteSystemConnectionInfo : NSObject

+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;
// clang-format on

@property(nonatomic, readonly) BOOL isProximal;

+ (nullable instancetype)tryCreateFromAppServiceConnection:(nonnull MCDAppServiceConnection*)appServiceConnection;

@end
