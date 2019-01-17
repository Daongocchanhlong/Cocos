#include "Model.h"



Model::Model()
{
}


Model::~Model()
{
}

cocos2d::Sprite * Model::GetSprite()
{
	return this->mSprite;
}

void Model::SetSprite(cocos2d::Sprite * sprite)
{
	this->mSprite = sprite;
}

void Model::SetAlive(bool alive)
{
	this->mIsAlive = alive;
	this->GetSprite()->setVisible(alive);
}

bool Model::IsAlive()
{
	return this->mIsAlive;
}

cocos2d::Vec2 Model::GetPosition()
{
	return this->GetSprite()->getPosition();
}

void Model::SetPosition(cocos2d::Vec2 pos)
{
	this->GetSprite()->setPosition(pos);
}


