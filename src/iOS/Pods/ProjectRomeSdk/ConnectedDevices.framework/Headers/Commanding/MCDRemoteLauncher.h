//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

#import "MCDRemoteLauncherOptions.h"
#import "MCDRemoteSystemConnectionRequest.h"

// @brief Status of a URI launch
typedef NS_ENUM(NSInteger, MCDRemoteLaunchUriStatus)
{
    MCDRemoteLaunchUriStatusUnknown = 0,
    MCDRemoteLaunchUriStatusSuccess,
    MCDRemoteLaunchUriStatusAppUnavailable,
    MCDRemoteLaunchUriStatusProtocolUnavailable,
    MCDRemoteLaunchUriStatusRemoteSystemUnavailable,
    MCDRemoteLaunchUriStatusDataSetTooLarge,
    MCDRemoteLaunchUriStatusDeniedByLocalSystem,
    MCDRemoteLaunchUriStatusDeniedByRemoteSystem
};

// clang-format off
__attribute__((visibility("default")))
@interface MCDRemoteLauncher : NSObject

- (void)launchUriAsync:(nonnull NSString*)uri
 withConnectionRequest:(nonnull MCDRemoteSystemConnectionRequest*)connection
            completion:(nullable void (^)(MCDRemoteLaunchUriStatus result, NSError* _Nullable error))completionBlock;

- (void)launchUriAsync:(nonnull NSString*)uri
 withConnectionRequest:(nonnull MCDRemoteSystemConnectionRequest*)connection
               options:(nonnull MCDRemoteLauncherOptions*)options
            completion:(nullable void (^)(MCDRemoteLaunchUriStatus result, NSError* _Nullable error))completionBlock;

@end