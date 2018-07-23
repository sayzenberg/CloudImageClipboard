//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "MCDRemoteSystemFilter.h"

// @brief Authorization / owner of remote system
typedef NS_ENUM(NSInteger, MCDRemoteSystemAuthorizationKind)
{
    MCDRemoteSystemAuthorizationKindSameUser = 0,
    MCDRemoteSystemAuthorizationKindAnonymous
};

__attribute__((visibility("default")))
@interface MCDRemoteSystemAuthorizationKindFilter : NSObject <MCDRemoteSystemFilter>
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)filterWithAuthorizationKind:(MCDRemoteSystemAuthorizationKind)authorizationKind;
- (nullable instancetype)initWithAuthorizationKind:(MCDRemoteSystemAuthorizationKind)authorizationKind;

@property(nonatomic, readonly) MCDRemoteSystemAuthorizationKind authorizationKind;

@end
