//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "MCDNotificationRegistration.h"

// @brief Raises the event, informing all listeners from the connected devices framework that notification registration has changed.

// clang-format off
// TODO: #14276872 - MCDRegistrationUpdatedEvent should either inherited or customized from common event
// which does most internal heavy lifting
__attribute__((visibility("default"))) 
@interface MCDRegistrationUpdatedEvent : NSObject

// @brief Raises the event, informing all listeners from the connected devices framework that notification registration has changed.
-(void)raiseWithNotificationRegistration : (nonnull MCDNotificationRegistration*)notificationRegistration;
@end

// @brief App implements this protocol to be come a notification registration provider.
__attribute__((visibility("default"))) 
@protocol MCDNotificationProvider<NSObject>

// @brief platform query app for current notification registration
- (void)getNotificationRegistrationAsync: (nonnull void (^)(MCDNotificationRegistration* _Nullable, NSError* _Nullable))completionBlock;

// @brief when notification token changes, app needs to raise this event.
@property(nonatomic, readonly, strong, nonnull) MCDRegistrationUpdatedEvent* registrationUpdated;

@end
