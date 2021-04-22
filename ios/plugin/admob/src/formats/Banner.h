//
//  Banner.h
//  Banner
//
//  Created by Gustavo Maciel on 24/01/21.
//


#include "core/object.h"

#import <GoogleMobileAds/GADBannerView.h>
#import <GoogleMobileAds/GADExtras.h>
#import "app_delegate.h"
#import "view_controller.h"

@class Banner;

@interface Banner: NSObject <GADBannerViewDelegate> {
    GADBannerView *bannerView;
    bool initialized;
    int instanceId;
    int positionBanner;
    NSString *adUnitId;
    ViewController *rootController;
}

- (instancetype)init: (int) instance_id;
- (void)load_banner: (NSString*) ad_unit_id : (int) position : (NSString*) size;
- (void)destroy_banner;

@end
