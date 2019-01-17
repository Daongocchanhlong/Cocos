#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Planes.h"
#include "ui/CocosGUI.h"


using namespace cocos2d;

Planes::~Planes()
{
	
}
Vec2 posT;
Planes::Planes()
{
	auto spritePlane = Sprite::create("spaceship.png");
	this->setSprite(spritePlane);
	this->setAlive(true);
	this->setPosXY(Director::getInstance()->getVisibleSize().width / 2, spritePlane->getContentSize().height);
	this->getSprite()->setScale(0.6);
	createBullet();

}
bool Planes::onTouchBegan(Touch* touch, Event *event) {
	posT.x = touch->getLocation().x;
	posT.y = touch->getLocation().y;
	//this->setPosXY(posT.x, posT.y);
	return true;
}
void Planes::onTouchMoved(Touch* touch, Event *event) {
	Vec2 nPosT;
	nPosT.x = touch->getLocation().x - posT.x;
	nPosT.y = touch->getLocation().y - posT.y;
	this->getSprite()->setPosition(Vec2(this->getSprite()->getPosition() + nPosT));
	posT.x = touch->getLocation().x;
	posT.y = touch->getLocation().y;
}
void Planes::onTouchEnded(Touch* touch, Event *event) {
}
void Planes::update()
{
	for (int i = 0; i < 49; i++)
	{
		this->mListBullet[i]->update(this->getSprite()->getPosition());
		if (this->mListBullet[i]->getSprite()->getPosition().y > this->getSprite()->getPosition().y + 50 )
		{
			this->mListBullet[i+1]->setAlive(true);
	       CCLOG("ok");
		}

		if (this->mListBullet[i]->getSprite()->getPosition().y > 750)
		{
			this->mListBullet[i]->setAlive(false);
			this->mListBullet[i]->getSprite()->setVisible(false);
			this->mListBullet[i]->setPosXY(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y);
		}
		if (mListBullet[19]->getAlive())
		{
			mListBullet[19]->setAlive(false);
			mListBullet[0]->setAlive(true);
		}
	}
}
void Planes::dirvePlane(Scene *sence)
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Planes::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Planes::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Planes::onTouchEnded, this);
	sence->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, sence);
}

void Planes::createBullet()
{
	for (int i = 0; i < 50; i++)
	{
		Bullet * bullet = new Bullet();
		bullet->getSprite()->setPosition(this->getSprite()->getPosition());
		this->mListBullet.push_back(bullet);
	}
	this->mListBullet[0]->setAlive(true);
}

vector<Bullet*> Planes::getListBullet()
{
	return this->mListBullet;
}
