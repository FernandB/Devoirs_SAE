// Ex2.1_OOP.cpp
//Fernand Battisti
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct StudentExam
{
	std::string name;
	double grade;
};

void print_best_student(std::vector<StudentExam>& students)
{
	StudentExam best_student = { "",std::numeric_limits<int>::min() };
	for (StudentExam& student : students)
	{
		if (student.grade > best_student.grade)
		{
			best_student = student;
		}
	}
	std::cout << "Best student: " << best_student.name << " \n";

}
int main()
{
	std::vector<StudentExam> students = {
		{ "Jack", 2.0 },
		{ "John", 4.5 },
		{ "James", 6.0 },
		{ "Jillie", 4.0 },
		{ "Jonas", 3.5 },
	};
	print_best_student(students);

	system("pause");
	return 0;

}
