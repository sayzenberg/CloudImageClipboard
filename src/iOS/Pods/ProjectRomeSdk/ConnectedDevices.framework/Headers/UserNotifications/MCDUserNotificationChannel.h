//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

@class MCDUserDataFeed;
@class MCDUserNotification;
@class MCDUserNotificationChangeReader;
@class MCDUserNotificationFilter;
@class MCDUserNotificationReader;
@class MCDUserNotificationUpdateStatus;
@class MCDSyncScope;

// @brief The IUserNotificationChannel, which is backed by AFS.
// This store will manage the life cycle of the UserNotifications.
__attribute__((visibility("default")))
@interface MCDUserNotificationChannel : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

// @brief Factory method.
+ (nullable instancetype)userNotificationChannelWithUserDataFeed:(nonnull MCDUserDataFeed*)userDataFeed;

+ (nonnull MCDSyncScope*)syncScope;

// @brief An event that fires whenever the user notifications data changes. The parameter passed in here is the sender and the query to
// get the changes.
- (NSUInteger)addDataChangedListener:(nonnull void (^)(MCDUserNotificationChannel* _Nonnull))listener;
- (void)removeDataChangedListener:(NSUInteger)eventRegistrationToken;

// @brief Obtain all the user notifications
// If the store is unable to sync from user notification service, the stored offline notifications will be returned.
- (MCDUserNotificationReader* _Nullable)createReaderWithFilter:(nonnull MCDUserNotificationFilter*)filter;

// @brief Obtain all the user notifications
// @param readerState (optional) determines the state of the reader, to allow reader to start from an advanced position.
// If the store is unable to sync from user notification service, the stored offline notifications will be returned.
- (MCDUserNotificationReader* _Nullable)createReaderWithState:(nonnull NSString*)readerState;

// @brief Get the changes that happened to user notifications.
// @param readerState (optional) determines the state of the reader, to allow reader to start from an advanced position.
// This will allow you to get all the changes (C/U/D) that happened the notifications that has not been explicitly accepted by the
// developer.
- (MCDUserNotificationChangeReader* _Nullable)createChangeReaderWithState:(nullable NSString*)readerState;

// @brief Obtain the UserNotification object associated with the notification Id
- (void)getUserNotificationAsync:(nonnull NSString*)notificationId
                      completion:(nonnull void (^)(MCDUserNotification* _Nullable, NSError* _Nullable))completion;

// @brief Delete a notification corresponding to the notificationId parameter
// If we are unable to send the delete to UserNotification service (e.g connectivity lost), we will attempt to send it when we are able
// to contact UserNotification service. When the delete is being sent to the UserNotification service after being deferred, any errors
// will be communicated via callback.
- (void)deleteUserNotificationAsync:(NSString* _Nonnull)notificationId
                         completion:(nonnull void (^)(MCDUserNotificationUpdateStatus* _Nullable, NSError* _Nullable))completion;
@end
