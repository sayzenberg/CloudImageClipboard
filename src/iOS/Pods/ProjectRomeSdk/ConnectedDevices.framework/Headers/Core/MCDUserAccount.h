//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>

// @brief The type of the MCDUserAccount.
typedef NS_ENUM(NSInteger, MCDUserAccountType)
{
    MCDUserAccountTypeAAD = 0, // Azure Active Directory Workplace Account
    MCDUserAccountTypeMSA      // Microsoft Personal Account
};

// clang-format off
// @brief MCDUserAccount is the result of a successful user sign in.
__attribute__((visibility("default"))) 
@interface MCDUserAccount : NSObject 
+ (nullable instancetype) new NS_UNAVAILABLE;
- (nullable instancetype)init NS_UNAVAILABLE;

+ (nullable instancetype)accountWithAccountId:(nullable NSString*)accountId type:(MCDUserAccountType)type;
- (nullable instancetype)initWithAccountId:(nullable NSString*)accountId type:(MCDUserAccountType)type;

@property(nonatomic, readonly, copy, nonnull) NSString* accountId;
@property(nonatomic, readonly) MCDUserAccountType type;

@end
