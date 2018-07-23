//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/NSObject.h>
#import "Commanding/MCDRemoteSystemApplicationRegistration.h"
#import "MCDAppServiceProvider.h"
#import "MCDLaunchUriProvider.h"

// clang-format off
__attribute__((visibility("default")))
@interface MCDHostingRemoteSystemApplicationRegistration : MCDRemoteSystemApplicationRegistration
@property(nonatomic, readonly, nullable) NSArray<id<MCDAppServiceProvider>>* appServiceProviders;
@property(nonatomic, readonly, nullable) id<MCDLaunchUriProvider> launchUriProvider;
@end

