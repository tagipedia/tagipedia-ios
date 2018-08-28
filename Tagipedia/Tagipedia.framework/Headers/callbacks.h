//
//  callbacks.h
//  TbeaconManger
//
//  Created by Tagipedia on 2/21/18.
//  Copyright © 2018 Tagipedia. All rights reserved.
//
//#import "TGTopic.h"
//typedef void (^ onNotificationPressed)(TGTopic *topic);
typedef void (^ onNotificationPressed)(NSDictionary *data);

typedef void (^ onLoggedEventRecord)(NSDictionary *data);
