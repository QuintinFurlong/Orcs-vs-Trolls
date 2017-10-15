#ifndef TROLL
#define TROLL

#include <iostream>
#include "Character.h"

using namespace std;

class Troll : public Character {
private:
	int spellSelect();
	int meleeSelect();
	void defenceSelect();
public:
	void start() { cout << "Trolls turn" << endl; }
	int spell() { cout << "Eye cane speel purfektlie" << endl; return spellSelect();}
	int melee() { cout << "I hurt you on outside" << endl; return meleeSelect();}
	void shield() { cout << "I am rubber, you are glue" << endl; defenceSelect(); }
	int ranSpell();
	int ranMelee();
	void ranDefence();
};
#endif // !TROLL