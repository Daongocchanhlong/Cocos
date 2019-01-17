#include "Model.h"
#include "Bullet.h"
#include "Defines.h"
#include "cocos2d.h"

Bullet::Bullet(cocos2d::Scene * scene) : Model()
{
	auto spriteRock = cocos2d::Sprite::create(IMG_BULLET);
	this->SetSprite(spriteRock);
	scene->addChild(spriteRock);
	auto step = cocos2d::random(ROCK_MIN_STEP, ROCK_MAX_STEP);
	this->SetStep(step);
	this->SetAlive(false);
}

Bullet::~Bullet()
{
}

void Bullet::InIt()
{
	auto posX = cocos2d::random(this->GetSprite()->getContentSize().width / 2, SCREEN_W - this->GetSprite()->getContentSize().width / 2);
	auto posY =SCREEN_H + this->GetSprite()->getContentSize().height / 2 ;
	this->SetPosition(cocos2d::Vec2(100,100));
}

void Bullet::Update()
{
	if (!this->IsAlive())
	{
		this->SetAlive(true);
		this->SetPosition(this->GetPosition() + cocos2d::Vec2(0, this->GetStep()));
	}
	else
	{
		this->SetPosition(this->GetPosition() + cocos2d::Vec2(0, this->GetStep()));
	}
}

void Bullet::SetStep(int step)
{
	this->mStep = step;
}

int Bullet::GetStep()
{
	return this->mStep;
}
