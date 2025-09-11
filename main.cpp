#include<iostream>
#include"input.h"
#include"TicTacToe.h"
using namespace std;
void mainMenu();
void TicTacToeMenu();
int main()
{
	do
	{
		system("cls");
		mainMenu();
		switch (toupper(inputChar("\n\tOption: ")))
		{
		case '1': 
			TicTacToeMenu();
			break;
		case '2': 
			break;
		case '3': 
			break;
		case '0':
			exit(0);
			//EXIT_SUCCESS;
		default:
			cout << "\n\tERROR: Invalid Input.";
			break;

		}

		cout << "\n\n\t";
		system("pause");

	} while (true);

	return EXIT_SUCCESS;
	
}

void mainMenu()
{
	cout << "\n\tCMPR131 Chapter 3 - Games Applications using Container by Thi Ho, Khang Quach, Thi Ngoc Quynh Pham (09/02/2025)";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\t1> Tic-Tac-Toe";
	cout << "\n\t\t2> Tower of Hanoi";
	cout << "\n\t\t3> n-Queens";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\t0. Exit";
	cout << "\n\t" << string(80, char(205));
}

void TicTacToeMenu() {
	system("cls");
	cout << "\n\tTic-tac-toe (also known as Noughts and crosses or Xs and Os) is a game for two";
	cout << "\n\tplayers, X and O, who take turns marking the spaces in a 3x3 grid. The player who";
	cout << "\n\tsucceeds in placing three of their marks in a horizontal, vertical, or diagonal";
	cout << "\n\trow wins the game.";
	cout << "\n\tThis tic-tac-toe program plays against the computer. Human player, X, will always";
	cout << "\n\tfirst. Time will be recorded for the fastest and the slowest game. Average time will";
	cout << "\n\tthen be calculated and displayed.";
	cout << "\n\n\tGame begins...";

	

	TicTacToe t;
	char again;

	do {
		t.resetBoard();     
		cout << "\n\n\tGame begins...";
		t.playGame();           
		again = toupper(inputChar("\n\n\tPlay again? (Y-yes or N-no): ", "YN"));
	} while (again == 'Y');

	t.printStats();  
}


