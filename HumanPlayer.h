#ifndef HUMAN_PLAYER_H
#define	HUMAN_PLAYER_H

#include <string>

using namespace std;

class HumanPlayer {
	string playerName;
	char playerSymbol;

public:
	void setPlayerAttributes(int playerNumber);
	char getPlayerSymbol();
	string getPlayerName();
	void cleanStream();
};
#endif