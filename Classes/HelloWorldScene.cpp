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

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "MenuGame.h"
#include "cocos2d.h"
#include <string>
 
using namespace cocos2d;


Scene* HelloWorld::createScene()
{
	auto scene = HelloWorld::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
	// first init
    if ( !Scene::init() )
    {
        return false;
    }	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	//load background
	HelloWorld::loadBackground("background.png", visibleSize.width / 2, visibleSize.height /2);
	
	//load name's game
	auto nameGame = HelloWorld::loadLable("X GUN X", 50, visibleSize.width / 2, visibleSize.height / 2);
	
	//set effect lablenamegame
	auto fadeIn = FadeIn::create(1.0f);
	auto fadeOut = FadeOut::create(2.0f);
	auto sequenceFadeNameGame = Sequence::create(fadeIn, fadeOut, nullptr);
	auto repeatsequenceFadeNameGame = Repeat::create(sequenceFadeNameGame, 10);
	nameGame->runAction(repeatsequenceFadeNameGame);
	
	//load version's game
	auto verGame = HelloWorld::loadLable("VER 1.0.0.0", 15, 5, visibleSize.height);
	verGame->setAnchorPoint(Vec2(0, 1));
	
	//load date's game released
	auto dateGame = HelloWorld::loadLable("14/01/2019", 15, visibleSize.width-5, visibleSize.height);
	dateGame->setAnchorPoint(Vec2(1, 1));
	
	//loading game
	HelloWorld::loadGame();
    
	return true;
}

void HelloWorld::loadBackground(std::string nameBackground, int posX, int posY)
{
	auto background = Sprite::create(nameBackground);
	background->setPosition(Vec2(posX,posY));
	background->setContentSize(Director::getInstance()->getVisibleSize());
	this->addChild(background);
}

void HelloWorld::createSprite(std::string nameSprite, int posX, int posY)
{
	auto sprite = Sprite::create(nameSprite);
	sprite->setPosition(Vec2(posX, posY));
	this->addChild(sprite);
}

Label* HelloWorld::loadLable(std::string text, int font, int posX, int posY)
{
	auto lable = Label::createWithTTF(text, "fonts/Marker Felt.ttf", font);
	lable->setPosition(Vec2(posX,posY));
	lable->enableShadow();
	lable->enableOutline(Color4B::RED, 3);
	this->addChild(lable);
	return lable;
}

void HelloWorld::loadGame()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	//loading barbg
	auto loadingbarBg = Sprite::create("loadingbar_bg.png");
	loadingbarBg->setPosition(visibleSize.width / 2, 20);
	this->addChild(loadingbarBg);
	
	//loading bar
	auto loadingBar = ui::LoadingBar::create("loadingbar.png");
	loadingBar->setDirection(ui::LoadingBar::Direction::LEFT);
	loadingBar->setPosition(Vec2(visibleSize.width / 2, 20));
	loadingBar->setPercent(0);
	this->addChild(loadingBar);
	
	//create func loading bar
	auto updateLoadingBar = CallFunc::create([=]() {
		if (loadingBar->getPercent() < 100)
		{
			loadingBar->setPercent(loadingBar->getPercent() + 1);
		}
		if (loadingBar->getPercent() >= 100)
		{
			Director::getInstance()->replaceScene(MenuGame::createScene());
		}
	});
	
	//create sequence loadingbar
	auto sequenceloadingbar = Sequence::create(updateLoadingBar, DelayTime::create(0.01), nullptr);
	auto repeat = Repeat::create(sequenceloadingbar, 100);
	loadingBar->runAction(repeat);
}
