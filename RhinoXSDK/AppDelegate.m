//
//  AppDelegate.m
//  RhinoXSDK
//
//  Created by daidai on 2020/7/8.
//  Copyright © 2020 daidia. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    if (self.window == nil) {
        UIWindow *keyWindow = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
        keyWindow.backgroundColor = UIColor.whiteColor;
        self.window = keyWindow;
        self.window.rootViewController = [[ViewController alloc] init];
        [self.window makeKeyAndVisible];
    }
    
    return YES;
}

@end
