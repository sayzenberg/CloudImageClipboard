//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

__attribute__((visibility("default")))
@interface MCDUserActivityAttribution : NSObject
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

@property(nonatomic, copy, nonnull) NSString* iconUri;
@property(nonatomic, copy, nonnull) NSString* alternateText;
@property(nonatomic, assign) BOOL addImageQuery;

@end
