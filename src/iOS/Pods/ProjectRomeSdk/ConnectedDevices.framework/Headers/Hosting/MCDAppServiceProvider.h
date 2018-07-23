//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/NSObject.h>
#import "Discovery/MCDAppServiceDescription.h"

@class MCDAppServiceConnection;

// clang-format off
__attribute__((visibility("default"))) 
@protocol MCDAppServiceProvider<NSObject> 

- (void)connectionDidOpen: (nonnull MCDAppServiceConnection*)connection;

@property(nonatomic, readonly, strong, nonnull) MCDAppServiceDescription* appServiceDescription;

@end
