#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

// Variables to store your hack states
bool g_noclip = false;

class $modify(MyPlayer, PlayerObject) {
    void pushButton(PlayerButton btn) {
        PlayerObject::pushButton(btn);
        
        // This runs every time you tap!
        if (g_noclip) {
            log::info("Noclip is active!");
        }
    }
};

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Create a toggle button on the main menu
        auto sprite = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
        auto btn = CCMenuItemSpriteExtra::create(
            sprite, this, menu_selector(MyMenuLayer::onToggle)
        );

        auto menu = this->getChildByID("bottom-menu");
        if (menu) {
            menu->addChild(btn);
            menu->updateLayout();
        }

        return true;
    }

    void onToggle(CCObject* sender) {
        g_noclip = !g_noclip;
        auto msg = g_noclip ? "Noclip ON" : "Noclip OFF";
        Notification::create(msg, NotificationIcon::Info)->show();
    }
};

