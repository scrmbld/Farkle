#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
using std::vector;
using std::cout;
using std::endl;

//TODO: add weight system for loaded dice
class Die {
	bool saved;
	vector<double> weight;
	unsigned int last_roll;
	public:
	const unsigned int SIDES = 0;
	
	Die(); //Create a fair die
	Die(vector<double> new_weights, int new_sides); //Create a cheater die
	int get_roll() const; //Return the last value rolled
	void roll(); //Set the die to a random value
	void save();
	void unsave();
	bool is_saved() const;

	vector<double> get_weight() const;
	
};
