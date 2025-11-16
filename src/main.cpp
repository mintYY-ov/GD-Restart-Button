#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		log::debug("fire in the hole!!!!!");

		auto restartButton = CCMenuItemSpriteExtra::create(
			CCSprite::create("restart.png"_spr),
			this,
			menu_selector(MyMenuLayer::onrestartButton)
		);

		auto menu = this->getChildByID("close-menu");
		menu->addChild(restartButton);

		restartButton->setID("restart-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onrestartButton(CCObject*) {
		game::restart();
	}
};
