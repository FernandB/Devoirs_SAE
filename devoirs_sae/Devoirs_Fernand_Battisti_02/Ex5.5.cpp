// Auteur: Fernand Battisti
// Date: 05.10.17
//Exercice: 5.5

#include "stdafx.h"
#include <iostream>
#define MAX_FIB_VALUE 4000000
int fib(int n)
{
	int somme = 0;
	int fibonnaci_result = 1;
	int fibonnaci_actuel = 1;
	int fibonnaci_precedent = 0;
	if (n > 0)
	{
		int i = 0;

		std::cout << fibonnaci_result << " ";
		while (i < n)
		{
			bool premier = true;
			fibonnaci_precedent = fibonnaci_actuel;
			fibonnaci_actuel = fibonnaci_result;
			if (fibonnaci_actuel + fibonnaci_precedent < MAX_FIB_VALUE)
			{
				fibonnaci_result = fibonnaci_actuel + fibonnaci_precedent;
				for (int i = 2; i < fibonnaci_result; i++)
				{
					if (fibonnaci_result % i == 0)
					{
						premier = false;
						break;
					}
				}
				if (premier)
				{
					somme = somme + fibonnaci_result;

					std::cout << fibonnaci_result << " ";
				}
			}
			else
			{
				//Sert à arrêter la boucle avant 4'000'000
				i = n - 1;
			}
			i++;
		}

	}
	return somme;
}

int main()
{
	std::cout << "La somme des nombres premiers de fibonnacci  avant 4000000 vaut :" << fib(1000000) << "\n";
	system("pause");
	return 0;
}
