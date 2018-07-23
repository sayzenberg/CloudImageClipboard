//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/NSObject.h>
#import "MCDHostingRemoteSystemApplicationRegistration.h"

// clang-format off
__attribute__((visibility("default"))) 
@interface MCDHostingRemoteSystemApplicationRegistrationBuilder : NSObject 
- (void)addAttribute:(NSString*)value forName : (NSString*)name;
- (void)addAppServiceProvider:(id<MCDAppServiceProvider>)provider;
- (void)setLaunchUriProvider:(id<MCDLaunchUriProvider>)provider;
- (MCDHostingRemoteSystemApplicationRegistration*)buildRegistration;
@end
    // clang-format on