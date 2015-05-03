#ifndef	BOARD_H
#define BOARD_H


#include <string>

using namespace std;

class Board {
	char spaces[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
	char symbol1, symbol2;
public:
	//Prints playing board with updated symbols
	void printBoard();

	/*
	Updates board with new move. Will prompt for repeated input
	until the input is invalid.

	@param symbol
			symbol to add on board
	@param name
			name of player making move
	@return move
			true iff the move creates a winner
			false iff the move doesn't create a winner
	*/
	bool move(char symbol, string name);

	/*
	Sets the two symbols that will be placed on the board

	@param symbol1
			1st symbol to be added
	@param symbol2
			2nd symbol to be added
	*/
	void setSymbols(char symbol1, char symbol2);
};

#endif