#include "Rock.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

Rock::Rock()
{
	auto sprite = Sprite::create("rock.png");
	this->setSprite(sprite);
	int randX = rand() % 401 + 50;
	this->setPosXY(randX + sprite->getContentSize().width, 750);

}

Rock::~Rock()
{
}

void Rock::fall()
{
	auto move = MoveTo::create(3, Vec2(this->getSprite()->getPosition().x, -50));
	auto rotate = RotateBy::create(0.5, 360);
	auto resetPosition = CallFunc::create([=]() {
		int randX = rand() % 401 + 50;
		this->setPosXY(randX + this->getSprite()->getContentSize().width , 750);
	});
	auto repeat = Repeat::create(rotate,10);
	auto spawn = Spawn::create(move, repeat, nullptr);
	auto sequenceFall = Sequence::create(spawn, DelayTime::create(1),resetPosition, nullptr);
	this->getSprite()->runAction(sequenceFall);

}

