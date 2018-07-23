//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

// @brief Enum for state of notifications requested
typedef NS_ENUM(NSInteger, MCDUserNotificationReadStateFilter)
{
    MCDUserNotificationReadStateFilterAny = 0,
    MCDUserNotificationReadStateFilterUnread,
    MCDUserNotificationReadStateFilterRead
};

// @brief Enum for state of notifications requested
typedef NS_ENUM(NSInteger, MCDUserNotificationUserActionStateFilter)
{
    MCDUserNotificationUserActionStateFilterAny = 0,
    MCDUserNotificationUserActionStateFilterNoInteraction,
    MCDUserNotificationUserActionStateFilterActivated,
    MCDUserNotificationUserActionStateFilterSnoozed,
    MCDUserNotificationUserActionStateFilterDismissed,
};

// @brief Filter for querying user notifications
__attribute__((visibility("default")))
@interface MCDUserNotificationFilter : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

// @brief Factory method
+ (nullable instancetype)userNotificationFilterWithReadStateFilter:(MCDUserNotificationReadStateFilter)readStateFilter
                                             userActionStateFilter:(MCDUserNotificationUserActionStateFilter)userActionStateFilter;

// @brief Get the filter for read state
@property(nonatomic, readonly) MCDUserNotificationReadStateFilter readStateFilter;
// @brief Get the filter for user action state
@property(nonatomic, readonly) MCDUserNotificationUserActionStateFilter userActionStateFilter;
@end
