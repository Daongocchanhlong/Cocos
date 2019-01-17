#ifndef _PLANES_
#define _PLANES_
#include "cocos2d.h"
#include <vector>
#include "Object.h"
#include "Bullet.h"
using namespace std;
using namespace cocos2d;

class Planes : public FatherObject
{
public:
	Planes();
	~Planes();
	virtual void update();
	void dirvePlane(Scene *sence);
	void createBullet();
	vector<Bullet*> getListBullet();
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);

private:
	vector<Bullet*> mListBullet;
};

#endif // !_ROCK_
