#include <iostream>
#include <vector>
#include "die.h"
#include "table.h"
using std::cerr;

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
		dice.push_back(vec.at(i));
	}
}

int Table::get_wager() { return bet; }
int Table::get_points() { return pts; }
vector<Die> Table::get_dice() {
	cerr << "WARNING: Table::get_dice() is for debugging purposes only\n";
	return dice;
}

void Table::set_wager(int new_bet) { bet = new_bet; }
void Table::set_points(int new_pts) { pts = new_pts; }
void Table::operator+=(int new_pts) {
	this->pts += new_pts;
}
