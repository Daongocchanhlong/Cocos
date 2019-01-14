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
#include "PlayGame.h"

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
	MenuGame::loadBackground("backgroundMenu.png", visibleSize.width / 2, visibleSize.height / 2);
	
	//create menu
	MenuGame::loadMenu();

	//add animation	
	MenuGame::loadAnimation("luf.plist", "luf (%d).png", 19);
	
	return true;
}

void MenuGame::menuCloseCallback(cocos2d::Ref * pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();
}

void MenuGame::loadBackground(std::string nameBackground, int posX, int posY)
{
	auto background = Sprite::create(nameBackground);
	background->setPosition(Vec2(posX, posY));
	background->setContentSize(Director::getInstance()->getVisibleSize());
	this->addChild(background);
}

void MenuGame::loadMenu()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto itemPlay = MenuItemFont::create("Play", nullptr);
	itemPlay->setColor(Color3B::RED);
	itemPlay->setCallback(CC_CALLBACK_1(MenuGame::onTouchMenu, this));
	auto itemSetting = MenuItemFont::create("Setting", nullptr);
	itemSetting->setColor(Color3B::RED);
	auto itemMoreGame = MenuItemFont::create("More Game", nullptr);
	itemMoreGame->setColor(Color3B::RED);
	auto itemAbout = MenuItemFont::create("About", nullptr);
	itemAbout->setColor(Color3B::RED);
	auto itemQuit = MenuItemFont::create("Quit", nullptr);
	itemQuit->setColor(Color3B::RED);
	itemQuit->setCallback(CC_CALLBACK_1(MenuGame::menuCloseCallback, this));
	auto menuLabel = Menu::create(itemPlay, itemSetting, itemMoreGame, itemAbout, itemQuit, nullptr);
	menuLabel->alignItemsVerticallyWithPadding(10);
	menuLabel->setPosition(visibleSize.width / 2 - 70, visibleSize.height / 2 + 50);
	addChild(menuLabel);

}

void MenuGame::loadAnimation(std::string namePlist, const char * namePng, int CountImage)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//add plist
	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile(namePlist);
	Vector<SpriteFrame*> animFrames;
	char str[100];
	for (int i = 1; i < CountImage; i++)
	{
		sprintf(str, namePng, i);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}
	//create fist sprite
	auto sprite = Sprite::createWithSpriteFrame(animFrames.front());
	addChild(sprite);
	//run action animation
	sprite->setPosition(Vec2(visibleSize.width / 2 + 75, visibleSize.height / 2 + 75));
	auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 8);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));
}

void MenuGame::onTouchMenu(Ref * ref)
{
	Director::getInstance()->replaceScene(PlayGame::createScene());
}
