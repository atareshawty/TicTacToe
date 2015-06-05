#include "Game.h"
#include "Board.h"
#include "HumanPlayer.h"
#include <iostream>
#include <string>

using namespace std;



Game::Game(HumanPlayer player1, HumanPlayer player2, Board playingBoard) {
	this->player1 = player1;
	this->player2 = player2;
	this->playingBoard = playingBoard;
	this->turn = 1;
} 

void Game::startGame() {
	while(!isGameOver()) {
		playingBoard.printCurrentBoard();
		int playerMovePosition;
		if (turn % 2 != 0) {
			playerMovePosition = getMoveFromPlayer(player1);
			playingBoard.placeMoveOnBoard(player1.getPlayerSymbol(), playerMovePosition);
		}
		else {
			playerMovePosition = getMoveFromPlayer(player2);
			playingBoard.placeMoveOnBoard(player2.getPlayerSymbol(), playerMovePosition);
		}
		turn++;
	}

	playingBoard.printCurrentBoard();

	if (turn % 2 == 0 && turn < 10) 
		cout << "Congrats, " << player1.getPlayerName() << "! You won :D" << endl;
	else if (turn < 10)
		cout << "Congrats, " << player1.getPlayerName() << "! You won :D" << endl;		
}

bool Game::isGameOver() {
	return playingBoard.isWinner() || turn > 9;
}

int Game::getMoveFromPlayer(HumanPlayer player) {
	int playedSpacePosition;

	do {
		cout << player.getPlayerName() << ", what tile do you wish to play? ";
		cin >> playedSpacePosition;
		playedSpacePosition--;
		cleanStream();

	} while (!(0 <= playedSpacePosition && 
		     playedSpacePosition <= 8 && 
		     !playingBoard.isSpaceAlreadyPlayed(playedSpacePosition)));
	return playedSpacePosition;
}

void Game::cleanStream() {
	while (getchar() != '\n');
}