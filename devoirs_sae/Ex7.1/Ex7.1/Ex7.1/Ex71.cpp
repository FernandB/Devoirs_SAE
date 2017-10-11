// Auteur Fernand Battisti
// Date 22.09.17
// Exercice 7.1

#include "stdafx.h"
#include <iostream>
#define	LENGTH 3


void GenerateMap(char tableau[3][3])
{

	for (int i = 0; i < LENGTH; i++)
	{
		int y = 0;
		//Pour chaque ligne on parcours les trois colonnes et on met le caractère dans le tableau
		while (y < LENGTH)
		{
				tableau[i][y] = '_';
			y++;
		}
	}
}

void ShowMap(char tableau[3][3])
{
	for (int i = 0; i < LENGTH; i++)
	{
		std::cout << "\n";
		int y = 0;
		while (y < LENGTH)
		{
			std::cout << tableau[i][y]<<" ";
			y++;
		}
	}
}
int AskColumn(int column)
{
	std::cout << "Which column ? \n";
	std::cin >> column;
	if(column<1||column>3)
	{
		std::cout << "Wrong input! Please retry. \n";
		column=AskColumn(column);
	}
	return column;
}

int AskRow(int row)
{
	
	row = 0;
	std::cout << "Which row would you play ? \n";
	std::cin >> row;
	if (row >= 1 && row <= 3)
	{
		return row;
	}
	else
	{
		std::cout << "Wrong input! Please retry. \n";
		row=AskRow(row);
	}
	return row;
}

void SetNewPosition(char currentPlayer,int row, int column, char tableau[3][3])
{
	row = AskRow(row);
	column = AskColumn(column);
	if (tableau[row - 1][column - 1] == '_')
	{
		tableau[row - 1][column - 1] = currentPlayer;
	}
	else
	{
		std::cout << "This position is taken, try again !";
		row = 0;
		column = 0;
		SetNewPosition(currentPlayer,row,column,tableau);
	}


}
bool CheckWin(char tableau[3][3], char currentPlayer)
{
	bool row1 = false;
	bool row2 = false;
	bool row3 = false;
	bool diagonal1 = false;
	bool diagonal2 = false;
	bool column1 = false;
	bool column2 = false;
	bool column3 = false;

	row1 = (currentPlayer == tableau[0][0]) && (currentPlayer == tableau[0][1]) && (currentPlayer == tableau[0][2]);
	row2 = (currentPlayer == tableau[1][0]) && (currentPlayer == tableau[1][1]) && (currentPlayer == tableau[1][2]);
	row3 = (currentPlayer == tableau[2][0]) && (currentPlayer == tableau[2][1]) && (currentPlayer == tableau[2][2]);
	diagonal1 = (currentPlayer == tableau[0][0]) && (currentPlayer == tableau[1][1]) && (currentPlayer == tableau[2][2]);
	diagonal2 = (currentPlayer == tableau[0][2]) && (currentPlayer == tableau[1][1]) && (currentPlayer == tableau[2][0]);
	column1 = (currentPlayer == tableau[0][0]) && (currentPlayer == tableau[1][0]) && (currentPlayer == tableau[2][0]);
	column2 = (currentPlayer == tableau[0][1]) && (currentPlayer == tableau[1][1]) && (currentPlayer == tableau[2][1]);
	column3 = (currentPlayer == tableau[0][2]) && (currentPlayer == tableau[1][2]) && (currentPlayer == tableau[2][2]);
	if (row1 || row2 || row3 || diagonal1 || diagonal2 || column1 || column2 || column3)
	{
		return true;
	}
	else
		return false;
}
void PlayGame(char currentPlayer,char p1,char p2, char tableau[3][3], bool p1Active)
{
	int row = 0;
	int column = 0;
	SetNewPosition(currentPlayer, row, column, tableau);
	ShowMap(tableau);
	if(p1Active)
	{
		
		if (!CheckWin(tableau, currentPlayer))
		{
			currentPlayer = p2;
			PlayGame(currentPlayer, p1, p2, tableau, false);
		}
		else
		{
			std::cout << " Player 1 WIN !";
		}
		
	}
	else
	{
		if (!CheckWin(tableau, currentPlayer))
		{
			currentPlayer = p1;
			PlayGame(currentPlayer, p1, p2, tableau, true);
		}
		else
		{
			std::cout << " Player 2 WIN !";
		}
	}
	
	
	
}


int main()
{
	char  tableau[3][3]; //= { { NULL,NULL,NULL },{ NULL,NULL,NULL },{ NULL,NULL,NULL } };
	GenerateMap(tableau);
	ShowMap(tableau);
	char player1 = 'X';
	char player2 = 'O';
	char currentPlayer = player1;
	bool player1Active = true;
	
	PlayGame(currentPlayer,player1,player2,tableau,player1Active);
	
		
		
	
	
	system("pause");
    return 0;
}

