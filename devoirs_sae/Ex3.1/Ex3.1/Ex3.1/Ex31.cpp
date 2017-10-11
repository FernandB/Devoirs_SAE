//Auteur: Fernand Battisti
//Date : 16.09.17
//Exercice : 3.1

#include "stdafx.h"
#include <iostream>
#include "math.h"


int main()
{
	int sum = 0;
	std::cout << "The number multiple of 5 or 3 are : \n";
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

