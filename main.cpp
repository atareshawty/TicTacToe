/*
@author Alex Tareshawty

Two player tic-tac-toe game on 3x3 grid. Both players are human.
*/

#include <iostream>
#include "Board.h"
#include "HumanPlayer.h"
using namespace std;

void cleanStream() {
	while (getchar() != '\n');
}

int main() {

	//Create two players and fresh playing board
	HumanPlayer *player1 = new HumanPlayer();
	HumanPlayer *player2 = new HumanPlayer();
	Board *board = new Board();

	//Get info for player1 and player2
	player1->setPlayerInfo(1);
	cleanStream();
	player2->setPlayerInfo(2);
	cleanStream();

	//Explanation to user
	cout << "This is the playing board, make your guesses according"
		 << " to the values" << endl;

	board->printBoard();

	//Add user symbols to board for winner checking
	board->setSymbols(player1->getSymbol(), player2->getSymbol());

	/*
		9 turns moves in a game
		Board.move will return return true if there is a winner
		false otherwise. If board.move returns winner, both loop
		and program will terminate. If loop makes 9 iterations
		without a winner, there is a draw.
	*/
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
		cleanStream();
	}

	cout << "Draw" << endl;
	return 0;
}