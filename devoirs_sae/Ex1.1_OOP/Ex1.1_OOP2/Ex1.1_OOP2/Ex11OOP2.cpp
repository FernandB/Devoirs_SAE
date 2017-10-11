// Ex11OOP2.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <random>

enum fruit
{
	ORANGE,
	APPLE,
	MELON,
	BANANA,
	LENGTH
};

double probabilities[(int)fruit::LENGTH]=
{
	33.3,
	10.0,
	28.35,
	28.35
}
;

fruit random_fruit()
{
	srand(time(nullptr));
	double resultat = rand() % 100;
	double tmpTotal = 0;
	bool proba_found = false;
	int result = 0;
	while (result < (int)fruit::LENGTH&&!proba_found)
	{
		if (tmpTotal + probabilities[result] > resultat)
			proba_found = true;
		else
			tmpTotal += probabilities[result];

			result++;
	}
	result--;
	return (fruit)result;
}


int main()
{
	const char * fruit_string = "";
	fruit fruit=random_fruit();
	switch (fruit)
	{
	case fruit::APPLE: fruit_string = "APPLE";
		break;
	case fruit::BANANA: fruit_string = "BANANA";
		break;
	case fruit::MELON: fruit_string = "MELON";
		break;
	case fruit::ORANGE: fruit_string = "ORANGE";
		break;
	}
	std::cout << fruit_string << " \n";
	system("pause");
    return 0;
}

