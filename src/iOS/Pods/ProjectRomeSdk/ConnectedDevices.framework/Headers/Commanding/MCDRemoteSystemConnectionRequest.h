//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import "Discovery/MCDRemoteSystem.h"
#import "Discovery/MCDRemoteSystemApplication.h"

__attribute__((visibility("default")))
@interface MCDRemoteSystemConnectionRequest : NSObject

+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)requestWithRemoteSystem:(nonnull MCDRemoteSystem*)remoteSystem;
+ (nullable instancetype)requestWithRemoteSystemApplication:(nonnull MCDRemoteSystemApplication*)remoteSystemApplication;
- (nullable instancetype)initWithRemoteSystem:(nonnull MCDRemoteSystem*)remoteSystem;
- (nullable instancetype)initWithRemoteSystemApplication:(nonnull MCDRemoteSystemApplication*)remoteSystemApplication;

@end
