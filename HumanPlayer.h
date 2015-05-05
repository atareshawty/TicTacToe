#ifndef HUMAN_PLAYER_H
#define	HUMAN_PLAYER_H
#include <string>

using namespace std;

class HumanPlayer {
	//Character a player can place on the board
	char symbol;

	//Name of player for game personalization
	string name;
public:

	/*
	Constructor
	@param name
			Name associated with each player
	@param symbol
			Character the player can place on the board 
	*/
	HumanPlayer(string name, char symbol);
	
	/*
	Get player's symbol
	@return getSymbol
			 symbol
	*/
	char getSymbol();
	
	/*
	Get player's name
	@return getName
			 name
	*/
	string getName();
};
#endif