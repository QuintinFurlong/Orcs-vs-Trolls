#ifndef CHARACTER
#define CHARACTER

#include <iostream>
using namespace std;

class Character {
protected:
	int m_health, m_strength, m_defence, m_numOfSoilders, m_goldCoins;

public:
	virtual int spell() { cout << "Default spell" << endl; return m_strength;}
	virtual int melee() { cout << "Default melee" << endl; return m_strength;}
	virtual void shield() { cout << "Default shield" << endl; }
	virtual void start() { cout << "Default start" << endl;}
	//run the kind of move the user selected and ask for pacifics 
	virtual int spellSelect() { cout << "Default spell select" << endl; return m_strength; }
	virtual int meleeSelect() { cout << "Default melee select" << endl; return m_strength; }
	virtual void defenceSelect() { cout << "Default defence select" << endl;; }
	//randomises pacific move
	virtual int ranSpell() { cout << "Default random spell" << endl; return m_strength; }
	virtual int ranMelee() { cout << "Default random melee" << endl; return m_strength; }
	virtual void ranDefence() { cout << "Default random defence" << endl;; }

	void	recieveHealth(int newHealth) { m_health = newHealth; m_numOfSoilders--; }//sets health to taken number
	void	recieveStrength(int newStrength) { m_strength = newStrength; }//sets strength to taken number
	void	unGaurd() { m_defence = 0; }
	void	gatherArmy(int numOfRecruits) { m_numOfSoilders = numOfRecruits; m_goldCoins = 0;}//sets army size to taken number
	int		getHealth() { return m_health; }
	int		getArmySize() { return m_numOfSoilders; }
	void	takeDamage(int damage);
	void	lootDrop();//calculates loot
	void	shop();
};
#endif // !CHARACTER