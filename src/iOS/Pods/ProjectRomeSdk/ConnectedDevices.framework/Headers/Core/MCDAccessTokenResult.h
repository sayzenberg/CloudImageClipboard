//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

// @brief The status of the MCDAccessTokenRequest.
// Transient errors may be resolved by requesting the ticket again
// (for example if connectivity is temporarily unavailable).
// Permanent errors are communicated via an exception on the getAccessTokenForUserAccountAsync:scopes:completion: call
// on MCDUserAccountProvider.
typedef NS_ENUM(NSInteger, MCDAccessTokenRequestStatus)
{
    MCDAccessTokenRequestStatusSuccess = 0,
    MCDAccessTokenRequestStatusTransientError
};

// clang-format off
// @brief MCDAccessTokenResult is the result of fetching an access token.
__attribute__((visibility("default"))) 
@interface MCDAccessTokenResult : NSObject 
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)resultWithAccessToken:(nullable NSString*)accessToken status:(MCDAccessTokenRequestStatus)status;
- (nullable instancetype)initWithAccessToken:(nullable NSString*)accessToken status:(MCDAccessTokenRequestStatus)status;

@property(nonatomic, readonly) MCDAccessTokenRequestStatus tokenRequestStatus;
@property(nonatomic, readonly, copy, nonnull) NSString* accessToken;

@end
