//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

@class MCDUserNotificationUpdateStatus;

// @brief Read status of a User Notification
typedef NS_ENUM(NSInteger, MCDUserNotificationReadState)
{
    MCDUserNotificationReadStateUnread = 0,
    MCDUserNotificationReadStateRead
};

// @brief User state of User Notification
typedef NS_ENUM(NSInteger, MCDUserNotificationUserActionState)
{
    MCDUserNotificationUserActionStateNoInteraction = 0,
    MCDUserNotificationUserActionStateActivated,
    MCDUserNotificationUserActionStateSnoozed,
    MCDUserNotificationUserActionStateDismissed
};

// @brief Priority of the User Notification
typedef NS_ENUM(NSInteger, MCDUserNotificationPriority)
{
    MCDUserNotificationPriorityUnknown = 0,
    MCDUserNotificationPriorityHigh,
    MCDUserNotificationPriorityMedium,
    MCDUserNotificationPriorityLow
};

// @brief User notification created by User's notification channel
__attribute__((visibility("default")))
@interface MCDUserNotification : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

// @brief Get the ID
@property(nonatomic, readonly, nonnull) NSString* notificationId;
// @brief Get the group ID
@property(nonatomic, readonly, nonnull) NSString* groupId;
// @brief Get the expiration time
@property(nonatomic, readonly, nonnull) NSDate* expirationTime;
// @brief Get the priority
@property(nonatomic, readonly) MCDUserNotificationPriority priority;
// @brief Get the content
@property(nonatomic, readonly, nonnull) NSString* content;

// @brief Get/Set read state
@property(nonatomic, readwrite) MCDUserNotificationReadState readState;
// @brief Get/Set the user action state
@property(nonatomic, readwrite) MCDUserNotificationUserActionState userActionState;

// @brief Save the notification
- (void)saveAsync:(nonnull void (^)(MCDUserNotificationUpdateStatus* _Nullable, NSError* _Nullable))completion;
@end
