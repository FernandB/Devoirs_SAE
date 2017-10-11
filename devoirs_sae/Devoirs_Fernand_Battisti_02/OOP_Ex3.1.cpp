// OOP_Ex3.1.cpp 
//Fernand Battisti
//09.10.17
#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

struct StudentExam
{
	std::string name;
	double grade;
};

int main()
{
	std::list<StudentExam> students = {
		{ "Jack", 2.0 },
		{ "John", 4.5 },
		{ "James", 6.0 },
		{ "Jillie", 4.0 },
		{ "Jonas", 3.5 },
	};

	for (StudentExam& student : students)
	{
		std::cout << "Eleve: " << student.name << " Note: "<<student.grade<<"\n";

	}
	system("pause");
}


