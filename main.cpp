/*
Author: Alex Tareshawty
This program will be a two player tic tac toe game. For now, both users will be human
*/

#include <iostream>
#include <string>
using namespace std;

//Board represents the playing board, a nine by nine grid with 
//either spaces, X's, or O's
class Board {
		string spaces[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
		int fullTiles = 0;
	public:
		void printBoard() {
			for (int i = 0; i < 9; i++) {
				cout << "|" << spaces[i];
				if ((i + 1) % 3 == 0) {
					cout << "|" << endl;
					cout << "-------" << endl;
				}
			}
		}
		void changeTile(int position, string character) {
			if (1 <= position && position <= 9) {
				spaces[position - 1] = character;
				fullTiles++;
			}
		}
		int getFullTiles() {return fullTiles;}
} board;

//Players have a turn, and a mark 
class Player {
		int turn, positionGuess;
		string character;
		string name;

	public:

		void setPositionGuess(int x) {
			positionGuess = x;
		}
		void setCharacter(string x) {
			character = x;
		}
		void setTurn(int x) {
			turn = x;
		}
		void setName(string x) {
			name = x;
		}
		int getPositionGuess() {
			return positionGuess;
		}
		string getCharacter() {
			return character;
		}
		int getTurn() {
			return turn;
		}
		string getName() {
			return name;
		}



} player;

Player* createPlayer(int turn) {

	Player *player = new Player();
	player->setTurn(turn);

	return player;
}

void cleanInput() {
	while (getchar() != '\n');
}

void getPlayerInfo(Player *player) {
	
	string name, character;
	cout << "Player " << player->getTurn() << ", what is your name? ";
	getline(cin, name);
	cout << "What character to you wish to use on the board? ";
	getline(cin, character);
	cout << endl;

	player->setName(name);
	player->setCharacter(character);		
}

void getPlayerGuess(Player *player) {

	int positionGuess;
	cout << "It is " << player->getName(); 
	cout <<"'s turn. Which tile do you with to place a ";
	cout << player->getCharacter() << " on? ";

	cin  >> positionGuess;
	player->setPositionGuess(positionGuess);
}

int main() {

	Board playingBoard;
	Player *player1 = createPlayer(1);
	Player *player2 = createPlayer(2);
	int fullTiles = playingBoard.getFullTiles();

	cout << "Welcome to Tic-Tac-Toe!\n";
	cout << "Before we start playing, I need some information about the two players\n";
	cout << endl;
	getPlayerInfo(player1);
	getPlayerInfo(player2);
	cout << "Great! Thank you\nHere is your playing board:\n";
	playingBoard.printBoard();

	while (fullTiles < 9) {
		if (fullTiles % 2 == 0) {
			getPlayerGuess(player1);
			playingBoard.changeTile(player1->getPositionGuess(), 
									player1->getCharacter());
		} else {
			getPlayerGuess(player2);
			playingBoard.changeTile(player2->getPositionGuess(), 
									player2->getCharacter());
		}
		fullTiles = playingBoard.getFullTiles();
		playingBoard.printBoard();
	}





	free (player1);
	free (player2);

	return 0;
}