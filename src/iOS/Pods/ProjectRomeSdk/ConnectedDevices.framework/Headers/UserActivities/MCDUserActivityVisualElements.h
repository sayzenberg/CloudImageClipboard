//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGColor.h>

@class MCDUserActivityAttribution;

// clang-format off
__attribute__((visibility("default"))) 
@interface MCDUserActivityVisualElements : NSObject 
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

@property(nonatomic, copy, nonnull) NSString* displayText;
@property(nonatomic, assign, nonnull) CGColorRef backgroundColor;
@property(nonatomic, copy, nonnull) NSString* descriptionText;
@property(nonatomic, copy, nonnull) MCDUserActivityAttribution* attribution;
@property(nonatomic, copy, nonnull) NSString* content;
@property(nonatomic, copy, nonnull) NSString* attributionDisplayText;

@end
