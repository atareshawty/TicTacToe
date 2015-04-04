/*
Author: Alex Tareshawty
This program will be a two player tic tac toe game. For now, both users are be human
*/

#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
using namespace std;

void cleanInput() {
	while (getchar() != '\n');
}

int main() {

	Board playingBoard = new Board();
	Player player1 = new Player(), player2 = new Player();
	int fullTiles = playingBoard.getFullTiles();
	bool gameOver = false;

	cout << "Welcome to Tic-Tac-Toe!\n";
	cout << "Before we start playing, I need some information about the two players\n";
	cout << endl;
	player1.getPlayerInfo();
	player2.getPlayerInfo();
	cout << "Great! Thank you\nHere is your playing board:\n";
	playingBoard.printBoard();

	while (fullTiles < 9 && !gameOver) {
		if (fullTiles % 2 == 0) {
			player1.getPlayerGuess();
			playingBoard.changeTile(player1.getPositionGuess(), 
									player1.getCharacter());
		} else {
			player2.getPlayerGuess();
			playingBoard.changeTile(player2.getPositionGuess(), 
									player2.getCharacter());
		}
		fullTiles = playingBoard.getFullTiles();
		playingBoard.printBoard();
	}

	return 0;
}