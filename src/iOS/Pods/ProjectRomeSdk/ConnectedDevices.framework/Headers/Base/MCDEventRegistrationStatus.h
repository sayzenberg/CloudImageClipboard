//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

// @brief Type of registration changed event.
// Specifies whether a registration has been added or removed for listening to an event.
typedef NS_ENUM(NSInteger, MCDEventRegistrationStatus)
{
    MCDEventRegistrationStatusAdded = 0,
    MCDEventRegistrationStatusRemoved
};
