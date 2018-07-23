//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

@class MCDUserDataFeed;
@class MCDUserActivity;
@class MCDUserActivitySessionHistoryItem;
@class MCDSyncScope;

__attribute__((visibility("default"))) @interface MCDUserActivityChannel : NSObject + (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)userActivityChannelWithUserDataFeed:(nonnull MCDUserDataFeed*)userDataFeed;

+ (nonnull MCDSyncScope*)syncScope;

- (void)getOrCreateUserActivityAsync:(nonnull NSString*)activityId
                          completion:(nonnull void (^)(MCDUserActivity* _Nonnull, NSError* _Nullable))completionBlock;
- (void)deleteActivityAsync:(nonnull NSString*)activityId completion:(nonnull void (^)(NSError* _Nullable))completionBlock;
- (void)deleteAllActivitiesAsync:(nonnull void (^)(NSError* _Nullable))completionBlock;
- (void)getRecentUserActivitiesAsync:(NSInteger)maxUniqueActivities
                          completion:
                              (void (^_Nonnull)(NSArray<MCDUserActivitySessionHistoryItem*>* _Nonnull, NSError* _Nullable))completionBlock;
- (void)getSessionHistoryItemsForUserActivityAsync:(nonnull NSString*)activityId
                                     withStartTime:(nonnull NSDate*)startTime
                                        completion:(void (^_Nonnull)(NSArray<MCDUserActivitySessionHistoryItem*>* _Nonnull,
                                                       NSError* _Nullable))completionBlock;
@end