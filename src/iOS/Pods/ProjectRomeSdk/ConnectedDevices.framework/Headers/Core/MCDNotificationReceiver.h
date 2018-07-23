//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

// clang-format off
__attribute__((visibility("default"))) 
@interface MCDNotificationReceiver : NSObject

+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

// @brief when app receives push notification, it invokes receiveNotification to push the notification to CDP Platform
// returns YES if CDP processed the notification, NO otherwise.
+ (BOOL)receiveNotification:(nonnull NSDictionary*)userInfo;

@end
