#pragma once
#include "Hero.h"

class SkilledHero : public Hero {
	// TODO
public:
	static int bladestormLevel;
	static int avatarlevel;
	void getSkill(name2Level& skillMap){
		skillMap["Bladestorm"] = bladestormLevel;
		skillMap["Avatar"] =avatarlevel;
		bladestormLevel = 0;
		avatarlevel = 0;
	}
};


int SkilledHero::avatarlevel = 0;
int SkilledHero::bladestormLevel = 0;