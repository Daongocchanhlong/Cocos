#include "Model.h"
#include "Bullet.h"
#include "Defines.h"
#include "cocos2d.h"
#include "SpaceShip.h"
#include "cocos2d.h"
#include "Defines.h"

SpaceShip::SpaceShip(cocos2d::Scene * scene)
{
	auto spriteRock = cocos2d::Sprite::create(IMG_BULLET);
	this->SetSprite(spriteRock);
	scene->addChild(spriteRock);
	this->SetAlive(true);

	
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::InIt()
{
	this->SetPosition(cocos2d::Vec2(SCREEN_W / 2, this->GetSprite()->getContentSize().height));
}
