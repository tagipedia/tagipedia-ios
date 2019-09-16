# tagipedia-ios

## Installation

### To integrate Tagipedia into your Xcode project, add it to your Podfile:
```
pod 'Tagipedia', :git => "https://github.com/tagipedia/tagipedia-ios.git"
```


## Usage

```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    Tagipedia *newTBuilder =[[Tagipedia alloc] initWithClientId:@"CLIENT_ID" clientSecret:@"CLIENT_SECRET" identifer:@"IDENTIFIER" UUID:@"UUID"];
    
    //to monitoring specific regions
    [newTBuilder setTRegions:[NSArray arrayWithObjects:[[TRegion alloc] initWithUUID:@"UUID" major:major minor:minor ], ..., nil]];
    
    newTBuilder.onNotificationPressed = ^(NSDictionary *data) {
        NSLog(@"topic %@", data[@"ad_data"]);
        // push your view controller here
        // or show ad dialog with its assigned template
        // YOU SHOULD PASS YOUR NAVIGATION CONTROLLER
        [TUtil showAdDialog:data navigation: self.window.rootViewController];
    };
    // change notify period between different beacons notification in millisecond
    // DEFAULT: 10 * 60 * 1000 (10 minutes)
    [newTBuilder setDifferentBeaconNotifyPeriod:1000];
    // change notify period between same beacons notification in millisecond
    // DEFAULT: 30 * 60 * 1000 (30 minutes)
    [newTBuilder setSameBeaconNotifyPeriod:20000];
    // to receive event records
    newTBuilder.onLoggedEventRecord = ^(NSDictionary *data){
        NSLog(@"data %@", data);
    };
    // to receive feature_id if the action of ad is navigate to map location
    // you should open the map and navigate to the location that recived
    newTBuilder.onMapButtonPressed = ^(NSDictionary *data){
        NSLog(@"data %@", data);
        //you should dispatch to map to show navigation dialog
        // @{
        //      @"type": @"SHOW_NAVIGATION_DIALOG",
        //      @"navigation_params": @{@"route_to": [data valueForKey:@"feature_id"]}
        // };
    };
    [newTBuilder build];
    //to register user with interests
    //this will show ads based on matching between ad interests and user interests otherwise it will show ads that was created without interests
    [Tagipedia identifyUser:@"USER_NAME" interests:[NSArray arrayWithObjects:@"INTEREST", @"INTEREST", ..., nil]];
    return YES;
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [Tagipedia applicationDidEnterBackground];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    [Tagipedia applicationDidBecomeActive];
}

- (NSDictionary *)JSONFromFile
{
    NSString *path = [[NSBundle mainBundle] pathForResource:@"TRegions" ofType:@"json"];
    NSData *data = [NSData dataWithContentsOfFile:path];
    return [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:nil];
}

```


### PList Permissions

#### In order to use permissions, your enclosing app needs to grant permissions in the info.plist file. The string message in the key will show in the Alert box when your app requests permissions.
```plist
<key>NSLocationWhenInUseUsageDescription</key>
<string>This is the plist item for NSLocationWhenInUseUsageDescription</string>
<key>NSLocationAlwaysUsageDescription</key>
<string>This is the plist item for NSLocationAlwaysUsageDescription</string>
<key>NSLocationAlwaysAndWhenInUseUsageDescription</key>
<string>This is the plist item for NSLocationAlwaysAndWhenInUseUsageDescription</string>
```

#### you need also to add background modes in info.plist file.
```plist
<key>UIBackgroundModes</key>
<array>
<string>bluetooth-central</string>
<string>fetch</string>
<string>location</string>
<string>remote-notification</string>
</array>
```

### Hint: to show ad with its assigned template.
```objc
[TUtil showAdDialog:data navigation: self.window.rootViewController];
```

### to logout user.
```objc
[Tagipedia logOutUser];
```

### to receive current region user located at you should set the regions (NSArray of TRegion ) before build
```objc
[newTBuilder setTRegions:tBeaconRegions];
```

## Sample code
https://github.com/tagipedia/tagipedia-ios-sample
