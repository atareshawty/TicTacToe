/*
@author Alex Tareshawty

Two player tic-tac-toe game on 3x3 grid. Both players are human.
*/

#include <iostream>
#include "Board.h"
#include "HumanPlayer.h"
using namespace std;

//To get rid of pesky new line characters
void cleanStream() {
	while (getchar() != '\n');
}

int main() {

	string name;
	char symbol;
	

	//Get info for player1 and player2
	cout << "Player 1, what is your name? ";
	getline(cin, name);
	cout << "What character do you want to place on the board? ";
	symbol = getchar();
	cleanStream();
	HumanPlayer player1 (name, symbol);

	cout << "Player 2, what is your name? ";
	getline(cin, name);
	cout << "What character do you want to place on the board? ";
	symbol = getchar();
	cleanStream();
	HumanPlayer player2 (name, symbol);

	//Create board from constructor
	Board board (player1.getSymbol(), player2.getSymbol());

	//Explanation to user
	cout << "This is the playing board, make your guesses according"
		 << " to the values" << endl;

	board.printBoard();

	/*
	9 turns moves in a game
	Board.move will return return true if there is a winner
	false otherwise. If board.move returns winner, both loop
	and program will terminate. If loop makes 9 iterations
	without a winner, there is a draw.
	*/
	for (int i = 0; i < 9; i++) {
		if (i % 2 == 0) {
			if (board.move(player1.getSymbol(), player1.getName())) {
				cout << player1.getName() << " is the winner!" << endl;
				board.printBoard();
				return 0;
			}
		} else {
			if (board.move(player2.getSymbol(), player2.getName())) {
				cout << player2.getName() << " is the winner!" << endl;
				board.printBoard();
				return 0;
			}
		}
		board.printBoard();
		cleanStream();
	}

	cout << "Draw" << endl;
	return 0;
}