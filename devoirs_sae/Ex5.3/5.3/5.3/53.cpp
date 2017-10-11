// Auteur: Fernand Battisti
// Date: 18.09.17
//Exercice: 5.3

#include "stdafx.h"
#include <iostream>

int fib(int n)
{
	int somme = 0;
	int fibonnaci_result = 1;
	int fibonnaci_actuel = 1;
	int fibonnaci_precedent = 0;
	if (n > 0)
	{
		//Initialiser a 1 puisque on commence avec 0 et 1
		int i = 0;
		
		std::cout << fibonnaci_result << " ";
		while (i < n)
		{
			fibonnaci_precedent = fibonnaci_actuel;
			fibonnaci_actuel = fibonnaci_result;
			if (fibonnaci_actuel + fibonnaci_precedent < 4000000)
			{
				fibonnaci_result = fibonnaci_actuel + fibonnaci_precedent;
				if (fibonnaci_result % 2 == 0)
					somme = somme + fibonnaci_result;

				std::cout << fibonnaci_result << " ";
			}
			else
			{
				//Sert à arrêter la boucle avant 4000000
				i = n - 1;
			}
			i++;
		}

	}
	return somme;
}

int main()
{
	std::cout<<"La somme des nombres de fibonnacci paires avant 4000000 vaut :"<<fib(1000000)<<"\n";
	system("pause");
	return 0;
}
