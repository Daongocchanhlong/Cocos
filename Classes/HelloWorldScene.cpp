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

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//load background
	auto background = Sprite::create("background.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->setContentSize(visibleSize);
	this->addChild(background);
	//load name's game
	auto lableNameGame = Label::createWithTTF("GUN X GUN", "fonts/Marker Felt.ttf", 50);
	lableNameGame->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	lableNameGame->enableShadow();
	lableNameGame->enableOutline(Color4B::RED,3);
	this->addChild(lableNameGame);
	//load version's game
	auto lableVersionGame = Label::createWithTTF("VER 1.0.0.0", "fonts/Marker Felt.ttf", 15);
	lableVersionGame->setAnchorPoint(Vec2(0,1));
	lableVersionGame->enableOutline(Color4B::RED, 1);
	lableVersionGame->setPosition(Vec2(5, visibleSize.height));
	this->addChild(lableVersionGame);
	//load date's game released
	auto lableDateGame = Label::createWithTTF("11/01/2019", "fonts/Marker Felt.ttf", 15);
	lableDateGame->setAnchorPoint(Vec2(1, 1));
	lableDateGame->enableOutline(Color4B::RED, 1);
	lableDateGame->setPosition(Vec2(visibleSize.width - 5, visibleSize.height));
	this->addChild(lableDateGame);
	//set effect lablenamegame
	auto fadeIn = FadeIn::create(1.0f);
	auto fadeOut = FadeOut::create(2.0f);
	auto sequenceFadeNameGame = Sequence::create(fadeIn, fadeOut, nullptr);
	auto repeatsequenceFadeNameGame = Repeat::create(sequenceFadeNameGame,10);
	lableNameGame->runAction(repeatsequenceFadeNameGame);
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
	auto sequenceloadingbar = Sequence::create(updateLoadingBar,DelayTime::create(0.01),nullptr);
	auto repeat = Repeat::create(sequenceloadingbar, 100);
	loadingBar->runAction(repeat);
	
	//replace to MenuGame


    return true;
}

void HelloWorld::onTouchMenu(Ref *ref) 
{
	
}

void HelloWorld::menuCloseCallback(Ref* pSender)
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
