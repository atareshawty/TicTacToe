#ifndef HUMAN_PLAYER_H
#define	HUMAN_PLAYER_H
#include <string>

using namespace std;

class HumanPlayer {
	//Character a player can place on the board
	char symbol;

	//Name of player for game personalization
	string name;

	//Indicates which turn player is (1 or 2)
	int turn;
public:

	void setPlayerInfo(int x);
	char getSymbol();
	string getName();
};
#endif