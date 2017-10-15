#ifndef GAME
#define GAME

#include "Orc.h"
#include "Troll.h"
struct Game {
	//creates orc and troll objects fromclasses
	Orc orc;
	Troll troll;
	//character pointers to allow user to play either side
	Character* player = &orc;
	Character* npc = &troll;
	int input;//takes input for user in multiple instances
	bool gameSelect;//allows user to select to play as trolls or orcs

	//default stats for new trolls and orcs
	static const int ORC_START_HEALTH = 500;
	static const int ORC_START_STRENGTH = 18;
	static const int TROLL_START_HEALTH = 400;
	static const int TROLL_START_STRENGTH = 25;

	void	setUp();
	void	run();
	void	gameLoop();//runs actual game play
	void	guideBook();//gives user all the moves and thier affects
};
#endif // !GAME