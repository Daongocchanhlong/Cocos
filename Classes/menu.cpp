#include "menu.h"
#include "SimpleAudioEngine.h"

cocos2d::Scene * menu::createScene()
{
	auto scene = menu::create();
	auto layer = menu::create();
	scene->addChild(layer);
	return scene;	
}

bool menu::init()
{
	return false;
}

void menu::menuCloseCallback(cocos2d::Ref * pSender)
{
}
