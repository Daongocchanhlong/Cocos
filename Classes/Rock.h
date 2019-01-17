#pragma once
#include "cocos2d.h"
#include "Model.h"
class Rock : public Model
{
public:
	Rock(cocos2d::Scene *scene);
	~Rock();

	virtual	void InIt();
	virtual	void Update();

	void SetStep(int step);
	int GetStep();

private:
	int mStep;
};

