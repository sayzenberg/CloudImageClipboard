//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

@class MCDUserActivitySession;
@class MCDUserActivityContentInfo;
@class MCDUserActivityVisualElements;

typedef NS_ENUM(NSInteger, MCDUserActivityState)
{
    New = 0,
    Published
};

// clang-format off
__attribute__((visibility("default")))
@interface MCDUserActivity : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

- (nonnull MCDUserActivitySession*)createSession;
- (void)saveAsync:(nonnull void (^)(NSError* _Nullable))completionBlock;

@property(nonatomic, readonly, nonnull) NSString* activityId;
@property(nonatomic, readonly) MCDUserActivityState state;
@property(nonatomic, copy, nonnull) NSString* contentUri;
@property(nonatomic, copy, nonnull) NSString* fallbackUri;
@property(nonatomic, copy, nonnull) NSString* contentType;
@property(nonatomic, copy, nonnull) NSString* activationUri;
@property(nonatomic, strong, nonnull) MCDUserActivityContentInfo* contentInfo;
@property(nonatomic, copy, nonnull) MCDUserActivityVisualElements* visualElements;

@end
