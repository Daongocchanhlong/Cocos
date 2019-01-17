#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Planes.h"
#include "ui/CocosGUI.h"
#include "Bullet.h"

using namespace cocos2d;

Bullet::Bullet()
{
	auto spriteBullet = Sprite::create("bullet.png");
	this->setSprite(spriteBullet);
	this->setAlive(false);
}

Bullet::~Bullet()
{
}

void Bullet::update(Vec2 posBullet)
{
	if (!this->getAlive())
	{
		this->getSprite()->setVisible(true);
		this->setPosXY(posBullet.x, posBullet.y);
		float x = this->getSprite()->getPosition().x;
		float y = this->getSprite()->getPosition().y;
		this->setPosXY(x, y + 5);
	}
	if (this->getAlive())
	{
		float x = this->getSprite()->getPosition().x;
		float y = this->getSprite()->getPosition().y;
		this->setPosXY(x, y + 5);
	}
}
