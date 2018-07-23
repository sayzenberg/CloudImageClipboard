//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

@class MCDUserNotification;

// @brief Type of notification change
typedef NS_ENUM(NSInteger, MCDUserNotificationChangeType)
{
    MCDUserNotificationChangeTypeActive = 0,
    MCDUserNotificationChangeTypeDeleted
};

// @brief Object returned from a change list
__attribute__((visibility("default")))
@interface MCDUserNotificationChange : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

// @brief Get the underlying notification
@property(nonatomic, readonly, nonnull) MCDUserNotification* notification;
// @brief Get the type of change
@property(nonatomic, readonly) MCDUserNotificationChangeType changeType;
// @brief Get the time the change was made
@property(nonatomic, readonly, nonnull) NSDate* changeTime;
@end
