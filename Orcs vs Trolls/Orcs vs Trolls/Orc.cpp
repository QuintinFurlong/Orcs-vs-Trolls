#include "Orc.h"

//all function use a switch which will cout a message and change some stats

int Orc::spellSelect()
{
	short input = 0;
	short damage = 0;
	std::cout << "\t0: Fire blast \n\t1: Water splash \n\t2: Ground pound \n\t3: Wind slash \n\t4: Void explosion" << std::endl;
	std::cin >> input;
	switch (input)
	{
	case 0:
		m_health -= m_strength / 2;
		damage = m_strength * 2;
		std::cout << "\tFire blast" << std::endl;
		break;
	case 1:
		m_health += m_strength / 2;
		damage = m_strength / 2;
		std::cout << "\tWater splash" << std::endl;
		break;
	case 2:
		m_defence = 2;
		damage = m_strength / 2;
		std::cout << "\tGround pound" << std::endl;
		break;
	case 3:
		damage = m_strength;
		std::cout << "\tWind slash" << std::endl;
		break;
	case 4:
		m_health -= m_strength * 3;
		damage = m_strength * 4;
		std::cout << "\tVoid explosion" << std::endl;
		break;
	default:
		break;
	}
	return damage;
}

int Orc::meleeSelect()
{
	short input = 0;
	short damage = 0;
	m_defence = 0;
	std::cout << "\t0: Wrath berserk \n\t1: Sloth crush\n\t2: Gluttony bite\n\t3: Pride stomp\n\t4: Greed swipe\n\t5: Envy steal\n\t6: Lust Violation " << std::endl;
	std::cin >> input;
	switch (input)
	{
	case 0:
		m_strength += 2;
		std::cout << "\tWrath berserk" << std::endl;
		break;
	case 1:
		m_defence = 2;
		damage = static_cast<int>(m_strength * .75);
		std::cout << "\tSloth crush" << std::endl;
		break;
	case 2:
		m_health += m_strength / 2;
		damage = m_strength / 2;
		std::cout << "\tGluttony bite" << std::endl;
		break;
	case 3:
		m_defence = 4;
		damage = m_strength / 2;
		std::cout << "\tPride stomp" << std::endl;
		break;
	case 4:
		m_health += 8;
		std::cout << "\tGreed swipe" << std::endl;
		break;
	case 5:
		m_defence = m_strength;
		std::cout << "\tEnvy steal" << std::endl;
		break;
	case 6:
		damage = m_strength;
		std::cout << "\tLust Violation" << std::endl;
		break;
	default:
		break;
	}
	return damage;
}

void Orc::defenceSelect()
{
	short input = 0;
	std::cout << "\t0: Sheild protect \n\t1: Brace \n\t2: Blood gaurd" << std::endl;
	std::cin >> input;
	switch (input)
	{
	case 0:
		m_defence = 3;
		std::cout << "\tSheild protect" << std::endl;
		break;
	case 1:
		m_defence = m_strength;
		std::cout << "\tBrace" << std::endl;
		break;
	case 2:
		m_defence = m_health / 10;
		m_health -= m_defence;
		std::cout << "\tBlood gaurd" << std::endl;
		break;
	default:
		break;
	}
}

int Orc::ranSpell()
{
	short damage = 0;
	switch (rand() % 5)
	{
	case 0:
		m_health -= m_strength / 2;
		damage = m_strength * 2;
		std::cout << "\tFire blast" << std::endl;
		break;
	case 1:
		m_health += m_strength / 2;
		damage = m_strength / 2;
		std::cout << "\tWater splash" << std::endl;
		break;
	case 2:
		m_defence = 2;
		damage = m_strength / 2;
		std::cout << "\tGround pound" << std::endl;
		break;
	case 3:
		damage = m_strength;
		std::cout << "\tWind slash" << std::endl;
		break;
	case 4:
		m_health -= m_strength * 3;
		damage = m_strength * 4;
		std::cout << "\tVoid explosion" << std::endl;
		break;
	default:
		break;
	}
	return damage;
}

int Orc::ranMelee()
{
	short damage = 0;
	m_defence = 0;
	switch (rand() % 7)
	{
	case 0:
		m_strength += 2;
		std::cout << "\tWrath berserk" << std::endl;
		break;
	case 1:
		m_defence = 2;
		damage = static_cast<int>(m_strength * .75);
		std::cout << "\tSloth crush" << std::endl;
		break;
	case 2:
		m_health += m_strength / 2;
		damage = m_strength / 2;
		std::cout << "\tGluttony bite" << std::endl;
		break;
	case 3:
		m_defence = 4;
		damage = m_strength / 2;
		std::cout << "\tPride stomp" << std::endl;
		break;
	case 4:
		m_health += 8;
		std::cout << "\tGreed swipe" << std::endl;
		break;
	case 5:
		m_defence = m_strength;
		std::cout << "\tEnvy steal" << std::endl;
		break;
	case 6:
		damage = m_strength;
		std::cout << "\tLust Violation" << std::endl;
		break;
	default:
		break;
	}
	return damage;
}

void Orc::ranDefence()
{
	switch (rand() % 3)
	{
	case 0:
		m_defence = 3;
		std::cout << "\tSheild protect" << std::endl;
		break;
	case 1:
		m_defence = m_strength;
		std::cout << "\tBrace" << std::endl;
		break;
	case 2:
		m_defence = m_health / 10;
		m_health -= m_defence;
		std::cout << "\tBlood gaurd" << std::endl;
		break;
	default:
		break;
	}
}

