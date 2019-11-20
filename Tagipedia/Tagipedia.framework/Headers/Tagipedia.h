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
@property onMapButtonPressed onMapButtonPressed;
@property onEnterBeaconRegion onEnterBeaconRegion;
@property onExitBeaconRegion onExitBeaconRegion;

@property NSString *clientId;
@property NSString *clientSecret;
@property NSString *identifier;
@property NSString *UUID;

- (instancetype)initWithClientId: (NSString *)clientId clientSecret: (NSString *)clientSecret identifer: (NSString *)identifier UUID: (NSString *)UUID;
- (void)build;
+ (void)applicationDidEnterBackground;
+ (void)applicationDidBecomeActive;
+ (void)applicationWillEnterForeground;
- (void)setSameBeaconNotifyPeriod:(double)sameBeaconNotifyPeriod;
- (void)setDifferentBeaconNotifyPeriod:(double)differentBeaconNotifyPeriod;
- (void)setTRegions:(NSArray*)tRegions;
+ (void)logOutUser;
+ (void)identifyUser:(NSString*) userName interests:(NSArray*)interests;


@end

