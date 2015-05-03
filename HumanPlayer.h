#ifndef HUMAN_PLAYER_H
#define	HUMAN_PLAYER_H
#include <string>

using namespace std;

class HumanPlayer {
	char symbol;
	string name;
public:
	void setPlayerInfo(int x);
	char getSymbol();
	string getName();
};
#endif