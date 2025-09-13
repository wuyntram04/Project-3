#include<iostream>
#include<iomanip>
#include"input.h"
#include"TowerOfHanoi.h"
using namespace std;
void mainMenu();
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
			break;
		case '2':
			TowerOfHanoiMenu();
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

	t.playGame();

	do
	{
		switch (toupper(inputChar("\n\tPlay again? (Y-yes or N-no): ", 'YN')))
		{
		case 'Y':
		{
			t.resetBoard();
			t.playGame();

		}
		break;
		case 'N': return;
		default: cout << "\n\tInvalid Option.";
		}
	} while (true);
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
	char option = ' ';
	bool playAgain = true;

	toh.setRings(inputInteger("\n\tEnter the number of ring (1..64) to begin: ", 1, 64));

	do 
	{
		toh.displayTower();

		option = inputChar("\n\n\tSelect the top disk from the start peg (A, B, C, or Q-quit): ", static_cast<string>("ABCQ"));
		switch (toupper(option))
		{
		case 'A':
			option = inputChar("\tSelect the end peg (A, B, C or Q-quit) to move the selected disk: ", static_cast<string>("ABCQ"));

			switch(toupper(option))
			{
			case 'B':
				toh.moveAtoB();
				break;
			case 'C':
				toh.moveAtoC();
				break;
			}
			break;
		case 'B':
			option = inputChar("\tSelect the end peg (A, B, C or Q-quit) to move the selected disk: ", static_cast<string>("ABCQ"));
			switch (toupper(option))
			{
			case 'A':
				toh.moveBtoA();
				break;
			case 'C':
				toh.moveBtoC();
				break;
			}
			break;
		case 'C':
			option = inputChar("\tSelect the end peg (A, B, C or Q-quit) to move the selected disk: ", static_cast<string>("ABCQ"));
			switch (toupper(option))
			{
			case 'A':
				toh.moveCtoA();

				break;
			case 'B':
				toh.moveCtoB();
				break;
			}
			break;
		case 'Q':
			break;

		default:
			cout << "\n\tERROR: Cannot make the move. The selected end peg cannot be the same as the selected start peg.";
			cout << "Please choose again.";
			break;

		}
		cout << "\n";

		if (toh.checkWin())
		{
			toh.displayTower();

			cout << "\n\n\tCongratuation! You have solved the game in " << toh.getCurrentMoves() << " moves.";

			if (inputChar("\n\n\tPlay again? (Y-yes) or (N-no) ", static_cast<string>("YN")) == 'Y')
			{
				playAgain = true;
				toh.restartGame();
				toh.setRings(inputInteger("\n\tEnter the number of ring (1..64) to begin: ", 1, 64));
			}
			else
			{
				playAgain = false;
				option = 'Q';
			}
		}

	} while (option != 'Q' && playAgain);
	
	toh.~TowerOfHanoi();
	return;
}
