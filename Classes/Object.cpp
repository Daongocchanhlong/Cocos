#include "cocos2d.h"
#include "Object.h"

using namespace cocos2d;


FatherObject::FatherObject()
{
}

FatherObject::~FatherObject()
{

}


void FatherObject::setPosXY(float posX, float posY)
{
	this->mSprite->setPosition(Vec2(posX , posY));
}

Sprite * FatherObject::getSprite()
{
	return this->mSprite;
}

void FatherObject::setSprite(Sprite * sprite)
{
	this->mSprite = sprite;
}

void FatherObject::setAlive(bool alive)
{
	this->mAlive = alive;
}

bool FatherObject::getAlive()
{
	return this->mAlive;
}
