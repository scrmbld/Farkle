#include <iostream>
#include <vector>
#include <algorithm>
#include "die.h"
#include "table.h"
using std::cerr;

//constructors
Table::Table() {
	bet = 0;
	pts = 0;
	for (int i = 0; i < 6; i++) {
		dice.push_back(Die()); //pushes back a normal, fair die
	}
}

Table::Table(vector<Die> vec) {
	bet = 0;
	pts = 0;
	dice.clear();
	dice.resize(0);
	for (int i = 0; i < 6; i++) {
		dice.push_back(Die(vec.at(i).get_weight(), vec.at(i).SIDES));
	}
}

//meant to be run between every turn, unsaves every die and sets pts to 0
void Table::clear() {
	for (Die &d : dice) {
		d.unsave();
	}
	pts = 0;
	bet = 0;
}


//for debugging/gtests purposes only
vector<Die> Table::get_dice() {
	cerr << "WARNING: Table::get_dice() is for debugging purposes only\n";
	return dice;
}

//score related functions
int Table::get_wager() const { return bet; }
int Table::get_points() const { return pts; }
void Table::set_wager(int new_bet) { bet = new_bet; }
void Table::set_points(int new_pts) { pts = new_pts; }
void Table::operator+=(int new_pts) {//adds to the point total
	this->pts += new_pts;
}



//roll related functions
void Table::roll() {
	for (Die &d : dice) {
		if (!d.is_saved()) d.roll();
	}
}

bool Table::all_saved() const {
	for (const Die &d : dice) {
		if (!d.is_saved()) return false;
	}
	return true;
}

int Table::get_roll(int i) const { return dice.at(i).get_roll(); }
vector<int> Table::get_rolls() const {
	vector<int> retval;
	for (const Die &d : dice) {
		if (!d.is_saved()) retval.push_back(d.get_roll());
	}
	return retval;
}
int Table::save_roll(int i) {
	if (!dice.at(i).is_saved()) {
		dice.at(i).save();
		return dice.at(i).get_roll();
	}
	return 0;
}
void Table::print_rolls() const {
	for (int i = 0; i < 6; i++) {
		if (!dice.at(i).is_saved()) cout << "Die " << i << ": " << dice.at(i).get_roll() << endl;
	}
}
