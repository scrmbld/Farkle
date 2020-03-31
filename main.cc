//Write your last name and your partner's name here
//enter any command line parameter to run tests
#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "die.h"
#include "table.h"
using namespace std;

/*So Far:
	basic die class
	basic table class
	implemented gtests for die and table classes

 */
//TODO: add player class (be sure to make tests)
//TODO: make main game loop
//TODO: extend table class for main game loop if necessary


//WARNING: inserting new tests before the end WILL break successive tests if rand() is used

//die tests
TEST(dice_roll, good_tests) {
	Die d;
	d.roll();
	EXPECT_EQ(d.get_roll(), 3);
	d.roll();
	EXPECT_EQ(d.get_roll(), 6);
	EXPECT_EQ(d.get_roll(), 6);
}

TEST(dice_load, good_tests) {
	Die d({0.2, 0.1, 0.4, 0.1, 0.1, 0.1}, 6);
	vector<double> vec = {0.2, 0.1, 0.4, 0.1, 0.1, 0.1};
	EXPECT_EQ(d.get_weight(), vec);

	Die d2;
	
	EXPECT_NE(d.get_weight(), d2.get_weight());
	EXPECT_EQ(d.get_weight().size(), d.SIDES);
	EXPECT_EQ(d.get_weight().size(), d2.get_weight().size());

	Die d3({0.1, 0.1, 0.1, 0.1, 0.1, 0.5}, 6);
	int sixes = 0;
	int ones = 0;
	for (int i = 0; i < 1000; i++) {
		d3.roll();
		if (d3.get_roll() == 6) sixes++;
		else if (d3.get_roll() == 1) ones++;
	}

	cerr << "ones: " << ones << endl;
	cerr << "sixes: " << sixes << endl;

	EXPECT_NE(ones, 0); //there had better be at least one 1 in 1000 rolls
	EXPECT_GT(sixes, (ones * 2));
}

//table tests
TEST(table__constructors, fair_tests) {
	Table t;
	Die d;
	EXPECT_EQ(t.get_wager(), 0);
	EXPECT_EQ(t.get_points(), 0);
	EXPECT_EQ(t.get_dice().at(0).get_weight(), d.get_weight());

}

TEST(table_constructors, loaded_tests) {
	vector<double> w = {0.1, 0.1, 0.1, 0.2, 0.1, 0.4};
	vector<Die> dice;
	for (int i = 0; i < 6; i++) {
		dice.push_back(Die(w, 6));
	}

	Die d(w, 6);
	Table t(dice);
	EXPECT_EQ(t.get_wager(), 0);
	EXPECT_EQ(t.get_points(), 0);
	EXPECT_EQ(t.get_dice().at(3).get_weight(), d.get_weight());
}

TEST(table_wager, good_tests) {
	Table t;
	EXPECT_EQ(t.get_wager(), 0);
	t.set_wager(1);
	EXPECT_EQ(t.get_wager(), 1);
	t.set_wager(t.get_wager() + 7);
	EXPECT_EQ(t.get_wager(), 8);
}

TEST(table_points, good_tests) {
	Table t;
	EXPECT_EQ(t.get_points(), 0);
	t.set_points(3);
	EXPECT_EQ(t.get_points(), 3);
	t+=5;
	EXPECT_EQ(t.get_points(), 8);
}

TEST(table_roll, good_tests) {
	Table t;
	t.roll();
	
	EXPECT_EQ(t.get_roll(0), 3);
	EXPECT_EQ(t.get_roll(1), 3);
	EXPECT_EQ(t.get_roll(2), 3);
	EXPECT_EQ(t.get_roll(3), 1);
	EXPECT_EQ(t.get_roll(4), 6);
	EXPECT_EQ(t.get_roll(5), 6);
}

void turn(string p, Table t) {
	cout << p << "'s turn" << endl;

	//roll dice
	//select dice
	//roll again or bank points
	//return points?
}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	
	cout << "Hello World!\n";
	
	if (argc > 1) {
		srand(0);
		return RUN_ALL_TESTS();
	}
	srand(time(0));
	
	vector <string> gamers; //the players (switch to player class later)
	for (int i = 0; i < 3; i++) {
		gamers.push_back("player " + to_string(i));
	}
	Table t;
	
	int i = 0;
	while (true) {
		turn(gamers.at(i % gamers.size()), t);
		//break if someone has 2000 points
		i++;
		//placeholder base condition (need a player class!)
		if (i / gamers.size() > 3) break;
	}
}
