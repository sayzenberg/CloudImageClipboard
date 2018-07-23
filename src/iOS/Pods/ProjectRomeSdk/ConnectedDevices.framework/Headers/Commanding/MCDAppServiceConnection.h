//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "Discovery/MCDAppServiceDescription.h"
#import "MCDAppServiceRequest.h"
#import "MCDAppServiceResponse.h"
#import "MCDRemoteSystemConnectionRequest.h"

typedef NS_ENUM(NSUInteger, MCDAppServiceClosedStatus)
{
    MCDAppServiceClosedStatusCompleted = 0,
    MCDAppServiceClosedStatusCanceled,
    MCDAppServiceClosedStatusResourceLimitsExceeded,
    MCDAppServiceClosedStatusUnknown
};

typedef NS_ENUM(NSUInteger, MCDAppServiceConnectionStatus)
{
    MCDAppServiceConnectionStatusSuccess = 0,
    MCDAppServiceConnectionStatusAppNotInstalled,
    MCDAppServiceConnectionStatusAppUnavailable,
    MCDAppServiceConnectionStatusAppServiceUnavailable,
    MCDAppServiceConnectionStatusUnknown,
    MCDAppServiceConnectionStatusRemoteSystemUnavailable,
    MCDAppServiceConnectionStatusRemoteSystemNotSupportedByApp,
    MCDAppServiceConnectionStatusNotAuthorized
};

// clang-format off
__attribute__((visibility("default")))
@interface MCDAppServiceRequestReceivedEventArgs : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

@property(nonatomic, readonly, nonnull) MCDAppServiceRequest* request;
@end

__attribute__((visibility("default")))
@interface MCDAppServiceConnection : NSObject
- (nullable instancetype)init;

- (nullable instancetype)initWithAppServiceDescription:(nonnull MCDAppServiceDescription*) appServiceDescription;
+ (nullable instancetype)appServiceConnectionWithAppServiceDescription:(nonnull MCDAppServiceDescription*) appServiceDescription;

- (void)openRemoteAsync:(nonnull MCDRemoteSystemConnectionRequest*)connectionRequest
             completion:(nonnull void (^)(MCDAppServiceConnectionStatus, NSError* _Nullable))completion;
- (void)close;

- (void)sendMessageAsync:(nonnull NSDictionary*)message
              completion:(nonnull void (^)(MCDAppServiceResponse* _Nonnull, NSError* _Nullable))completion;

@property(nonatomic, copy, nonnull) MCDAppServiceDescription* appServiceDescription;

- (NSUInteger)addRequestReceivedListener:(nonnull void (^)(
                                             MCDAppServiceConnection* _Nonnull, MCDAppServiceRequestReceivedEventArgs* _Nonnull))listener;
- (void)removeRequestReceivedListener:(NSUInteger)eventRegistrationToken;

- (NSUInteger)addServiceClosedListener:(nonnull void (^)(MCDAppServiceConnection* _Nonnull, MCDAppServiceClosedStatus))listener;
- (void)removeServiceClosedListener:(NSUInteger)eventRegistrationToken;

+ (void)sendSingleMessageAsync:(nonnull NSDictionary*)message
                withConnection:(nonnull MCDRemoteSystemConnectionRequest*)connectionRequest
         appServiceDescription:(nonnull MCDAppServiceDescription*)appServiceDescription
                    completion:(nonnull void (^)(MCDAppServiceResponse* _Nonnull, NSError* _Nullable))completion;
@end
