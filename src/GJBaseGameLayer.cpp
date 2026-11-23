#include "GJBaseGameLayer.hpp"

// TODO: different styles? (e.g. vignette)
// TODO: max z-order option (put in uilayer and convert pos to world space)
// TODO: scale based on player size as an option?

bool HookedGJBaseGameLayer::init() {
    if (!GJBaseGameLayer::init()) return false;

    auto fields = m_fields.self();
    fields->p1Sprite = cocos2d::CCSprite::createWithSpriteFrameName("particle_193_001.png");
    fields->p2Sprite = cocos2d::CCSprite::createWithSpriteFrameName("particle_193_001.png");

    fields->p1Sprite->setVisible(false);
    fields->p1Sprite->setZOrder(60);
    fields->p2Sprite->setVisible(false);
    fields->p2Sprite->setZOrder(60);

    fields->p1Sprite->setID("player-1"_spr);
    fields->p2Sprite->setID("player-2"_spr);

    this->runAction(geode::cocos::CallFuncExt::create([this] {
        auto fields = m_fields.self();
        m_objectLayer->addChild(fields->p1Sprite);
        m_objectLayer->addChild(fields->p2Sprite);
    }));

    return true;
}

void HookedGJBaseGameLayer::update(float dt) {
    GJBaseGameLayer::update(dt);
    auto fields = m_fields.self();

    fields->p1Sprite->setVisible(m_player1->m_controlsDisabled);
    fields->p1Sprite->setPosition(m_player1->getPosition());
    fields->p2Sprite->setVisible(m_player2->m_controlsDisabled);
    fields->p2Sprite->setPosition(m_player2->getPosition());
}
