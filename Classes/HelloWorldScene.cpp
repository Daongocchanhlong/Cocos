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
#include <vector>
#include "Rock.h"
#include "Planes.h"
#include <time.h>
#include "Bullet.h"
#include <windows.h>

using namespace std;
using namespace cocos2d;

Scene* HelloWorld::createScene()
{
	/*auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);*/
	return HelloWorld::create();
}


// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
vector<Rock*> listRock;
int i = 0;
Planes *spaceShip;
bool HelloWorld::init()
{
	srand(time(NULL));

    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
	
	for (int  i = 0; i < 10; i++)
	{
		Rock * rock = new Rock();
		listRock.push_back(rock);
		addChild(rock->getSprite());
	}
	listRock[0]->setAlive(true);
	// drive plane
	spaceShip = new Planes();
	for (auto  bullet: spaceShip->getListBullet() )
	{
		addChild(bullet->getSprite());
		bullet->getSprite()->setVisible(false);
	}
	this->addChild(spaceShip->getSprite());
	spaceShip->dirvePlane(this);



	scheduleUpdate();
	return true;
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

void HelloWorld::update(float delta)
{
	for (int j = 0; j < 9; j++)
	{
		listRock[j]->update(1);
		if (listRock[j]->getSprite()->getPosition().y == 550)
		{
			listRock[j+1]->setAlive(true);
		}
		if (listRock[9]->getAlive())
		{
			listRock[9]->setAlive(false);
			listRock[0]->setAlive(true);
		}
	}
	spaceShip->update();

}



