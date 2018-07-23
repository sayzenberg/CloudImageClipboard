//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, MCDCloudRegistrationStatus)
{
    MCDCloudRegistrationStatusNotStarted = 0,
    MCDCloudRegistrationStatusInProgress,
    MCDCloudRegistrationStatusSucceeded,
    MCDCloudRegistrationStatusFailed,
};