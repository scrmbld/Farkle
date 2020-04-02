#include <iostream>
#include "player.h"
#include "complex.h"
using namespace std;

Player::Player() : name("Player"){
	score = 0;
	money = 100;
}

Player::Player(string n) : name(n){
	score = 0;
	money = 100;
}

void Player::AddScore(int add) {
	score = score + add;
}

void Player::AddMoney(int add) {
	money = money + add;
}

int Player::GetScore() {
	return score;
}

int Player::GetMoney() {
	return money;
}

string Player::GetName() {
	return name;
}
