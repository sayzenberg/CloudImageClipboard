//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

// @brief Result status for notification update
typedef NS_ENUM(NSInteger, MCDUserNotificationResult)
{
    MCDUserNotificationResultSuccess = 0,
    MCDUserNotificationResultTransientFailure
};

// @brief The user notification callback status for the async callback
__attribute__((visibility("default")))
@interface MCDUserNotificationUpdateStatus : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

// @brief Get the notificationId
@property(nonatomic, readonly, nonnull) NSString* notificationId;
// @brief The result status for the operation
@property(nonatomic, readonly) MCDUserNotificationResult result;
@end
