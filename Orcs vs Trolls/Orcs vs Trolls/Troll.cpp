#include "Troll.h"

//all function use a switch which will cout a message and change some stats

int Troll::spellSelect()
{
	short input = 0;
	short damage = 0;
	std::cout << "\t0: Thumb control \n\t1: Index point \n\t2: Middle aggresion \n\t3: Ring trap \n\t4: Pinky puff" << std::endl;
	std::cin >> input;
	switch (input)
	{
	case 0:
		m_health -= m_strength / 2;
		damage = m_strength * 2;
		std::cout << "\tThumb control" << std::endl;
		break;
	case 1:
		m_health += m_strength / 2;
		damage = m_strength / 2;
		std::cout << "\tIndex point" << std::endl;
		break;
	case 2:
		m_defence = 2;
		damage = m_strength / 2;
		std::cout << "\tMiddle aggresion" << std::endl;
		break;
	case 3:
		damage = m_strength;
		std::cout << "\tRing trap" << std::endl;
		break;
	case 4:
		m_health -= m_strength * 3;
		damage = m_strength * 4;
		std::cout << "\tPinky puff" << std::endl;
		break;
	default:
		break;
	}
	return damage;
}

int Troll::meleeSelect()
{
	short input = 0;
	short damage = 0;
	m_defence = 0;
	std::cout << "\t0: Bow shot \n\t1: Great sword slash \n\t2: Scales of faith\n\t3: Death stare\n\t4: Martyr soul\n\t5: Great earthquake\n\t6: Seven D angels" << std::endl;
	std::cin >> input;
	switch (input)
	{
	case 0:
		m_strength += 2;
		std::cout << "\tBow shot" << std::endl;
		break;
	case 1:
		m_defence = 4;
		damage = static_cast<int>(m_strength * .75);
		std::cout << "\tGreat sword slash" << std::endl;
		break;
	case 2:
		m_health += m_strength / 2;
		damage = m_strength / 2;
		std::cout << "\tScales of faith" << std::endl;
		break;
	case 3:
		m_defence = 8;
		damage = m_strength / 2;
		std::cout << "\tDeath stare" << std::endl;
		break;
	case 4:
		m_health += 8;
		std::cout << "\tMartyr soul" << std::endl;
		break;
	case 5:
		m_defence = m_strength;
		std::cout << "\tGreat earthquake" << std::endl;
		break;
	case 6:
		damage = m_strength;
		std::cout << "\tSeven D angels" << std::endl;
		break;
	default:
		break;
	}
	return damage;
}

void Troll::defenceSelect()
{
	short input = 0;
	std::cout << "\t0: Rock block \n\t1: Scissors gaurd \n\t2: Paper sheild" << std::endl;
	std::cin >> input;
	switch (input)
	{
	case 0:
		m_defence = 6;
		std::cout << "\tRock block" << std::endl;
		break;
	case 1:
		m_defence = m_strength;
		std::cout << "\tScissors gaurd" << std::endl;
		break;
	case 2:
		m_defence = m_health / 10;
		m_health -= m_defence;
		std::cout << "\tPaper sheild" << std::endl;
		break;
	default:
		break;
	}
}

int Troll::ranSpell()
{
	short damage = 0;
	switch (rand() % 5)
	{
	case 0:
		m_health -= m_strength / 2;
		damage = m_strength * 2;
		std::cout << "\tThumb control" << std::endl;
		break;
	case 1:
		m_health += m_strength / 2;
		damage = m_strength / 2;
		std::cout << "\tIndex point" << std::endl;
		break;
	case 2:
		m_defence = 2;
		damage = m_strength / 2;
		std::cout << "\tMiddle aggresion" << std::endl;
		break;
	case 3:
		damage = m_strength;
		std::cout << "\tRing trap" << std::endl;
		break;
	case 4:
		m_health -= m_strength * 3;
		damage = m_strength * 4;
		std::cout << "\tPinky puff" << std::endl;
		break;
	default:
		break;
	}
	return damage;
}

int Troll::ranMelee()
{
	short damage = 0;
	m_defence = 0;
	switch (rand() % 7)
	{
	case 0:
		m_strength += 2;
		std::cout << "\tBow shoot" << std::endl;
		break;
	case 1:
		m_defence = 4;
		damage = static_cast<int>(m_strength * .75);
		std::cout << "\tGreat sword slash" << std::endl;
		break;
	case 2:
		m_health += m_strength / 2;
		damage = m_strength / 2;
		std::cout << "\tScales of faith" << std::endl;
		break;
	case 3:
		m_defence = 8;
		damage = m_strength / 2;
		std::cout << "\tDeath stare" << std::endl;
		break;
	case 4:
		m_health += 8;
		std::cout << "\tMartyr soul" << std::endl;
		break;
	case 5:
		m_defence = m_strength;
		std::cout << "\tGreat earthquake" << std::endl;
		break;
	case 6:
		damage = m_strength;
		std::cout << "\tSeven D angels" << std::endl;
		break;
	default:
		break;
	}
	return damage;
}

void Troll::ranDefence()
{
	switch (rand() % 3)
	{
	case 0:
		m_defence = 6;
		std::cout << "\tRock block" << std::endl;
		break;
	case 1:
		m_defence = m_strength;
		std::cout << "\tScissors gaurd" << std::endl;
		break;
	case 2:
		m_defence = m_health / 10;
		m_health -= m_defence;
		std::cout << "\tPaper sheild" << std::endl;
		break;
	default:
		break;
	}
}
