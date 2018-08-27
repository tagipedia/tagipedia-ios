//
//  Tagipedia.h
//  Tagipedia
//
//  Created by Tagipedia on 2/25/18.
//  Copyright © 2018 Tagipedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "callbacks.h"
@interface Tagipedia : NSObject
@property onNotificationPressed onNotificationPressed;
@property onLoggedEventRecord onLoggedEventRecord;

@property NSString *clientId;
@property NSString *clientSecret;
@property NSString *identifier;
@property NSString *UUID;

- (instancetype)initWithClientId: (NSString *)clientId clientSecret: (NSString *)clientSecret identifer: (NSString *)identifier UUID: (NSString *)UUID;
- (void)build;
+ (void)applicationDidEnterBackground;
- (void)setSameBeaconNotifyPeriod:(double)sameBeaconNotifyPeriod;
- (void)setDifferentBeaconNotifyPeriod:(double)differentBeaconNotifyPeriod;

@end

