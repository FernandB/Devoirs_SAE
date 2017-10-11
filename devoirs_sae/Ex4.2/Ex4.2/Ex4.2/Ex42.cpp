// Auteur: Fernand Battisti
// Date: 05.10.17
//Exercice: 4.2

#include "stdafx.h"
#include <iostream>
#include <vector>
 
int vector_length = 0;

void ask_vector_length()
{
	std::cout << "Please give the number of integers : \n";
	std::cin >> vector_length;
	
}
double avg(const std::vector<int>& numbers)
{
	double average_number = 0.0;
	for (const int& n : numbers) //foreach
	{
		average_number += n;
	}

	return average_number = average_number / vector_length;
}

void fill_vector( std::vector<int>& numbers)
{
	

	std::cout << "Please give the " << vector_length << " values \n";
	int i = 0;
	while (i < vector_length)
	{
		int input_number = 0; 
		std::cin >> input_number;
		 numbers.push_back(input_number);
		i++;
	}

}
int main()
{
	
	std::vector<int> numbers;
	ask_vector_length();
	fill_vector(numbers);
	std::cout << "La moyenne est de " << avg(numbers) << " ! \n";
	system("pause");

	return 0;



}




