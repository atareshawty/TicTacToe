#include <iostream>
#include "Board.h"
#include "HumanPlayer.h"
#include "Game.h"
using namespace std;

int main() {

	HumanPlayer player1, player2;

	player1.setPlayerAttributes(1);
	player2.setPlayerAttributes(2);

	Board playingBoard(player1.getPlayerSymbol(), player2.getPlayerSymbol()); 

	Game game(player1, player2, playingBoard);

	game.startGame();

	return 0;
}