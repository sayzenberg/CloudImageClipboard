//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

__attribute__((visibility("default")))
@interface MCDRemoteSystemKinds : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

@property(class, copy, readonly, nonnull) NSString* desktop;
@property(class, copy, readonly, nonnull) NSString* holographic;
@property(class, copy, readonly, nonnull) NSString* hub;
@property(class, copy, readonly, nonnull) NSString* phone;
@property(class, copy, readonly, nonnull) NSString* xbox;
@property(class, copy, readonly, nonnull) NSString* laptop;
@property(class, copy, readonly, nonnull) NSString* iot;
@property(class, copy, readonly, nonnull) NSString* tablet;
@end
