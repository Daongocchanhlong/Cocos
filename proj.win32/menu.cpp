#include "menu.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

using namespace cocos2d;
USING_NS_CC;
Scene * menu::createScene()
{
	auto scene = menu::create();
	auto layer = menu::create();
	scene->addChild(layer);
	return scene;	
}

bool menu::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(HelloWorld::createScene());
	}); 
	auto sequence = Sequence::create(DelayTime::create(1), gotoNext,
		nullptr);
	runAction(sequence);


	return true;
}

void menu::menuCloseCallback(cocos2d::Ref * pSender)
{
}
