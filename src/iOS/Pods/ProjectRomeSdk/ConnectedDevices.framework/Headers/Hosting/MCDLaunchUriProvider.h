//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

// clang-format off
__attribute__((visibility("default")))
@protocol MCDLaunchUriProvider <NSObject>
- (void)onLaunchUriAsync:(nonnull NSString*)uri
         withFallbackUri:(nonnull NSString*)fallbackUri
         preferredPackageIds:(nonnull NSArray<NSString*>*)preferredPackageIds
              completion:(nonnull void (^)(BOOL, NSError* _Nullable))completionBlock;
@property(nonatomic, readonly, strong, nonnull) NSArray<NSString*>* supportedUriSchemes;
@end