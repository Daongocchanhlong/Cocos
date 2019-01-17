#include "Rock.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

Rock::Rock()
{
	auto sprite = Sprite::create("rock.png");
	this->setSprite(sprite);
	this->setAlive(false);
	float randX = rand() % 461 + 20;
	this->setPosXY(randX, 750);
}

Rock::~Rock()
{
}

void Rock::update(float delta)
{
	if (this->getAlive())
	{
	float x = this->getSprite()->getPosition().x;
	float y = this->getSprite()->getPosition().y;
	this->setPosXY(x, y -5);
	if (y < -50)
	{
		this->setAlive(false);
		int rand = random(10, 490);
		this->setPosXY(rand, 750);
	}
	}
	
}

void Rock::fall()
{
}
