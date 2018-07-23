//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "MCDRemoteSystem.h"
#import "MCDRemoteSystemFilter.h"

// @brief remote system watcher errors
// Used for communicating errors during discovery
typedef NS_ENUM(NSInteger, MCDRemoteSystemWatcherError)
{
    MCDRemoteSystemWatcherErrorUnknown = 0,
    MCDRemoteSystemWatcherErrorInternetNotAvailable,
    MCDRemoteSystemWatcherErrorAuthenticationError
};

// @brief MCDRemoteSystemWatcher is the result of a successful user sign in.
// clang-format off
__attribute__((visibility("default")))
@interface MCDRemoteSystemWatcher : NSObject

+ (nullable instancetype)watcher;
// clang-format on
+ (nullable instancetype)watcherWithFilters:(nonnull NSArray<NSObject<MCDRemoteSystemFilter>*>*)filters;
- (nullable instancetype)initWithFilters:(nonnull NSArray<NSObject<MCDRemoteSystemFilter>*>*)filters;

- (void)start;
- (void)stop;

- (NSUInteger)addRemoteSystemAddedListener:(nonnull void (^)(MCDRemoteSystemWatcher* _Nonnull, MCDRemoteSystem* _Nonnull))listener;
- (void)removeRemoteSystemAddedListener:(NSUInteger)eventRegistrationToken;

- (NSUInteger)addRemoteSystemUpdatedListener:(nonnull void (^)(MCDRemoteSystemWatcher* _Nonnull, MCDRemoteSystem* _Nonnull))listener;
- (void)removeRemoteSystemUpdatedListener:(NSUInteger)eventRegistrationToken;

- (NSUInteger)addRemoteSystemRemovedListener:(nonnull void (^)(MCDRemoteSystemWatcher* _Nonnull, MCDRemoteSystem* _Nonnull))listener;
- (void)removeRemoteSystemRemovedListener:(NSUInteger)eventRegistrationToken;

- (NSUInteger)addEnumerationCompletedListener:(nonnull void (^)(MCDRemoteSystemWatcher* _Nonnull))listener;
- (void)removeEnumerationCompletedListener:(NSUInteger)eventRegistrationToken;

- (NSUInteger)addErrorOccurredListener:(nonnull void (^)(MCDRemoteSystemWatcher* _Nonnull, MCDRemoteSystemWatcherError))listener;
- (void)removeErrorOccurredListener:(NSUInteger)eventRegistrationToken;

@end
