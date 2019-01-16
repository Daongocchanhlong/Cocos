#ifndef _ROCK_
#define _ROCK_
#include "cocos2d.h"
#include <vector>
#include "Object.h"
using namespace std;
using namespace cocos2d;
class Rock  : public FatherObject
{
public:
	Rock();
	~Rock();
	void fall();

	
private:
	
};

#endif // !_ROCK_
