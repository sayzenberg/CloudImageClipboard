//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "MCDUserAccountProvider.h"

// clang-format off
__attribute__((visibility("default")))
@interface MCDPlatform : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)platformWithAccountProvider:(id<MCDUserAccountProvider> _Nullable)accountProvider
                               notificationProvider:(id _Nullable)notificationProvider;
- (nullable instancetype)initWithAccountProvider:(id<MCDUserAccountProvider> _Nullable)accountProvider
                               notificationProvider:(id _Nullable)notificationProvider;

- (void)shutdownAsync:(void (^_Nonnull)(NSError* _Nullable))completionBlock;

@end
