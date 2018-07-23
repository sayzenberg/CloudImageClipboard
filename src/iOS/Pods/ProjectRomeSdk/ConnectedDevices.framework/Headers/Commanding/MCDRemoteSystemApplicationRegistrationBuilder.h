//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "MCDRemoteSystemApplicationRegistration.h"

// clang-format off
__attribute__((visibility("default"))) 
@interface MCDRemoteSystemApplicationRegistrationBuilder : NSObject 
- (void)addAttribute:(NSString*)value forName : (NSString*)name;
- (MCDRemoteSystemApplicationRegistration*)buildRegistration;
@end