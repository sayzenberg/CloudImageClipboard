//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

// clang-format off
__attribute__((visibility("default")))
@interface MCDRemoteLauncherOptions : NSObject

+ (nullable instancetype)optionsWithFallbackUri: (nullable NSString*)fallbackUri 
                            preferredPackageIds: (nullable NSArray<NSString*>*)preferredPackageIds;
                            
- (nullable instancetype)initWithFallbackUri:(nullable NSString*)fallbackUri
                         preferredPackageIds:(nullable NSArray<NSString*>*)preferredPackageIds;

@property(nonatomic, nullable) NSString* fallbackUri;
@property(nonatomic, nullable) NSArray<NSString*>* preferredPackageIds;

@end
