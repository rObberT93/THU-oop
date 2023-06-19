#pragma once
#include "SkilledHero.h"

class BladestormHero : public SkilledHero {
	// TODO
public:
	BladestormHero(Hero* h) {
		bladestormLevel ++;
	}
};