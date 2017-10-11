//Fernand Battisti
//09.10.17
//Exercice OOP_4.1

#ifndef MONSTER_H
#define MONSTER_H


class Monster
{
protected:
	double health;
	double attack_power;
	double defense;
	double speed;
	char const * race;
public:
	Monster(double health, double attack_power, double defense, double speed, char const * race);
	~Monster();
	void attack(Monster opponent, bool fastest_checked, int turn_number);
	void setHealth(double new_health);
	char const* getRace();
};

#endif 