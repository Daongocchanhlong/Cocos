#pragma once
#include "cocos2d.h"
#include "Model.h"
class SpaceShip : public Model
{
public:
	SpaceShip(cocos2d::Scene *scene);
	~SpaceShip();

	virtual	void InIt();
	virtual	void Update();


private:

};

