//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

__attribute__((visibility("default")))
@interface MCDUserActivityContentInfo : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;
+ (nullable instancetype)fromJson:(nonnull NSString*)contentInfo;
- (nonnull NSString*)toJson;
@end
