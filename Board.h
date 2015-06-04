#ifndef	BOARD_H
#define BOARD_H

#include <string>

using namespace std;

class Board {
	char spaces[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char playerSymbol1, playerSymbol2;
	int  spacePlayed;
	bool isWinnerByColumns();
	bool isWinnerByRows();
	bool isWinnerByTopLeftToBottomRightDiagonal();
	bool isWinnerByBottemLeftToTopRightDiagonal();
public:
	Board(char playerSymbol1, char playerSymbol2);
	void printCurrentBoard();
	void placeMoveOnBoard(char playerSymbol, string playerName);
	void getPlayerMove(string playerName);
	bool isWinner();
};

#endif