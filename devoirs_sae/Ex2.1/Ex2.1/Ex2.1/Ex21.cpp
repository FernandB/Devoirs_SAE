//Auteur: Fernand Battisti
//Date : 15.09.17
//Exercice : 2.1

#include "stdafx.h"
#include <iostream>
#define _USE_MATH_DEFINES   
#include <math.h>  


int enter_radius(int radius)
{
	std::cin >> radius;
	return radius;
}

void calculate_area_perimeter(int radius)
{
	double area = pow(radius, 2)*M_PI;
	double perimeter = 2 * M_PI*radius;
	std::cout << "Area : "<< area << "\nPerimeter : "<<perimeter<<"\n";
	system("pause");
}

int main()
{
	int radius = 0;

	std::cout << "Please enter the radius of the circle : \n";
	radius = enter_radius(radius);
	
	
	if (radius >= 0)
	{
		calculate_area_perimeter(radius);
	}
	else
	{
		while (radius < 0)
		{
			std::cout << "Please enter a positive number ! \n";
			radius = enter_radius(radius);
		}
		calculate_area_perimeter(radius);
	}

	
    return 0;
}

