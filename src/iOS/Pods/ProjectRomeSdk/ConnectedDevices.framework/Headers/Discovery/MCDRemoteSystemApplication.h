//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

@class MCDAppServiceDescription;

__attribute__((visibility("default")))
@interface MCDRemoteSystemApplication : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

@property(nonatomic, readonly, nonnull) NSString* applicationId;
@property(nonatomic, readonly, nonnull) NSString* displayName;

@property(nonatomic, readonly, getter=isAvailableByProximity) BOOL availableByProximity;
@property(nonatomic, readonly, getter=isAvailableBySpatialProximity) BOOL availableBySpatialProximity;

@property(nonatomic, readonly, nonnull) NSDictionary<NSString*, NSString*>* attributes;
@property(nonatomic, readonly, nullable) NSArray<MCDAppServiceDescription*>* appServices;
@end
