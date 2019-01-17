#ifndef _BULLET_
#define _BULLET_
#include "cocos2d.h"
#include "Object.h"

using namespace std;
using namespace cocos2d;

class Bullet : public FatherObject
{
public:
	Bullet ();
	~Bullet ();
	virtual void update(Vec2 posBullet);

private:

};

#endif // !_ROCK_
