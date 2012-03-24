#pragma once

#include "Thing.h"
#include "CCAction.h"

using namespace cocos2d;

class Character :
	public Thing
{
public:
	Character(void);
	~Character(void);

	virtual bool init() = 0;

	CCFiniteTimeAction* makeAction(CCPoint from, CCPoint target);
	void changeDirection(CCNode *node, void *param);
	int speed;
	CCFiniteTimeAction* actionWalks[8];
	CCFiniteTimeAction* actionWalk;
};
