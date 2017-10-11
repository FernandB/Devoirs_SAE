//Auteur: Fernand Battisti
//Date : 16.09.17
//Exercice : 3.1

#include "stdafx.h"
#include <iostream>
#include "math.h"
// !!! eviter les nombres magiques-->define pr 1000, 3 et 5 ou un tableau!!!

int main()
{
	int sum = 0;
	std::cout << "The number multiple of 5 or 3 are : \n";
	//La boucle affiche chaque nombre correspondant a la condition
	for (int i = 1; i < 1000; i++)
	{
		
		if (i % 3 == 0 || i % 5 == 0)
		{
			std::cout << i<<", ";

			sum = sum + i;
		}
	}
	std::cout << "The sum is equal to : "<<sum<<"\n";
	system("pause");

	
    return 0;
}

