#include "HumanPlayer.h"
#include <iostream>
#include <string>

using namespace std;

void HumanPlayer::setPlayerInfo(int x) {
	string name;
	char symbol;
	
	cout << "Player " << x << ", what is your name? ";
	getline(cin, name);
	cout << "What symbol do you wish to use on the board? ";
	symbol = getchar();
	cout << endl;

	this->name = name;
	this->symbol = symbol;
	this->turn = x;
}

char HumanPlayer::getSymbol() {
	return symbol;
}

string HumanPlayer::getName() {
	return name;
}
