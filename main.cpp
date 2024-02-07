#include <iostream>
using namespace std;

void printMenu(char feld[3][3]);
bool isWinner(char feld[3][3]);

int main()
{
	int column;
	int row;
	char currentPlayer = 'X';

	char feld[3][3] = { { '-', '-', '-' },
			    { '-', '-', '-' },
			    { '-', '-', '-' } };

	do
	{
		printMenu(feld);

		cout << "Spieler: " << currentPlayer << endl;

		cout << "Reihe: ";
		cin >> row;

		cout << "Spalte: ";
		cin >> column;

		if (feld[row - 1][column - 1] == '-')
		{
			feld[row - 1][column - 1] = currentPlayer;
			currentPlayer = (currentPlayer == 'X')? 'O' : 'X'; // ternärer Operator ( wenn player == X, player wenn wahr == O, wenn nicht weiterhin player == X )
		}
		else
		{
			cout << "Ungültiger Zug. Das Feld ist bereits belegt." << endl;
		}

	} while (!isWinner(feld));

	system("cls");
	printMenu(feld);

	cout << "Spieler ";

	if (currentPlayer == 'X')
	{
		cout << "O";
	}
	else
	{
		cout << "X";
	}

	cout << " hat gewonnen." << endl;

	return 0;
}

void printMenu(char feld[3][3])
{
	system("cls");
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << feld[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

bool isWinner(char feld[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (feld[i][0] != '-' && feld[i][0] == feld[i][1] && feld[i][1] == feld[i][2])
		{
			return true;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (feld[0][i] != '-' && feld[0][i] == feld[1][i] && feld[1][i] == feld[2][i])
		{
			return true;
		}
	}

	if (feld[0][0] != '-' && feld[0][0] == feld[1][1] && feld[1][1] == feld[2][2])
	{
		return true;
	}

	if (feld[0][2] != '-' && feld[0][2] == feld[1][1] && feld[1][1] == feld[2][0])
	{
		return true;
	}

	return false;
}
