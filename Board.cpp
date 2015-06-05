#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board(char playerSymbol1, char playerSymbol2) {
	this->playerSymbol1 = playerSymbol1;
	this->playerSymbol2 = playerSymbol2;
} 

Board::Board() {
	playerSymbol1 = 'X';
	playerSymbol2 = 'O';
}

void Board::printCurrentBoard() {
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			cout << "|" << spaces[(3 * i) + k];
		}
		cout << "|" << endl;
		cout << "-------" << endl;
	}
}

void Board::placeMoveOnBoard(char playerSymbol, int spaceLocation) {
	spaces[spaceLocation] = playerSymbol;
}

bool Board::isSpaceAlreadyPlayed(int spaceLocation) {
	return this->spaces[spaceLocation] == this->playerSymbol1 || 
		   this->spaces[spaceLocation] == this->playerSymbol2;
}

bool Board::isWinner() {
	return isWinnerByColumns() ||
		   isWinnerByRows() ||
		   isWinnerByTopLeftToBottomRightDiagonal() ||
		   isWinnerByBottemLeftToTopRightDiagonal();
}

bool Board::isWinnerByColumns() {
	char symbolToCheckAgainst;
	int numberOfLikeSpacesInColumn;
	bool isWinnerByColumns = false;
	for (int topOfColumn = 0; topOfColumn < 3; topOfColumn++) {
		symbolToCheckAgainst = spaces[topOfColumn];
		numberOfLikeSpacesInColumn = 1;
		for (int rowMult = 1; rowMult < 3; rowMult++) {
			if (symbolToCheckAgainst == spaces[topOfColumn + (rowMult * 3)])
				numberOfLikeSpacesInColumn++;
		}
		if (numberOfLikeSpacesInColumn == 3) {
			isWinnerByColumns = true;
		}
	}
	return isWinnerByColumns;
}

bool Board::isWinnerByRows() {
	char symbolToCheckAgainst;
	int numberOfLikeSpacesInRow;
	bool isWinnerByRows = false;
	for (int row = 0; row < 3; row++) {
		symbolToCheckAgainst = spaces[3 * row];
		numberOfLikeSpacesInRow = 1;
		for (int column = 1; column < 3; column++) {
			if (symbolToCheckAgainst == spaces[(3 * row) + column]) 
				numberOfLikeSpacesInRow++;
		}
		if (numberOfLikeSpacesInRow == 3)
			isWinnerByRows = true;
	}
	return isWinnerByRows;
}

bool Board::isWinnerByTopLeftToBottomRightDiagonal() {
	return (this->spaces[0] == this->spaces[4]) && (this->spaces[4] == this->spaces[8]);
}

bool Board::isWinnerByBottemLeftToTopRightDiagonal() {
	return (this->spaces[6] == this->spaces[4]) && (this->spaces[4] == this->spaces[2]);
}
