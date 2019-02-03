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
    newTBuilder.onNotificationPressed = ^(NSDictionary *data) {
        NSLog(@"topic %@", data[@"topic"]);
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
    [newTBuilder build];
    return YES;
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [Tagipedia applicationDidEnterBackground];
}
```


### PList Permissions

#### In order to use permissions, your enclosing app needs to grant permissions in the info.plist file. The string message in the key will show in the Alert box when your app requests permissions.
```plist
<key>NSLocationWhenInUseUsageDescription</key>
<string>This is the plist item for NSLocationWhenInUseUsageDescription</string>
<key>NSLocationAlwaysAndWhenInUseUsageDescription</key>
<string>This is the plist item for NSLocationAlwaysAndWhenInUseUsageDescription</string>
```

## Sample code
https://github.com/tagipedia/tagipedia-ios-sample
