// Auteur: Fernand Battisti
// Date: 18.09.17
//Exercice: 4.1

#include "stdafx.h"
#include <iostream>
#include <array>
//attention magic numbers et faire une fonction
int main()
{
	int somme = 0;
	double moyenne = 0;
	std::cout << "Veuillez entrer 5 chiffres ! \n";
	std::array<int, 5> tableau;
	for (int i = 0; i < 4; i++)
	{

		std::cin >> tableau[i];
		somme = somme + tableau[i];
	
	}
	moyenne = somme / 5.0;
	std::cout << "La moyenne est de "<< moyenne<<" ! \n";
	system("pause");

    return 0;

	
		
}

/*
une fonction qui utilise std::vector
double avg(const std::vector<int>& numbers)
{
	double average_number=0.0;
	for(const int& n:numbers) //foreach
	{
	average_number+=n;
	}
}

*/