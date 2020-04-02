//Write your last name and your partner's name here
//enter any command line parameter to run tests
#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "die.h"
#include "table.h"
#include "player.h"
using namespace std;

/*So Far:
  basic die class
  basic table class
  implemented gtests for die and table classes

*/
//TODO: add player class (be sure to make tests)
//TODO: make main game loop
//TODO: extend table class for main game loop if necessary
//TODO: make sure the hand_points function follows the game rules

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

TEST(player_points, good_tests) {
	Player p;
	EXPECT_EQ(p.GetScore(), 0);
	p.AddScore(30);
	EXPECT_EQ(p.GetScore(), 30);
	p.AddScore(30);
	EXPECT_EQ(p.GetScore(), 60);
	p.SetScore(30);
	EXPECT_EQ(p.GetScore(), 30);
}

TEST(player_money, good_tests) {
	Player p;
	EXPECT_EQ(p.GetMoney(), 100);
	p.AddMoney(20);
	EXPECT_EQ(p.GetMoney(), 120);
	p.SetMoney(20);
	EXPECT_EQ(p.GetMoney(), 20);

}


int hand_points(vector<int> vec) {
	int score = 0;
	vector<int> counter(6);
	for (int i : vec) {
		counter.at(i - 1)++;
	}

	for (int i = 0; i < 6; i++) {
		if (counter.at(i) >= 3) {
			if (i == 0) {//if we roll a one
				score += 1000 * (counter.at(i) - 2);
				continue;

			} else score += 100 * (i + 1) * (counter.at(i) - 2);
		}
	}

	if (counter.at(0) < 3) {//count ones (three of a kinds handled elsewhere)
		score += 100 * counter.at(0);
	} 
	if (counter.at(4) < 3) {//count fives
		score += 50 * counter.at(4);
	}

	return score;
}

//tests for functions in main:
TEST(point_calc, good_tests) {
	//no three of a kinds
	EXPECT_EQ(hand_points({1, 5}), 150);
	EXPECT_EQ(hand_points({1, 2, 3, 4, 5, 6}), 150);
	EXPECT_EQ(hand_points({1, 3, 4, 5, 6, 6}), 150);

	//three of a kinds
	EXPECT_EQ(hand_points({1, 1, 1}), 1000);
	EXPECT_EQ(hand_points({1, 1, 1, 5}), 1050);
	EXPECT_EQ(hand_points({3, 3, 3}), 300);
	EXPECT_EQ(hand_points({1, 3, 3, 3}), 400);
	EXPECT_EQ(hand_points({3, 3, 3, 6, 6, 6}), 900);

	//four of a kinds
	EXPECT_EQ(hand_points({3, 3, 6, 6, 6, 6}), 1200);
	EXPECT_EQ(hand_points({1, 1, 1, 1}), 2000);
	EXPECT_EQ(hand_points({1, 1, 1, 1, 5, 5}), 2100);
}

void turn(string &p, Table &t) {
	cout << p << "'s turn" << endl;
	t.set_points(0);


	while (true) {
		//roll the dice
		t.roll();

		//print the rolls
		for (int i = 0; i < 6; i++) {
			cout << "Die " << i << ": " << t.get_roll(i) << endl;
		}
		//select dice
		vector<int> saved_rolls;
		cout << "which dice do you want to keep? (-1 to quit)\n";
		while (true) {
			int choice = 0;
			cin >> choice;
			if (choice == -1) break;
			else cout << "Keeping die " << choice << ": " << t.get_roll(choice) << endl;
			saved_rolls.push_back(t.get_roll(choice));
		}

		t += hand_points(saved_rolls);
		cout << "current points: " << t.get_points() << endl;
		//roll again or bank points
		while (true) {
			cout << "Do you want to roll again? (y/n)" << endl;
			string s;
			cin >> s;
			if (s == "n" || s == "N") {
				//add points to player
				return;
			}
			else if (s == "y" || s == "Y") {
				break;
			}
		}
	}
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
	Player p;

	int i = 0;
	while (true) {
		turn(gamers.at(i % gamers.size()), t);
		//break if someone has 2000 points
		i++;
		//placeholder base condition (need a player class!)
		if (i / gamers.size() > 3) break;
	}
}
