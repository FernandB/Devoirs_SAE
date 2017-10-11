//Fernand Battisti
//09.10.17
//Exercice OOP_4.1

#include "stdafx.h"
#include <iostream>
#include "Monster.h"
#define DEFAULT_NUMBER 0
#define ORC 1
#define TROLL 2
#define GOBLIN 3
#define FIRST_PLAYER 1
#define SECOND_PLAYER 2
#define RACES_ARRAY_LENGTH 2
void ask_race(int player_number,int race,int races_selected[RACES_ARRAY_LENGTH])
{
	if (race == 0)
	{
		std::cout << "Player "<<player_number<<" : Enter 1 for Orc, 2 for Troll or 3 for Goblin \n";
		std::cin >> race;
		
	}
	if (race != ORC && race != TROLL && race != GOBLIN)
	{
		std::cout << "Player " << player_number << " : Wrong input! Please, enter 1 for Orc, 2 for Troll or 3 for Goblin \n";
		std::cin >> race;
		ask_race(player_number,race,races_selected);
	}
	else
	{
		if (player_number < SECOND_PLAYER)
		{
			races_selected[FIRST_PLAYER - 1] = race;
			player_number++;
			ask_race(player_number, DEFAULT_NUMBER, races_selected);
		}
		else
		{
			if (race != races_selected[FIRST_PLAYER - 1])
				races_selected[SECOND_PLAYER - 1] = race;
			else
			{
				std::cout << "Player " << player_number << " : Please enter a different number than player 1 ! \n";
				std::cin >> race;
				ask_race(player_number, race, races_selected);
			}
		}


		
	}

}
Monster create_monster(int player_number,double hp, double ap, double dp, double speed,int races_selected[RACES_ARRAY_LENGTH])
{
	const char * race="";
	std::cout << "Player " << player_number << " : Please enter the Health, the AttackPower, the DefensivePower and Speed values! \n";
	std::cin >> hp;
	std::cin >> ap;
	std::cin >> dp;
	std::cin >> speed;
	
	if (player_number < SECOND_PLAYER)
	{
		switch (races_selected[FIRST_PLAYER - 1])
		{
		case 1:race = "Orc";
			break;
		case 2:race = "Troll";
			break;
		case 3:race = "Goblin";
			break;
		}
		Monster monster = Monster(hp, ap, dp, speed,race);
		return monster;
	}
	else
	{
		switch (races_selected[SECOND_PLAYER - 1])
		{
		case 1:race = "Orc";
			break;
		case 2:race = "Troll";
			break;
		case 3:race = "Goblin";
			break;
		}
		Monster monster = Monster(hp, ap, dp, speed, race);
		return monster;
	}

}
int main()
{
	int races[RACES_ARRAY_LENGTH];
	ask_race(FIRST_PLAYER, DEFAULT_NUMBER,races);
	double hp = 0;
	double dp = 0;
	double ap = 0;
	double speed = 0;
	Monster player1=create_monster(FIRST_PLAYER, hp, ap, dp, speed, races);
	Monster player2=create_monster(SECOND_PLAYER, hp, ap, dp, speed, races);

	std::cout << player1.getRace() << " VS " << player2.getRace() << "\n";
	player1.attack(player2, false, DEFAULT_NUMBER);
	system("pause");
	
    return 0;
}

