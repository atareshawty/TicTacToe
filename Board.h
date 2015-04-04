#ifndef	BOARD_H
#define BOARD_H


#include <string>

using namespace std;

class Board {
		string spaces[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
		int fullTiles = 0;
	public:
		void printBoard();
		void changeTile(int position, string character);
		int getFullTiles();
		bool isWon();
};

#endif