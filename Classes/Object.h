#ifndef _OBJECT_
#define _OBJECT_
#include "cocos2d.h"
#include <vector>

using namespace std;
using namespace cocos2d;

class FatherObject
{
public:
	FatherObject();
	virtual ~FatherObject();
	void setPosXY(float posX, float posY);
	Sprite* getSprite();
	void setSprite(Sprite * sprite);
	void setAlive(bool alive);
	bool getAlive();
private:
	Sprite *mSprite;
	bool mAlive;
};
#endif // !_ROCK_
