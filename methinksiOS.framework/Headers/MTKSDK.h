//
//  MTThinkerSDK.h
//  thinkerSDK-iOS
//
//  Created by Philip Yun on 11/10/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@interface MTKSDK : NSObject

//! Project version number for methinkiOS.
FOUNDATION_EXPORT double methinkiOSVersionNumber;

//! Project version string for methinkiOS.
FOUNDATION_EXPORT const unsigned char methinkiOSVersionString[];


/*
 shared instance using singleton.
 */
+ (instancetype)shared;

/*
 The designated initializer. Autotracking option will track current visible viewController.
 If we want to track and log UIView, set setAvtiveScreen method.
 Set autoCrashReport to make methinks-iOS SDK collection crash log.
 */
- (void)initializeWithClientKey:(nonnull NSString*)clientKey
                     productKey:(nonnull NSString*)productKey
                   autoTracking:(BOOL) autoTracking;

/*
 Set your userId for further custom tracking or custom in-app survey/live intercept. The userId should be unique per user.
 */
- (void)setUserId:(nonnull NSString *)userId;

/*
 Set your user attributes. Use this attributes for further advanced targeting.
 */
- (void)setUserAttribute:(nonnull NSString*) key
                   value:(nonnull id) value;

/*
 Can set custom time interval to confirm end of session since user finishes app session. Default is 10 seconds.
 */
- (void) setNewSessionInterval:(NSInteger) interval;

/*
 If setDebugMode, various log messages MTKSDK-IOS is tracking will be logged in debug console. Setting this won't be affective in production app.
 */
- (void) setDebugMode:(BOOL) setDebugMode;

/*
Set your custom event from the app to trigger custom event such as showing in-app surveys or live interivew interception. 
*/
- (void)logEvent:(nonnull NSString*)eventName;

/*
Set default survey view so that you will only show in-app survey when users are in this viewController.
Pass viewController in target viewController's viewDidLoad call.
If not set, survey will be showing when user starts app and about 3~5 seconds later.
*/
- (void) setDefaultSurveyViewController:(nonnull UIViewController*) defaultViewController;


/*
Exclude this view controller from autoTracking, this may distort "staying" time on previous view controller
 */
-(void) disableViewTracking;


/*
 Set custom name of the current view controller. This method must be call after the view controller is fully loaded and visible.
 Best to call before any touch event happens on current view controller. Great place to call this method is on viewDidLoad:
 */
-(void) setViewController:(UIViewController*) viewController withCustomTitle:(nonnull NSString*) title;



/*
If you  want to track multiple UIView in a viewController and like to track views instead of the viewController,
use this method to track user journey. Perform when the target view is moved to superview.
View Controller with this setting may not be tracked. No other view is tracked until same method called again on other views,
or move to different viewController.
 */

-(void) setCustomTrackingViewTitle:(nonnull NSString*) title;

/*
(Live Intercept for screen recording & User Journey analysis only)
If a specific screen contains sensitive personal information, you can set isSensitive, so the screen snapshow and recording will be skipped.
During screen recording, user will see the recoridng paused due to sensitive information. It's best to include this function on viewWillAppear:animated method.
 */

-(void) setIsSensitiveScreen;



/*
Call this method when you want to show User's experience in your app and lead to App Store Review if needed.
Be aware that Apple App Store review prompt will only be displayed to a user a maximum of three times within a 365-day period, so show App Store Review is not guranteed.
In Dashboard,you can set the scale of user score to decide to show App Store review prompt or not.

 */
-(void) showAppStoreReviewPrompt;


/*
Test in-app survey prompt in multiple choice format.
The test survey will only show in DEBUG mode and won't have any effect on Production build.
The answer will not be processed on the server side. The test survey can be skipped by tapping outside of the screen.
 */

-(void) testSurveyPrompt;


@end

NS_ASSUME_NONNULL_END
