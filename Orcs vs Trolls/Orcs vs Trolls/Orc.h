#ifndef ORC
#define ORC
#include <iostream>
#include "Character.h"

using namespace std;

class Orc : public Character {
private:
	int spellSelect();
	int meleeSelect();
	void defenceSelect();
public:
	void start() { cout << "Orcs turn" << endl; }
	int spell() { cout << "\tMe, proud orc use puny human spell" << endl; return spellSelect(); }
	int melee() { cout << "\tOrc hit!" << endl; return meleeSelect();}
	void shield() { cout << "\tOrc tough" << endl; defenceSelect(); }
	int ranSpell();
	int ranMelee();
	void ranDefence();
};
#endif // !ORC 