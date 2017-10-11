// Ex11OOP.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <ctime>
#include <string>
enum class Fruit
{
	ORANGE=0,
	PINEAPPLE=1,
	APPLE=2,
	GRAPPEFRUIT=3,
	BLUEBERRIES=4,
	LENGTH
};



Fruit random()
{
	double probabilities[(int)Fruit::LENGTH]
		=
	{
		15,10,12,17,46
	};
	srand(time(nullptr));
	int totalProbability = 0;
	for (int i = 0; i<(int)Fruit::LENGTH; i++)
	{
		totalProbability += probabilities[i];
	}
	int randomValue = rand() % totalProbability;
	int tmpTotal = 0;
	int result = 0;
	for (result = 0; result<(int)Fruit::LENGTH; result++)
	{
		if (tmpTotal + probabilities[result] > randomValue)
		{
			break;
		}
		tmpTotal += probabilities[result];
	}
	return (Fruit)result;
}

std::ostream& operator << (std::ostream& os, const Fruit& obj)
{
	os << static_cast<std::underlying_type<Fruit>::type>(obj);
	return os;
}

int main()
{
	const char* fruit = "";
	Fruit fruit_random=random();
	switch (fruit_random)
	{
	case Fruit::ORANGE: fruit = "Orange";
		break;
	case Fruit::PINEAPPLE: fruit = "PINEAPPLE";
		break;
	case Fruit::APPLE: fruit = "APPLE";
		break;
	case Fruit::GRAPPEFRUIT: fruit = "GRAPPEFRUIT";
		break;
	case Fruit::BLUEBERRIES: fruit = "BLUEBERRIES";
		break;

	}
	std::ostream stream(nullptr);
	std::cout << "Random fruit : " << fruit<<"\n";
	system("pause");

    return 0;
}

