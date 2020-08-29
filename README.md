# methinksSDK-iOS

The methinks iOS SDK allows you to track user journey and survey specific groups of your mobile app users. Understanding specific user behaviors and journey will be done with single line of code and initialize in-app survey for specific target group of users. Check more detail in [methinks](https://www.methinks.io) to create your account and acquire product key to begin with.  If you're interested in Android version go [here](https://www.methinks.io).

## Requirements

SDK works on iOS at least on version 10.

## Installation

### CocoaPods

We recommend using Cocoapods to get methinksSDK for iOS. 
Define pod in your `Podfile`:
```ruby

pod 'methinksSDK-iOS'

```

and run `pod install`.

### Manual installation

Download most recent SDK at [here](https://github.com/methinksBot/methinks-iOS/releases).
Once download the zipped file, embed `methinksiOS.framework` to your project target. 

## Setup

Before move on, please make sure you get the `clientKey` and `productKey` from [methinks](https://www.methinks.io).
You should initialize the SDK at the begging of your app's life cycle, a good place will be in `AppDelegate` class. 

Enable `autoTracking` to automatically analyze user journey. 

Swift:
```swift
import methinksSDK_iOS

func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {

  MTKSDK.shared().initialize(withClientKey: "YOUR CLIENT KEY", productKey: "YOUR PRODUCT KEY", autoTracking: true)

  return true
}
```

Obj-C:
```objc
#import <methinksiOS/MTKSDK.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

  [[MTKSDK shared] initializeWithClientKey:@"myClientKey" productKey:@"x12345" autoTracking:YES];

return YES;
}
```

## User Journey Tracking
methinks SDK tracks user journey based on `UIViewController` class and user's interaction with it. There are a few options you can adjust to get the most comprehensive journey data. 


### Custom view controller title 
If you enable `autoTracking`, SDK will capture user journey based on `UIViewController` name. If you want to setup more easy-to-understand name, you can set custom tracking view name. A good place will be `viewDidAppear:` in your `UIViewController`, before user interact with current view controller. 

Swift:
```swift
  override func viewDidAppear(_ animated: Bool) {
    super.viewDidAppear(animated)
    MTKSDK.shared().setViewController(self, withCustomTitle: "UserOptionSettingView")
  }
  ```

Obj-C:
```objc
- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [[MTKSDK shared] setViewController:self withCustomTitle:@"OptionSettionView"];
} 
```


### Add import view to tracking
If you app isn't based on `UIViewController` or is using many views in same `UIViewController` such as `UIHostingController` in `SwiftUI`, you can add any views to journey tracking. A good place would be when the view created and fully visible to user and user is ready to interact with the view. 

Swift:
```swift
  MTKSDK.shared().setCustomTrackingViewTitle("OptionSettingView")
```

Obj-C:
```objc
  [[MTKSDK shared] setCustomTrackingViewTitle:@"OptionSettingView"];
```

### Disable view tracking
You can exclude a `UIViewController` from auto tracking if the viewController is meaningless in user journey. A good place will be `viewDidAppear:` in your `UIViewController`, before user interact with current view controller. 

Swift:
```swift
  override func viewDidAppear(_ animated: Bool) {
    super.viewDidAppear(animated)
    MTKSDK.shared().disableViewTracking()
  }
```

Obj-C:
```objc
- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [[MTKSDK shared] disableViewTracking];
} 
```

## In-App Survey
methinks SDK provides fully-featured in-app survey which is optimized mobile apps with least intrusive presentation. 
To find out more about survey creation or collection real time responses, check [methinks](https://www.methinks.io).

### Decide where and when to show in-app survey
By default, in-app survey will be display at the beginning of new session, before user start any interaction with your app. 
But if your app has important process at the beginning or has longer loading at the beginning, you can set a specific view controller to display in-app survey. A good place would be right after you initialize the target view controller, 

Swift:
```swift
  let homeVC = HomeViewController()
  MTKSDK.shared().setDefaultSurveyViewController(homeVC)
```

Obj-C:
```objc
  HomeViewController* homeVC = [[HomeViewController alloc] init];
  [[MTKSDK shared] setDefaultSurveyViewController:homeVC];
```


## Associate User to In-App Survey and Journey Tracking
To get most out of in-app survey and user journey tracking, associating user attributes and custom events is highly recommended. For example, if you associate your identifiable unique userID with methinksSDK, you can specifically target the user to deliver in-app survey or tracking specific journey. 

Swift:
```swift
  MTKSDK.shared().setUserId:"X1234567"
```

Obj-C:
```objc
  [[MTKSDK shared] setUserId:@"X1234567"];
```

Add user attributes if available so that you are target specific group of users for in-app survey. For example, if you want to deliver surveys to female users only, 

Swift:
```swift
  MTKSDK.shared().setUserAttributes:"X1234567"
```

Obj-C:
```objc
  [[MTKSDK shared] setUserId:@"X1234567"];
```









