#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

void Board::printBoard() {
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			cout << "|" << this->spaces[i][k];
		}
		cout << "|" << endl;
		cout << "-------" << endl;
	}
}

void Board::setSymbols(char symbol1, char symbol2) {
	this->symbol1 = symbol1;
	this->symbol2 = symbol2;
} 

bool Board::move(char symbol, string name) {
	int n = 3, row = 0, col = 0, position = 0;

	//Get input until it becomes valid
	do {
		cout << name << ", enter your move: ";
		cin >> position;
		position--;
		switch (position) {
			case 0:	row = 0;
					col = 0;
					break;
			case 1:	row = 0;
					col = 1;
					break;
			case 2: row = 0;
					col = 2;
					break;
			case 3:	row = 1;
					col = 0;
					break;
			case 4:	row = 1;
					col = 1;
					break;
			case 5:	row = 1;
					col = 2;
					break;
			case 6: row = 2;
					col = 0;
					break;
			case 7:	row = 2;
					col = 1;
					break;
			default:
					row = 2;
					col = 2;
					break;
		}

	} while (!(0 <= position &&
			 position <= 8) ||
			 this->spaces[row][col] == this->symbol1 ||
			 this->spaces[row][col] == this->symbol2);

	//Place move on board
	this->spaces[row][col] = symbol;

	//Check column winner
	for  (int i = 0; i < n; i++) {
		if (spaces[i][col] != symbol) {
			break;
		} else if (i == n - 1) {
			return true;
		}
	}

	//Check if row winner
	for (int i = 0; i < n; i++) {
		if (spaces[row][i] != symbol) {
			break;
		} else if (i == n - 1) {
			return true;
		}
	}

	//Check for diagonal winner
	for (int i = 0; i < n; i++) {
		if (spaces[i][i] != symbol) {
			break;
		} else if (i == n - 1) {
			return true;
		}	
	}

	//Check opposite diagonal
	for (int i = 0; i < n; i++) {
		if (spaces[i][2 - i] != symbol) {
			break;
		} else if (i == n - 1) {
			return true;
		}
	}

	//If it hasn't returned true, we don't have a winner
	return false;
}