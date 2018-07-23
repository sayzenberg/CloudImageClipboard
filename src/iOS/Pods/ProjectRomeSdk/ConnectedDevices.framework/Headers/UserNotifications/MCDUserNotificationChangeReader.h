//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

@class MCDUserNotificationChange;

// @brief Used to get the results of notifications query
__attribute__((visibility("default")))
@interface MCDUserNotificationChangeReader : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

// @brief Returns the current state of the change reader. Can be used to construct a new reader starting from the same state
// Based upon the last completed batch of notification changes (or initial state, if none have completed successfully)
@property(nonatomic, readonly, nonnull) NSString* serializedState;

// @brief Used to get the next batch of notifications from the current query, up to the limit set the by the caller. Set the limit to 0
// to get all the rest of notifications.
- (void)readBatchAsyncWithMaxSize:(NSUInteger)maxBatchSize
                       completion:(nonnull void (^)(NSArray<MCDUserNotificationChange*>* _Nullable, NSError* _Nullable))completion;
@end
