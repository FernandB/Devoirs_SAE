// Auteur Fernand Battisti
//Date 22.09.17
//Exercice 6.1

#include "stdafx.h"
#include <iostream>
#include <array>
#include <limits>
#define nb_length 10
int max(int numbers_length, int* numbers)
{
	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < numbers_length; i++)
	{
		if (*(numbers+i) > max)
		{
			max = *(numbers+i);
		}
	}
	
	return max;
}

int min(int numbers_length, int* numbers)
{
	int min = std::numeric_limits<int>::max();
	for (int i = 0; i < numbers_length; i++)
	{
		if (*(numbers+i) < min)
		{
			min = *(numbers+i);
		}
	}

	return min;
}
int main()
{
	std::cout << "Entrez 10 chiffres : \n";

	int tableau[nb_length];
	for (int i = 0; i < nb_length; i++)
	{
		std::cin >> tableau[i];
	}
	int* numbers = tableau;
	std::cout << "Le chiffre max vaut " << max(nb_length,numbers) << " et le chiffre minimum vaut " << min(nb_length,numbers)<<"\n";
	system("pause");
    return 0;
}

