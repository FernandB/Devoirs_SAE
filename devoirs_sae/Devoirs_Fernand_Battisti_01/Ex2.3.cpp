//Auteur: Fernand Battisti
//Date : 15.09.17
//Exercice : 2.3
#include "stdafx.h"
#include <iostream>

int enter_number(int number)
{
	std::cout << "Is this number a prime number: ";
	std::cin >> number;
	if (number < 0)
		return -1;
	else
	return number;
	
}
int main()
{
	int number = 0;
	do {
		//a la place de number utiiser la racine du nombre
		number = enter_number(number);
		bool entier = true;
		for (int i = 2; i < number; i++)
		{
		if (number % i == 0)
		{
			entier = false;
			//break;
			//continue; pour continuer la boucle.
		}
		}
		//il aurait fallut juste mettre le boolean ds la condition car 2 est nombre premier
		if (number>2&&entier)
			std::cout << "\n Yes \n";
		else
			std::cout << "\n No \n";

	} while (number != -1);
	

		
		
		
    return 0;
}

