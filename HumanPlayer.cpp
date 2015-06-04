#include "HumanPlayer.h"
#include <iostream>
#include <string>

using namespace std;

void HumanPlayer::setPlayerAttributes(int playerNumber) {
	cout << "Player " << playerNumber << ", what is your name? ";
	cin >> this->playerName;
	this->cleanStream();

	cout << "Player " << playerNumber << ", what symbol do you wish to place on the board? ";
	cin >> this->playerSymbol;
	this->cleanStream();
}

char HumanPlayer::getPlayerSymbol() {
	return this->playerSymbol;
}

string HumanPlayer::getPlayerName() {
	return this->playerName;
}

void HumanPlayer::cleanStream() {
	while (getchar() != '\n');
}