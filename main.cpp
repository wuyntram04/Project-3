#include<iostream>
#include"input.h"
#include"TicTacToe.h"
#include"n_Queens.h"
#include"TowerOfHanoi.h"

using namespace std;
void mainMenu();
void TicTacToeMenu();
void nQueensMenu();
void TowerOfHanoiMenu();

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
			TowerOfHanoiMenu();
			break;
		case '3': 
			nQueensMenu();
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


void TowerOfHanoiMenu()
{
	system("cls");
	cout << "\n\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game.";
	cout << "\n\tIt consists of three pegs and a number of rings of different sizes, which can slide onto";
	cout << "\n\tany peg. The game starts with the rings in a neat stack in ascending order of size on one";
	cout << "\n\tpeg, the smallest at the top, thus making a conical shape.";
	
	cout << "\n\tThe objective of the game is to move the entire stack from the starting peg-A to ending peg-B,";
	cout << "\n\tobeying the following simple rules:";

	cout << "\n\n\t\t1. Only one disk can be moved at a time.";
	cout << "\n\t\t2. Each move consists of taking the upper disk from one of the stacks and";
	cout << "\n\t\tplacing it on top of another stack or on an empty peg.";
	cout << "\n\t\t3. No larger disk may be placed on top of a smaller disk.";

	cout << "\n\n";

	TowerOfHanoi toh;

	toh.playGame();

	return;
}


void nQueensMenu()
{
	n_Queens n;

	system("cls");
	cout << "\n\tThe n-queens puzzle is the problem of placing n chess queens on a n?n chessboard";
	cout << "\n\tso that no two queens threaten each other; thus, a solution requires that no two";
	cout << "\n\tqueens share the same row, column, or diagonal. Solutions exist for all natural";
	cout << "\n\tnumbers n with the exception of n = 2 and n = 3.";

	n.playGame();
	
}


