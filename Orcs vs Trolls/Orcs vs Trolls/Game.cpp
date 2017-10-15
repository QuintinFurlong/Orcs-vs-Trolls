/// <summary>
/// @author Quintin Furlong
/// date: 2/10/17
/// ORCS VS TROLLS: BATTLE FOR EVIL POWER
/// </summary>


#include <iostream>
#include "Game.h"
#include <time.h>

using namespace std;

int main(void)
{
	Game daGame;
	daGame.setUp();
	daGame.run();
}

//sets starting values for both sides 
void Game::setUp()
{
	orc.recieveHealth(ORC_START_HEALTH);
	orc.recieveStrength(ORC_START_STRENGTH);
	orc.unGaurd();
	orc.gatherArmy(5);
	troll.recieveHealth(TROLL_START_HEALTH);
	troll.recieveStrength(TROLL_START_STRENGTH);
	troll.unGaurd();
	troll.gatherArmy(5);
	input = 0;
}

void Game::run()
{
	//seed for randomnise
	srand(static_cast<int>(time(NULL)));
	cout << "How do you want to play?\n0:As orcs vs trolls \n1:As trolls vs orcs" << endl;
	cin >> gameSelect;
	
	cout << "Do want to read the guide book first\n0:Yes\n1:No" << endl;
	cin >> input;
	if (!input)
	{
		guideBook();
	}
	//swaps pointers around if user chooses the other side to default
	if (gameSelect)
	{
		player = &troll;
		npc = &orc;
	}
	system("cls");
	//loops as long as both sides has soilders
	while (troll.getArmySize() > 0 && orc.getArmySize() > 0)
	{
		//loops as long as both current soilders have health
		while (troll.getHealth() > 0 && orc.getHealth() > 0)
		{
			gameLoop();
		}
		system("cls");
		//displays both sides current soilders
		cout << "Orc has " << orc.getHealth() << " health     trolls have " << troll.getHealth() << " health" << endl;
		system("pause");
		//true if enemy is dead
		if (npc->getHealth() <= 0)
		{
			player->lootDrop();
			player->shop();
		}
		//true if current troll loses all health 
		if (troll.getHealth() <= 0)
		{
			troll.recieveHealth(TROLL_START_HEALTH);//resets the trolls values
			troll.recieveStrength(TROLL_START_STRENGTH);
			troll.unGaurd();
		}
		else//true if current orc loses all health 
		{
			orc.recieveHealth(ORC_START_HEALTH);//resets the trolls values
			orc.recieveStrength(ORC_START_STRENGTH);
			orc.unGaurd();
		}
		//display size of both armies
		cout << "Orc has " << orc.getArmySize() << " soilders left     trolls have " << troll.getArmySize() << " soilders left" << endl;
	}
	system("pause");
}

void Game::gameLoop()
{
	cout << "/////////////////////////////////////////////////" << endl;
	player->start();
	cout << "Orc has " << orc.getHealth() << " health     trolls have " << troll.getHealth() << " health" << endl;
	//select for kind of move 
	cout << "0:Spell \n1:Melee \n2:Shield" << endl;
	cin >> input;
	switch (input)
	{
	case 0:
		npc->takeDamage(player->spell());//causes damage to enemy based on attack
		break;
	case 1:
		npc->takeDamage(player->melee());
		break;
	case 2:
		player->shield();
		break;
	default:
		break;
	}
	npc->start();
	if (npc->getHealth() > 0)
	{
		switch (rand() % 3)//randomises move of enemy
		{
		case 0:
			player->takeDamage(npc->ranSpell());
			break;
		case 1:
			player->takeDamage(npc->ranMelee());
			break;
		case 2:
			npc->ranDefence();
			break;
		default:
			break;
		}
	}
}

void Game::guideBook()
{
	//sends out only very valuable information
	cout << "SPELLS:\nFire Blast: Will cause damage equal to double your strength but will hurt you equal to half your strength."
		"\nWater Splash: Will cause damage equal to half your strength and will heal you equal to half your strength."
		"\nGround Pound: Will cause damage equal to half your strength and will give you defence 2."
		"\nWind Slash: Will cause damage equal to your strength."
		"\nVoid Explosion: Will cause damage equal to quadruple your strength but will hurt you equal to triple your strength."
		"\nThumb control : Will cause damage equal to double your strength but will hurt you equal to half your strength."
		"\nIndex point: Will cause damage equal to half your strength and will heal you equal to half your strength."
		"\nMiddle aggresion: Will cause damage equal to half your strength and will give you defence 2."
		"\nRing trap: Will cause damage equal to your strength."
		"\nPinky puff: Will cause damage equal to quadruple your strength but will hurt you equal to triple your strength."
		"\n\nMELEE MOVES:\nWrath Berserk: Will increase your strength by 2,"
		"\nSloth crush: Will cause damage equal to 3/4 of your stength and will give you a defence of 2."
		"\nGluttony bite: Will cause damage equal to half of your stength and will heal you equal to half your strength."
		"\nPride stomp: Will cause damage equal to half of your stength and will give you a defence of 3."
		"\nGreed swipe: Will heal you by 8 health points."
		"\nEnvy steal: Will give you a defence equal to your strength."
		"\nLust Violation: Will cause damage equal to your strength."
		"\nBow shot: Will increase your strength by 2, "
		"\nGreat sword slash: Will cause damage equal to 3/4 of your stength and will give you a defence of 2."
		"\nScales of faith: Will cause damage equal to half of your stength and will heal you equal to half your strength."
		"\nDeath stare: Will cause damage equal to half of your stength and will give you a defence of 3."
		"\nMartyr soul: Will heal you by 8 health points."
		"\nGreat earthquake: Will give you a defence equal to your strength."
		"\nSeven D angels: Will cause damage equal to your strength."
		"\n\nDEFENCES:\nSheild protect: Will give you a defence of 3."
		"\nBrace: Will give you a defence equal to your strength."
		"\nBlood gaurd: Will give a defence equal to 1/10 of your strength but will hurt you the same amount."
		"\nRock block: Will give you a defence of 3."
		"\nScissors gaurd: Will give you a defence equal to your strength."
		"\nPaper sheild: Will give a defence equal to 1/10 of your strength but will hurt you the same amount." << std::endl;
	system("pause");
}
