#ifndef	GAME_H
#define GAME_H

#include <string>
#include "Board.h"
#include "HumanPlayer.h"

using namespace std;

class Game {
	HumanPlayer player1;
	HumanPlayer player2;
	Board playingBoard;
	int turn;
public:

	Game(HumanPlayer player1, HumanPlayer player2, Board playingBoard);
	void startGame();
	bool isGameOver();
	int getMoveFromPlayer(HumanPlayer player);
	void cleanStream();
};

#endif