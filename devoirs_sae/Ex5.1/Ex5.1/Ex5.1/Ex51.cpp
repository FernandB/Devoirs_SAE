// Auteur: Fernand Battisti
// Date: 18.09.17
//Exercice: 5.1

#include "stdafx.h"
#include <iostream>

int fib(int n)
{
	int fibonnaci_result = 1;
	int fibonnaci_actuel = 1;
	int fibonnaci_precedent = 0;
	if (n == 1)
		return fibonnaci_precedent;
	if (n > 0)
	{	
		//Initialiser a 1 puisque on commence avec 0 et 1
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
		return fibonnaci_result;
	}
}
int main()
{
	fib(18);
	system("pause");
    return 0;
}

