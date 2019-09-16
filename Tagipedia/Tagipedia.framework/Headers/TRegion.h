//
//  TRegion.h
//  Tagipedia
//
//  Created by Tagipedia on 9/8/19.
//  Copyright © 2019 Tagipedia. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TRegion : NSObject
@property (nonatomic) NSString* UUID;
@property (nonatomic) int major;
@property (nonatomic) int minor;
- (instancetype) initWithUUID:(NSString *)UUID major:(int )major minor:(int )minor;
@end

