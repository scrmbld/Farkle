#pragma once
#include <iostream>
#include "player.h"
using namespace std;

class Player {
	private:
		int score;
		int money;

	public:
		Player();
		void AddScore(int add);
		void AddMoney(int add);
		void SetScore(int new_score);
		void SetMoney(int new_score);
		int GetScore();
		int GetMoney();
};
