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
	int getPosY();
	int getPosX();
	void setPosXY( int posX, int posY);
	Sprite* getSprite();
	void setSprite(Sprite * sprite);

private:
	Sprite * sprite;
	int posX;
	int posY;
};
#endif // !_ROCK_
