#pragma once
#include <iostream>
#include "die.h"

class Table{
	private:
		int bet = 0;//the current wager
		int pts = 0;//the current score
		vector<Die> dice;//the dice
	
	public:
		//constructors
		Table();
		Table(vector<Die>);
		
		//getters
		int get_wager();
		int get_points();
		vector<Die> get_dice(); //for gtests
		
		//setters
		void set_wager(int);
		void set_points(int);

		//operators
		void operator+=(int new_pts);
};
