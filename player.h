//Player class by Thompson
#pragma once
#include <iostream>
#include "player.h"
using namespace std;

class Player {
	private:
		int score;
		int money;
		const string name;//except the name system, by allen
	public:
		Player();
		Player(string);
		void AddScore(int add);
		void AddMoney(int add);
		int GetScore();
		int GetMoney();
		string GetName();
};
