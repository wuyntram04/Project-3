#include <iostream>
#include "TicTacToe.h"
#include "input.h"

using namespace std;

void tictactoe();

int main()
{
	cout << "\n\tCMPR131 Chapter 3 - Games Applications using Container by Thinh";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\t1> Tic-Tac-Toe";
	cout << "\n\t\t2> Tower of Hanoi";
	cout << "\n\t\t3> n-Queens";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\t0. Exit";
	cout << "\n\t" << string(80, char(205));

	char option = toupper(inputChar("\n\tOption: ", static_cast<string>("1230")));
	switch (option)
	{
	case 48: //0
		return 0;
	case 49:
		tictactoe();
		break;
	}

	cout << "\n\n";
	system("pause");
	
}


void tictactoe()
{
	system("cls");
	TicTacToe game;
	char player1 = 'X';

	int count = 0;

	game.displayBoard();

	while (count < 9)
	{
		int row = inputInteger("\n\tEnter the board's row # (1..3) or 0 to forfeit: ", 0, 3);
		int col = inputInteger("\tEnter the board's column # (1..3) or 0 to forfeit: ", 0, 3);

		if (game.setPos(player1, row - 1, col - 1))
		{
			game.displayBoard();

			game.AI();
			game.displayBoard();
			count++;
		}
		else
		{
			cout << "\n\tERROR: Illegal move. The square has already owned. Please re-specify.";
		}
		
	}

}


