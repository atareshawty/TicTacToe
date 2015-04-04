#ifndef	PLAYER_H
#define	PLAYER_H
#include <string>

using namespace std;

class Player {
		int turn, positionGuess;
		string character;
		string name;
		void setPositionGuess(int x);
		void setCharacter(string x);
		void setTurn(int x);
		void setName(string x);
	public:
		void setPlayerInfo();
		void setPlayerGuess();
		int getPositionGuess();
		string getCharacter();
		int getTurn();
		string getName();
};
#endif