//Fernand Battisti
//09.10.17
#include "stdafx.h"
#include "Monster.h"
#include <iostream>
Monster::Monster(double health, double attack_power, double defense, double speed, char const * race): health(health), attack_power(attack_power), defense(defense), speed(speed), race(race)
{
	
}


Monster::~Monster()
{
}
void Monster::setHealth(double new_health)
{	
	health = new_health;
}

char const * Monster::getRace()
{
	return race;
}
void Monster::attack(Monster opponent, bool fastest_checked, int turn_number)
{
	//check who is the fastest
	if (!fastest_checked&&speed > opponent.speed)
	{
		turn_number = 1;
		fastest_checked = true;
		double damage = attack_power - opponent.defense;
		if (damage < 0)
			damage = 1;
		double opponent_health = opponent.health - damage;
		opponent.setHealth(opponent_health);
		if (opponent_health <= 0)
		{
			std::cout << "The " << race << " win ! \n";
		}
		else
		{
			
			std::cout <<"Turn "<<turn_number<<": "<< opponent.race << " health's is " << opponent.health << "\n";
			turn_number++;
			opponent.attack(*this,fastest_checked,turn_number);
		}

	}
	else
	{
		if (!fastest_checked)
		{
			turn_number = 1;
			fastest_checked = true;
			double damage = opponent.attack_power - defense;
			if (damage < 0)
				damage = 1;
			double my_health = health - damage;
			setHealth(my_health);
			if (my_health <= 0)
			{
				std::cout << "Turn " << turn_number << ": " << "The " << opponent.race << " win ! \n";
			}
			else
			{
				std::cout << "Turn " << turn_number << ": " << race << " health's is " << health<<"\n";
				turn_number++;
				attack(opponent, fastest_checked,turn_number);
			}
		}
		else
		{
			double damage = attack_power - opponent.defense;
			if (damage < 0)
				damage = 1;
			double opponent_health = opponent.health - damage;
			opponent.setHealth(opponent_health);
			if (opponent_health <= 0)
			{
				std::cout << "Turn " << turn_number << ": " << "The " << race << " win ! \n";
			}
			else
			{
				std::cout << "Turn " << turn_number << ": " << opponent.race << " health's is " << opponent.health << "\n";
				turn_number++;
				opponent.attack(*this, fastest_checked,turn_number);
			}
		}
	}
	
}