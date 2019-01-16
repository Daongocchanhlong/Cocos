#include "cocos2d.h"
#include "Object.h"

using namespace cocos2d;


FatherObject::FatherObject()
{
	

}

FatherObject::~FatherObject()
{
	//delete sprite;
}

int FatherObject::getPosY()
{
	return this->posY;
}

int FatherObject::getPosX()
{
	return this->posX;
}

void FatherObject::setPosXY(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
	this->sprite->setPosition(Vec2(posX , posY));
}

Sprite * FatherObject::getSprite()
{
	return this->sprite;
}

void FatherObject::setSprite(Sprite * sprite)
{
	this->sprite = sprite;
}
