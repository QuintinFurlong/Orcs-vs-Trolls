#include "Character.h"

void Character::lootDrop()
{
	int luck = rand() % 100;//randomises gold drop

	m_goldCoins += luck;
	std::cout << "LOOT: " << luck << " gold coins" << std::endl;
}

void Character::shop()
{
	short input = 0;
	do
	{
		system("cls");
		std::cout << "WELCOME TO THE NEUTRAL SHOP. WHAT WOULD YOU LIKE?" << std::endl;
		std::cout << "Your number of coins: " << m_goldCoins << "   Your health: " << m_health << "   Your strength: " << m_strength << std::endl;
		std::cout << "0: \"Nothing I'm good.\" \n1: Ring to increase your health by 50(30 gold)\n2: Amulet to increase your health by 150(75 gold)"
			"\n3: Potion to increase your strength by 3(40 gold)\n4: Black & Red gloves to increase your strength by 8(100 gold)"
			"\n5: Armor of Zeldron to increase your strength by 20 and increase your health by 500(300 gold)" << std::endl;
		std::cin >> input;
		switch (input)
		{
		case 0:
			std::cout << "Come again." << std::endl;
			break;
		case 1:
			if (m_goldCoins >= 30)
			{
				m_goldCoins -= 30;
				m_health += 50;
				std::cout << "Your health has increased by 50." << std::endl;
			}
			break;
		case 2:
			if (m_goldCoins >= 75)
			{
				m_goldCoins -= 75;
				m_health += 150;
				std::cout << "Your health has increased by 150." << std::endl;
			}
			break;
		case 3:
			if (m_goldCoins >= 40)
			{
				m_goldCoins -= 40;
				m_strength += 3;
				std::cout << "Your strength has increased by 3." << std::endl;
			}
			break;
		case 4:
			if (m_goldCoins >= 100)
			{
				m_goldCoins -= 100;
				m_strength += 8;
				std::cout << "Your strength has increased by 8." << std::endl;
			}
			break;
		case 5:
			if (m_goldCoins >= 300)
			{
				m_goldCoins -= 300;
				m_strength += 20;
				m_health += 500;
				std::cout << "Your strength has increased by 20 and Your health has increased by 500." << std::endl;
			}
			break;
		default:
			break;
		}
	} while (input != 0);
}

void Character::takeDamage(int damage)
{
	damage -= m_defence;//calculates damage after defence
	if (damage > 0)//doesn't increase health after attack
	{
		m_health -= damage;
	}
	if (m_health <= 0)
	{
		m_health = 0;
	}
}
