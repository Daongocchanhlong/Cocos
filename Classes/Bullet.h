#pragma once
#include "cocos2d.h"
#include "Model.h"
class Bullet : public Model
{
public:
	Bullet(cocos2d::Scene *scene);
	~Bullet();

	virtual	void InIt();
	virtual	void Update();

	void SetStep(int step);
	int GetStep();

private:
	int mStep;
};

