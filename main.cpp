/*
Author: Alex Tareshawty
This program will be a two player tic tac toe game. For now, both players are human
*/

#include <iostream>
#include <string>
#include "Board.h"
#include "HumanPlayer.h"
using namespace std;

void cleanStream() {
	while (getchar() != '\n');
}

int main() {

	HumanPlayer *player1 = new HumanPlayer();
	HumanPlayer *player2 = new HumanPlayer();
	Board *board = new Board();

	player1->setPlayerInfo(1);
	cleanStream();
	player2->setPlayerInfo(2);
	cleanStream();

	cout << "This is the playing board, make your guesses according"
		 << " to the values" << endl;

	board->printBoard();
	board->setSymbols(player1->getSymbol(), player2->getSymbol());

	for (int i = 0; i < 9; i++) {
		if (i % 2 == 0) {
			if (board->move(player1->getSymbol(), player1->getName())) {
				cout << player1->getName() << " is the winner!" << endl;
				board->printBoard();
				return 0;
			}
		} else {
			if (board->move(player2->getSymbol(), player2->getName())) {
				cout << player2->getName() << " is the winner!" << endl;
				board->printBoard();
				return 0;
			}
		}
		board->printBoard();
	}

	cout << "Draw" << endl;
	return 0;
}