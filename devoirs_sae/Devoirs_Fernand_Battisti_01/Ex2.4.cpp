//Auteur: Fernand Battisti
//Date : 16.09.17
//Exercice : 2.4
#include "stdafx.h"
#include <iostream>
//#include "math.h"

int main()
{
	double  nombre = 0;
	std::cout << "Entrez un nombre a virgule : ";
	std::cin >> nombre;
	if (nombre < 0)
		std::cout << "Erreur: le nombre est negatif ! \n";
	else
	{
		nombre = sqrt(nombre);
		std::cout << "La racine carree est egale a : " << nombre<<"\n";

	}
	system("pause");

    return 0;
}

