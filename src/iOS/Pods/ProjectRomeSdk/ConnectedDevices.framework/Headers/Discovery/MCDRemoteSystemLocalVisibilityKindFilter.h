//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "MCDRemoteSystemFilter.h"

typedef NS_ENUM(NSInteger, MCDRemoteSystemLocalVisibilityKind)
{
    MCDRemoteSystemLocalVisibilityKindShowAll = 0,
    MCDRemoteSystemLocalVisibilityKindHideLocalApplication
};

__attribute__((visibility("default")))
@interface MCDRemoteSystemLocalVisibilityKindFilter : NSObject <MCDRemoteSystemFilter>
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)filterWithLocalVisibilityKind:(MCDRemoteSystemLocalVisibilityKind)localVisibilityKind;
- (nullable instancetype)initWithLocalVisibilityKind:(MCDRemoteSystemLocalVisibilityKind)localVisibilityKind;

@property(nonatomic, readonly) MCDRemoteSystemLocalVisibilityKind localVisibilityKind;

@end
