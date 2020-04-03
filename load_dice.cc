#include <iostream>
#include "die.h"
#include "load_dice.h"

vector<Die> load_dice() {
	vector<Die> revtal;
	revtal.push_back(Die({0.44,0.11,0.11,0.11,0.12,0.11}, 6, "Biased"));
	revtal.push_back(Die({0.1,0.3,0.1,0.2,0.1,0.2}, 6, "Even"));
	revtal.push_back(Die({0.3,0.1,0.2,0.1,0.2,0.1}, 6, "Odd"));
	revtal.push_back(Die({0.05,0.20,0.25,0.20,0.05,0.25}, 6, "Rigged"));
	revtal.push_back(Die({0.1,0.1,0.1,0.1,0.5,0.1}, 6, "Fives"));
	revtal.push_back(Die({1.0,0.0,0.0,0.0,0.0,0.0}, 6, "GG"));
	revtal.push_back(Die());
	
	return revtal;
}
