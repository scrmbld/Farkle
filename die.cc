#include "die.h"
#include <cassert>
using namespace std;

Die::Die() : SIDES(6), last_roll(0) {
	for (unsigned int i = 0; i < SIDES; i++)
		weight.push_back(1.0/SIDES);
}


Die::Die(vector<double> new_weights, const int new_sides) : SIDES(new_sides), last_roll(0) {
	assert(new_sides >= 4);
	assert(new_weights.size() == SIDES);
	double sum = 0;
	for (unsigned int i = 0; i < SIDES; i++) {
		assert(new_weights[i] >= 0 && new_weights[i] <= 1);
		sum += new_weights[i];
		weight.push_back(new_weights[i]);
	}

	assert(sum > .99 && sum < 1.01);
}


int Die::get_roll() const {
	assert(last_roll >= 1 && last_roll <= SIDES);
	return last_roll;
}

void Die::roll() {
	double rl = rand() % 1000;
	rl /= 1000.0;
	for (int i = 0; i < weight.size(); i++) {
		rl -= weight.at(i);
		if (rl <= 0) {
			last_roll = i + 1;
			return;
		}
	}

	last_roll = SIDES; //if the for loop doesn't get it then the roll must be the highest possible value
}

void Die::save() { saved = true; }
void Die::unsave() { saved = false; }
bool Die::is_saved() const { return saved; }


vector<double> Die::get_weight() const{
		return weight;
}

