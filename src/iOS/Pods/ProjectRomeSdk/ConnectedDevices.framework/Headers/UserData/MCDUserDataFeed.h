#pragma once

#import <Foundation/Foundation.h>
#import "MCDSyncScope.h"

@class MCDPlatform;
@class MCDUserAccount;
@class MCDSyncScope;

typedef NS_ENUM(NSInteger, MCDUserDataSyncStatus)
{
    Queued = 0,
    Synchronized
};

// clang-format off
__attribute__((visibility("default")))
@interface MCDUserDataFeed : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)userDataFeedForAccount:(nonnull MCDUserAccount*)userAccount
                                   platform:(nonnull MCDPlatform*)platform
                         activitySourceHost:(nonnull NSString*)activitySourceHost;

- (void)addSyncScopes:(nonnull NSArray<MCDSyncScope*>*)syncScopes;

- (NSUInteger)addSyncStatusChangedListener:(nonnull void (^)(MCDUserDataFeed* _Nonnull))listener;
- (void)removeSyncStatusChangedListener:(NSUInteger)eventRegistrationToken;

- (void)startSync;

@property(nonatomic, readonly) MCDUserDataSyncStatus syncStatus;

@end
