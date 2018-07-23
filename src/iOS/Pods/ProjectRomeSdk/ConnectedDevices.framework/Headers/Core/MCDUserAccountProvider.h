//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "Base/MCDEventRegistrationStatus.h"

@class MCDUserAccount;
@class MCDAccessTokenResult;
@class MCDUserAccountChangedEvent;

// clang-format off
// @brief MCDUserAccountProvider is a protocol that the app developer implements in order to provide an access token for a user account.
__attribute__((visibility("default"))) 
@protocol MCDUserAccountProvider<NSObject>
// @brief Get access token for a user account.
- (void)getAccessTokenForUserAccountIdAsync: (nonnull NSString*)accountId 
                                     scopes: (nonnull NSArray<NSString*>*)scopes 
                                 completion: (nonnull void (^)(MCDAccessTokenResult* _Nullable, NSError* _Nullable))completionBlock;

// @brief Fetch the current snapshot of user accounts.
- (nonnull NSArray<MCDUserAccount*>*)getUserAccounts;

// @brief An event that will be listened to by the connected devices framework.
// When implementing the MCDUserAccountProvider protocol,
// 1) default-init this in your initializer
// 2) whenever a user account is changed (eg: added/removed/interrupted/fixed),
//    this event should be raised ([self.userAccountChanged raise]).
// See MCDUserAccountChangedEvent below for more information.
@property(nonatomic, readonly, strong, nonnull) MCDUserAccountChangedEvent* userAccountChanged;

// @brief token consumer call back Provider if token error happens when using it. isPermanentError is true if the error is permanent
// e.g., requires user to sign in again. false if the token error can be resolved by refreshing.
- (void)onAccessTokenError:(nonnull NSString*)accountId scopes:(nonnull NSArray<NSString*>*)scopes isPermanentError:(BOOL)isPermanentError;
@end

// @brief An event that will be listened to by the connected devices framework.
// An app developer implementing the MCDUserAccountProvider protocol should raise event this whenever a user account is changed
// (eg: added/removed/interrupted/fixed)
__attribute__((visibility("default"))) @interface MCDUserAccountChangedEvent : NSObject

// @brief Subscribes to this event, receiving a callback whenever the event is raised.
// Returns an NSUInteger that can be used to unsubscribe from this event
- (NSUInteger)subscribe : (nonnull void (^)())callback;

// @brief Unsubscribes from this event using the NSUInteger returned from subscribe:
- (void)unsubscribe:(NSUInteger)registration;

// @brief Raises the event, informing all listeners from the connected devices framework that a user account has changed.
- (void)raise;

// @brief Set a callback that will be called whenever a new listener is registered for this event.
- (void)setRegistrationCallback:(nonnull void (^)(MCDEventRegistrationStatus))callback;

// @brief Get the total number of current listeners for this event.
@property(atomic, readonly) NSUInteger subscriberCount;

@end
