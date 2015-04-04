#include "Board.h"
#include <iostream>
#include <string>

using namespace std;


void Board::printBoard() {
	for (int i = 0; i < 9; i++) {
		cout << "|" << this->spaces[i];
		if ((i + 1) % 3 == 0) {
			cout << "|" << endl;
			cout << "-------" << endl;
		}
	}
}

void Board::changeTile(int position, string character) {
	if (1 <= position && position <= 9) {
		this->spaces[position - 1] = character;
		this->fullTiles++;
	}
}

int Board::getFullTiles() {
	return this->fullTiles;
}