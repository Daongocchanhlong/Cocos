#pragma once
#include "cocos2d.h"
class Model
{
public:
	Model();
	~Model();

	virtual	void InIt() = 0;
	virtual	void Update() = 0;

	cocos2d::Sprite* GetSprite();
	void SetSprite(cocos2d::Sprite* sprite);

	void SetAlive(bool alive);
	bool IsAlive();

	cocos2d::Vec2 GetPosition();
	void SetPosition(cocos2d::Vec2 pos);

private:
	cocos2d::Sprite* mSprite;
	bool mIsAlive;
};

