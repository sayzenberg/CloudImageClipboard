//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

// @brief type of notification
typedef NS_ENUM(NSInteger, MCDNotificationType)
{
    MCDNotificationTypeNone = 0,
    MCDNotificationTypeWNS,
    MCDNotificationTypeGCM,
    MCDNotificationTypeFCM,
    MCDNotificationTypeAPN
};

// clang-format off
// @brief represent a notification registration
__attribute__((visibility("default"))) 
@interface MCDNotificationRegistration : NSObject

+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)registrationWithNotificationType:(MCDNotificationType)notificationType
                                                    token:(nonnull NSString*)token
                                                    appId:(nonnull NSString*)appId
                                           appDisplayName:(nonnull NSString*)appDisplayName;

- (nullable instancetype)initWithNotificationType:(MCDNotificationType)notificationType
                                            token:(nonnull NSString*)token
                                            appId:(nonnull NSString*)appId
                                   appDisplayName:(nonnull NSString*)appDisplayName;

@property(nonatomic, readonly) MCDNotificationType type;
@property(nonatomic, readonly, nonnull) NSString* token;
@property(nonatomic, readonly, nonnull) NSString* applicationId;
@property(nonatomic, readonly, nonnull) NSString* applicationDisplayName;

@end
