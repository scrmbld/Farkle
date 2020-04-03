//by allen
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
		
		void clear();

		//getters
		int get_wager() const;
		int get_points() const;
		vector<Die> get_dice(); //for gtests, do not use for any other purpose
		
		//setters
		void set_wager(int);
		void set_points(int);

		//operators
		void operator+=(int new_pts);

		//functions for rolling
		bool all_saved() const;
		void roll();

		int get_roll(int) const;
		vector<int> get_rolls() const;
		void print_rolls() const;
		int save_roll(int);

		
};
