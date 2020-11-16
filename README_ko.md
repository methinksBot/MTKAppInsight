# methinksSDK-iOS

methinks iOS SDK는 당신의 모바일을 앱을 사용하는 유저들의 행동을 트랙킹, 분석하고 적절하 순간에 in-app survey를 할 수 있게 해주는 SDK입니다. 구체적이 내용은 [methinks](https://www.methinks.io) 에서 확인하시고 사인업 후 clientKey와 productKey를 발급 받아 사용할 수 있습니다. 안드로이드 버전은 [여기](https://www.methinks.io)를 참고하세요.
<br>
## 버전 요구 사항

methinks iOS SDK는 최소 iOS 10 또는 상위 버전에서 작동합니다. 
<br>
## 인스톨

### CocoaPods

methinks SDK는 Cocoapods 로으 설치를 권장합니다. 
`Podfile` 파일에 아래 내용을 추가 주십시오:
```ruby

pod 'methinksSDK-iOS'

```

`pod install`을 실행하여 설치할 수 있습니다.

<br>

### 수동 인스톨

[여기](https://github.com/methinksBot/methinks-iOS/releases) 에서 최신 버전의 framework를 다운 받을 수 있습니다.
다운로드한 zip 파일에서 `methinksiOS.framework` 을 찾아 프로젝트 타겟에 추가하여 주십시오. 

<br>

## 기본 셋업

인스톨을 시작하 전 `clientKey`와 `productKey`를 [methinks](https://www.methinks.io)에서 발급 받았는지 확인해 주십시오.
methinks iOS SDK는 앱의 라이프 사이클이 시작될 때 initialize 해야 하며 `AppDelegate` 클래스에서 아래와 같이 initialize를 진행합니다.  

`autoTracking`을 `true`로 세팅하 자동을 유저 행동 패턴 수집을 시작합니다.  

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
<br>

## User Journey Tracking
methinks SDK tracks user journey based on `UIViewController` class and user's interaction with it. There are a few options you can adjust to get the most comprehensive journey data. 

<br>

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

<br>

### Add important but not viewController views to auto-tracking
If you app isn't based on `UIViewController` or is using many views in same `UIViewController` such as `UIHostingController` in `SwiftUI`, you can add any views to journey tracking. A good place would be when the view created and fully visible to user and user is ready to interact with the view. 

Swift:
```swift
  MTKSDK.shared().setCustomTrackingViewTitle("OptionSettingView")
```

Obj-C:
```objc
  [[MTKSDK shared] setCustomTrackingViewTitle:@"OptionSettingView"];
```
<br>

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
<br>
<br>

methinks SDK takes 1 screenshot per a view periodically to display as representative image in journey tracking. The screenshots are captured from a few very early users, once SDK obtains screenshots from all view, SDK stops taking screenshots. If you think that screenshot could lead to privacy concern, you can set a certain view as **sensitive**. A good place will be `viewDidAppear:` in your `UIViewController`, before user interact with current view controller. The is still be tracked, but SDK will skip taking screenshot. 

Swift:
```swift
  override func viewDidAppear(_ animated: Bool) {
    super.viewDidAppear(animated)
    MTKSDK.shared().setAsSensitiveScreen()
  }
```

Obj-C:
```objc
- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [[MTKSDK shared] setAsSensitiveScreen];
} 
```

<br>

## In-App Survey
methinks SDK provides fully-featured in-app survey which is optimized mobile apps with least intrusive presentation. 
To find out more about survey creation or collection real time responses, check [methinks](https://www.methinks.io).

<br>

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

<br>

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
  <br>
  <br>
  
Add user attributes if available so that you are target specific group of users for in-app survey. For example, if you want to deliver surveys to female users only, first provide the user's gender information to tracking SDK. Value could be number or string and Key must be non-nil string value. You can add multiple key-value combinations and use them for advanced targeting for in-app survey or journey tracking.   

Swift:
```swift
  MTKSDK.shared().setUserAttribute("gender", value: "female")
```

Obj-C:
```objc
  [[MTKSDK shared] setUserAttribute:@"gender" value:@"female"];
```
