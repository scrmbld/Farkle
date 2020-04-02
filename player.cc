#include <iostream>
#include "player.h"
#include "complex.h"
using namespace std;

Player::Player() {
	score = 0;
	money = 100;
}

void Player::AddScore(int add) {
	score = score + add;
}
void Player::SetScore(int new_score) {
	score = new_score;
}

void Player::AddMoney(int add) {
	money = money + add;
}
void Player::SetMoney(int new_money) {
	money = new_money;
}

int Player::GetScore() {
	return score;
}

int Player::GetMoney() {
	return money;
}
