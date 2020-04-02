#pragma once
#include <iostream>
#include "player.h"
using namespace std;

class Player {
	private:
		int score;
		int money;
		const string name;
	public:
		Player();
		Player(string);
		void AddScore(int add);
		void AddMoney(int add);
		int GetScore();
		int GetMoney();
		string GetName();
};
