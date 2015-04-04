#include "Player.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void Player::setPositionGuess(int x) {
	positionGuess = x;
}

void Player::setCharacter(string x) {
	character = x;
}

void Player::setTurn(int x) {
	turn = x;
}

void Player::setName(string x) {
	name = x;
}

int Player::getPositionGuess() {
	return positionGuess;
}

string Player::getCharacter() {
	return character;
}

int Player::getTurn() {
	return turn;
}

string Player::getName() {
	return name;
}

void Player::setPlayerInfo() {
	
	string name, character;
	cout << "Player " << this->getTurn() << ", what is your name? ";
	cin.ignore();
	getline(cin, name);
	cout << "What character to you wish to use on the board? ";
	cin.ignore();
	getline(cin, character);
	cout << endl;

	this->setName(name);
	this->setCharacter(character);		
}

void Player::setPlayerGuess() {

	int positionGuess;

	cout << "It is " << this->getName(); 
	cout <<"'s turn. Which tile do you with to place a ";
	cout << this->getCharacter() << " on? ";
	cin >> positionGuess;

	this->setPositionGuess(positionGuess);
}
