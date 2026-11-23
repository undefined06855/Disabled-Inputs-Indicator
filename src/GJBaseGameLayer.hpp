#include <Geode/modify/GJBaseGameLayer.hpp>

class $modify(HookedGJBaseGameLayer, GJBaseGameLayer) {
    struct Fields {
        geode::Ref<cocos2d::CCSprite> p1Sprite;
        geode::Ref<cocos2d::CCSprite> p2Sprite;
    };

    bool init();
    void update(float dt);
};
