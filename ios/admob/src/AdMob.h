#ifndef ADMOB_H
    #define ADMOB_H
    #include "object.h"

    #ifdef __OBJC__
        #include "Banner.h"
        #include "Interstitial.h"
        #include "Rewarded.h"

        @class Banner;
        @class Interstitial;
        @class Rewarded;
        
        typedef Banner *banner;
        typedef Interstitial *interstitial;
        typedef Rewarded *rewarded;
    #else
        typedef void *banner;
        typedef void *interstitial;
        typedef void *rewarded;
    #endif

    class AdMob : public Object {
        GDCLASS(AdMob, Object);
        
        bool initialized;
        String self_max_ad_content_rating;
        static AdMob *instance;
        Object *objectDB;

        banner bannerObj;
        interstitial interstitialObj;
        rewarded rewardedObj;

    protected:
        static void _bind_methods();

    public:
        void initialize(bool is_for_child_directed_treatment, const String &max_ad_content_rating, bool is_real, bool is_test_europe_user_consent, int instance_id);
        void load_banner(const String &ad_unit_id, int gravity, const String &size);
        void hide_banner();
        void show_banner();
        void destroy_banner();
        void load_interstitial(const String &ad_unit_id);
        void show_interstitial();
        void load_rewarded(const String &ad_unit_id);
        void show_rewarded();

        AdMob();
        ~AdMob();
    private: 
        const char* getDeviceId();
        void initializeAfterUMP(bool is_for_child_directed_treatment, bool is_real, int instance_id);
        void loadConsentForm(bool is_for_child_directed_treatment, bool is_real, int instance_id);

    };

#endif
