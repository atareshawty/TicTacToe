#include "HumanPlayer.h"
#include <iostream>
#include <string>

using namespace std;

HumanPlayer::HumanPlayer(string name, char symbol) {
	this->name = name;
	this->symbol = symbol;
}

char HumanPlayer::getSymbol() {
	return symbol;
}

string HumanPlayer::getName() {
	return name;
}
