/*
@author Alex Tareshawty

Two player tic-tac-toe game on 3x3 grid. Both players are human.
*/

#include <iostream>
#include "Board.h"
#include "HumanPlayer.h"
using namespace std;

int main() {

	Board *playingBoard;
	HumanPlayer player1, player2;

	player1.setPlayerAttributes(1);
	player2.setPlayerAttributes(2);

	playingBoard = new Board(player1.getPlayerSymbol(), player2.getPlayerSymbol()); 



	return 0;
}