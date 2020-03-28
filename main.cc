//Write your last name and your partner's name here
//enter any command line parameter to run tests
#include <iostream>
#include <gtest/gtest.h>
#include "die.h"
#include "table.h"
using namespace std;

//TODO: add player class & tests


//die tests
TEST(dice_roll, good_tests) {
	Die d;
	d.roll();
	EXPECT_EQ(d.get_roll(), 2);
	d.roll();
	EXPECT_EQ(d.get_roll(), 5);
	EXPECT_EQ(d.get_roll(), 5);
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
	int sum = 0;
	for (int i = 0; i < 1000; i++) {
		d3.roll();
		sum += d3.get_roll();
	}

	 double avg = sum / 1000.0;
	 //cerr << avg << endl;

	EXPECT_GT(avg, 3.0);
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


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	
	cout << "Hello World!\n";
	
	if (argc > 1) {
		srand(0);
		return RUN_ALL_TESTS();
	}
	srand(time(0));

	//testing dice
	cout << "dice:\n";
	Die d({.5,.1,.1,.1,.1,.1},6);
	Die d2;
	d.roll();
	d2.roll();
	cout << d.get_roll() << endl;
	cout << d2.get_roll() << endl;

	//testing table
	cout << "table:\n";
	Table t;
	cout << t.get_wager() << endl;
	cout << t.get_points() << endl;
}
