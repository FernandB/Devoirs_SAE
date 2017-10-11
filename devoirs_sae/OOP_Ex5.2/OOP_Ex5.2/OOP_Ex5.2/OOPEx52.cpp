// OOP_Ex5.2.cpp
//Fernand Battisti

#include "stdafx.h"
#include "Shapes.h"
#include <iostream>

int main()
{
	Shape* s1 = new Rectangle(3.0, 4.0, 5.0, 6.0);
	Shape* s2 = new Circle(6.0, 5.0, 3.0);

	if (s1->isColliding(s2))
	{
		std::cout << "Ouistiti\n";
	}
	else
	{
		std::cout << "Nomenclature\n";
	}

	delete s1;
	delete s2;
	system("pause");
	return 0;
}


