#include "Clock.h"
#include "CCPointExtension.h"

Clock::Clock(void)
{
}

Clock::~Clock(void)
{
}

Clock* Clock::clock()
{
	Clock *clock = new Clock;

	if (clock && clock->init())
	{
		clock->autorelease();
		return clock;
	}

	return NULL;
}

bool Clock::init()
{
	bool bRet = false;
	do{
		sprite = CCSprite::spriteWithSpriteFrameName("clock.png");
		sprite->setPosition(ccp(0, 50));
		addChild(sprite);
		owner = NULL;
		timeLife = 5;
		scheduleUpdate();

		bRet=true;
	}while(0);

	return bRet;
}

void Clock::kill()
{
	owner->setClock(NULL);
	removeFromParentAndCleanup(true);
}

void Clock::update(ccTime dt)
{
	timeLife -= dt;
	if (owner)
	{
		setPosition(owner->getPosition());
	}
	if (timeLife < 0)
	{
		kill();
	}
}