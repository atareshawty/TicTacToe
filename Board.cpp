#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board(char playerSymbol1, char playerSymbol2) {
	this->playerSymbol1 = playerSymbol1;
	this->playerSymbol2 = playerSymbol2;
} 

void Board::printCurrentBoard() {
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			cout << "|" << this->spaces[i + k];
		}
		cout << "|" << endl;
		cout << "-------" << endl;
	}
}

void Board::placeMoveOnBoard(char playerSymbol, string playerName) {

}

bool Board::isWinner() {
	return this->isWinnerByColumns() ||
		   this->isWinnerByRows() ||
		   this->isWinnerByTopLeftToBottomRightDiagonal() ||
		   this->isWinnerByBottemLeftToTopRightDiagonal();
}

bool Board::isWinnerByColumns() {
	char symbolToCheckAgainst = this->spaces[0];
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			if (this->spaces[i + 3] != symbolToCheckAgainst) {
				return false;
			}
		}
	}
	return true;
}

bool Board::isWinnerByRows() {
	char symbolToCheckAgainst = this->spaces[0];
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			if (this->spaces[i + k] != symbolToCheckAgainst) {
				return false;
			}
		}
	}
	return true;
}

bool Board::isWinnerByTopLeftToBottomRightDiagonal() {
	return (this->spaces[0] == this->spaces[4]) && (this->spaces[4] == this->spaces[8]);
}

bool Board::isWinnerByBottemLeftToTopRightDiagonal() {
	return (this->spaces[6] == this->spaces[4]) && (this->spaces[4] == this->spaces[2]);
	return true;
}

void Board::getPlayerMove(string playerName) {
	do {
		cout << playerName << ", enter your move: ";
		cin >> this->spacePlayed;
		this->spacePlayed--;
	} while (!(0 <= spacePlayed && spacePlayed <= 8) ||
			 this->spaces[this->spacePlayed] == this->playerSymbol1 ||
			 this->spaces[this->spacePlayed] == this->playerSymbol2);
}

