//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "Core/MCDUserAccount.h"
#import "MCDCloudRegistrationStatus.h"

// clang-format off
__attribute__((visibility("default")))
@interface MCDRemoteSystemApplicationRegistration : NSObject 
- (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

- (NSUInteger)addCloudRegistrationStatusChangedListener:(nonnull void (^)(MCDUserAccount* _Nonnull, MCDCloudRegistrationStatus))listener;
- (void)removeCloudRegistrationStatusChangedListener:(NSUInteger)eventRegistrationToken;

- (void)start;

@property(nonatomic, readonly, nullable) NSDictionary<NSString*, NSString*>* attributes;

@end

