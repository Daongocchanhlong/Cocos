/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/


#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "MenuGame.h"
#include <vector>

using namespace std;
using namespace cocos2d;


Scene* MenuGame::createScene()
{
	auto scene = MenuGame::create();
	auto layer = MenuGame::create();
	scene->addChild(layer);
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool MenuGame::init()
{
	if (!Scene::init())
	{	
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//add background menu
	auto backgroundMenu = Sprite::create("backgroundMenu.png");
	backgroundMenu->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	backgroundMenu->setContentSize(visibleSize);
	this->addChild(backgroundMenu);
	//create menu
	auto itemPlay = MenuItemFont::create("Play", nullptr);
	itemPlay->setColor(Color3B::RED);
	auto itemSetting = MenuItemFont::create("Setting", nullptr);
	itemSetting->setColor(Color3B::RED);
	auto itemMoreGame = MenuItemFont::create("More Game", nullptr);
	itemMoreGame->setColor(Color3B::RED);
	auto itemAbout = MenuItemFont::create("About", nullptr);
	itemAbout->setColor(Color3B::RED);
	auto itemQuit = MenuItemFont::create("Quit", nullptr);
	itemQuit->setColor(Color3B::RED);
	/*itemPlay->setPosition(400, 300);
	itemSetting->setPosition(400, 250);
	itemMoreGame->setPosition(400, 200);
	itemAbout->setPosition(400, 150);*/
	auto menuLabel = Menu::create(itemPlay, itemSetting, itemMoreGame,itemAbout,itemQuit, nullptr);
	menuLabel->alignItemsVerticallyWithPadding(10);
	menuLabel->setPosition(visibleSize.width/2 - 70, visibleSize.height/2 +50);
	addChild(menuLabel);

	//add animation
	/*SpriteFrameCache::getInstance()->addSpriteFramesWithFile("hero/luf.plist");
	auto mySprite = Sprite::create("hero/luf (1).png");
	mySprite->setPosition(Vec2(visibleSize.width /2, visibleSize.height / 2));
	mySprite->setContentSize(visibleSize/8);
	this->addChild(mySprite);

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(18);
	for (int i = 1; i < 19; i++)
	{
		char name[100] = { 0 };
		sprintf(name, "hero/luf (%d).png", i);
		animFrames.pushBack(SpriteFrame::create(name, Rect(0, 0, 100, 100)));
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	mySprite->runAction(RepeatForever::create(animate));*/
	
	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("luf.plist");
	Vector<SpriteFrame*> animFrames;
	char str[100];
	for (int i = 1; i < 19; i++)
	{
		sprintf(str, "luf (%d).png", i);
		CCLOG(str);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}
	auto sprite = Sprite::createWithSpriteFrameName("luf (1).png");
	addChild(sprite);
	sprite->setPosition(Vec2(visibleSize.width / 2 + 75, visibleSize.height / 2 + 75));
	auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 8);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));
	
}

void MenuGame::menuCloseCallback(cocos2d::Ref * pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);

}

void MenuGame::onTouchMenu(Ref * ref)
{
}
