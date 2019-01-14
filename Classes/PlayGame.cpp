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
#include "PlayGame.h"
#include <vector>

using namespace std;
using namespace cocos2d;


Scene* PlayGame::createScene()
{
	auto scene = PlayGame::create();
	auto layer = PlayGame::create();
	scene->addChild(layer);
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool PlayGame::init()
{
	if (!Scene::init())
	{	
		return false;
	}

	auto mainCharacter = Sprite::create("mainCharacter.png");
	mainCharacter->setPosition(Vec2(50, 50));
	this->addChild(mainCharacter);

	auto eventListen = EventListenerKeyboard::create();

	eventListen->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

		auto loc = event->getCurrentTarget()->getPosition();
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			event->getCurrentTarget()->setPosition(loc.x - 10, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			event->getCurrentTarget()->setPosition(loc.x + 10, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_SPACE:
		{
			auto spritecache = SpriteFrameCache::getInstance();
			spritecache->addSpriteFramesWithFile("luffymain.plist");
			Vector<SpriteFrame*> animFrames;
			char str[100];
			for (int i = 1; i < 44; i++)
			{
				sprintf(str, "luffytrans (%d).png", i);
				animFrames.pushBack(spritecache->getSpriteFrameByName(str));
			}
			auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 8);
			event->getCurrentTarget()->runAction(Animate::create(animation));
			break;
		}
		case EventKeyboard::KeyCode::KEY_C:
		{
			auto spritecache2 = SpriteFrameCache::getInstance();
			spritecache2->addSpriteFramesWithFile("luffymainHit.plist");
			Vector<SpriteFrame*> animFrames2;
			char str2[100];
			for (int i = 44; i < 51; i++)
			{
				sprintf(str2, "luffytrans (%d).png", i);
				animFrames2.pushBack(spritecache2->getSpriteFrameByName(str2));
			}
			auto animation2 = Animation::createWithSpriteFrames(animFrames2, 1.0f / 8);
			event->getCurrentTarget()->runAction(Animate::create(animation2));
			break;
		}
		case EventKeyboard::KeyCode::KEY_V:
		{
			auto spritecache2 = SpriteFrameCache::getInstance();
			spritecache2->addSpriteFramesWithFile("luffymainTele.plist");
			Vector<SpriteFrame*> animFrames2;
			char str2[100];
			for (int i = 51; i < 57; i++)
			{
				sprintf(str2, "luffytrans (%d).png", i);
				animFrames2.pushBack(spritecache2->getSpriteFrameByName(str2));
			}
			auto animation2 = Animation::createWithSpriteFrames(animFrames2, 1.0f / 8);
			event->getCurrentTarget()->setPosition(loc.x + 100, loc.y);
			event->getCurrentTarget()->runAction(Animate::create(animation2));
			//event->getCurrentTarget()->setPosition(loc.x + 100, loc.y);
			break;
		}
		}
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListen, mainCharacter);

	return true;
	
}

void PlayGame::menuCloseCallback(cocos2d::Ref * pSender)
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

void PlayGame::onTouchMenu(Ref * ref)
{
}
