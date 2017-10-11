// Auteur: Fernand Battisti
// Date: 18.09.17
//Exercice: 5.1

#include "stdafx.h"
#include <iostream>

void fib(int n)
{
	int fibonnaci_result = 1;
	int fibonnaci_actuel = 1;
	int fibonnaci_precedent = 0;
	if (n > 0)
	{	
		int i = 0;
		std::cout << fibonnaci_result << " ";
		while (i < n)
		{
			fibonnaci_precedent = fibonnaci_actuel;
			fibonnaci_actuel = fibonnaci_result;
			fibonnaci_result = fibonnaci_actuel + fibonnaci_precedent;
			std::cout << fibonnaci_result << " ";

			i++;
		}
		
	}
}
int main()
{
	fib(18);
	system("pause");
    return 0;
}

