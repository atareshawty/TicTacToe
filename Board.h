#ifndef	BOARD_H
#define BOARD_H

#include <string>

using namespace std;

class Board {
	char spaces[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char playerSymbol1, playerSymbol2;
	bool isWinnerByColumns();
	bool isWinnerByRows();
	bool isWinnerByTopLeftToBottomRightDiagonal();
	bool isWinnerByBottemLeftToTopRightDiagonal();
public:
	Board();
	Board(char playerSymbol1, char playerSymbol2);
	void printCurrentBoard();
	void placeMoveOnBoard(char playerSymbol, int spaceLocation);
	bool isWinner();
	bool isSpaceAlreadyPlayed(int spaceLocation);
};

#endif