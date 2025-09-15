#include <stack>
#include <iomanip>

#pragma once
using namespace std;

class TowerOfHanoi
{
private:

	int rings = 0;

	stack <int> towerA;
	stack <int> towerB;
	stack <int> towerC;

	int totalMoves = 0;

public:

	// Default constructor
	// Precondition: None
	// Postcondition: Initializes the game with 0 rings.
	TowerOfHanoi()
	{
		rings = 0;

		stack <int> newStack;
		towerA = newStack;
	}


	// Parameterized constructor
	// Precondition: The input 'r' must be non-negative integer representing the number of rings.
	// Postcondition: Initializes the game with 'r' rings on Tower A, arranged from largest (bottom) to smallest (top).
	TowerOfHanoi(int r)
	{
		rings = r;

		for (int i = r; i > 0; --i)
		{
			towerA.push(i);
		}
	}


	// Precondition: Tower A must be empty.
	// Postcondition: Pushes a number of rings onto Tower A from largest (bottom) to smallest (top).
	void setRings(int r)
	{
		rings = r;

		for (int i = r; i > 0; --i)
		{
			towerA.push(i);
		}
	}

	// Precondition: None.
	// Postcondition: Display the three towers: A, B and C.
	void displayTower()
	{
		cout << "\n\tTower of Hanoi\n";

		stack <int> tempA = towerA;
		stack <int> tempB = towerB;
		stack <int> tempC = towerC;

		if (rings == 3 || rings > 9)
		{
			cout << "\n\t" << string(3, char(' ')) << "\xBA" << string(7, char(' ')) << "\xBA" << string(7, char(' ')) << "\xBA" << "\n"; // ■ 
		}else
			cout << "\n\t" << string(rings, char(' ')) << "\xBA" << string(rings * 2 + 5, char(' ')) << "\xBA" << string(rings * 2 + 5, char(' ')) << "\xBA" << string(5, char(' ')) << "\n"; // ■ 


		if(rings <= 9)
		{

			for (int i = rings; i > 0; i--)
			{
				cout << "\t";
				if (i <= tempA.size() && !tempA.empty())
				{
					int space = 0;

					while (space < (rings - tempA.top()))
					{
						cout << " ";
						space++;
					}

					for (int j = 1; j <= tempA.top(); j++)
					{
						cout << "\xFE";
					}

					cout << tempA.top();

					for (int j = 1; j <= tempA.top(); j++)
					{
						cout << "\xFE";
					}

					space = 0;

					while (space < (rings - tempA.top()))
					{
						cout << " ";
						space++;
					}


					if (rings == 3)
					{
						cout << string(1, char(' '));
					}
					else
					{
						cout << string(5, char(' '));
					}

					tempA.pop();
				}
				else
				{
					cout << setw(rings + 1) << "\xBA";

					if (rings == 3)
					{
						cout << string(rings +1 , char(' '));
					}
					else
					{
						cout << string(rings + 5, char(' '));
					}
					
				}

				//cout << "\t";

				if (i <= tempB.size() && !tempB.empty())
				{
					int space = 0;

					while (space < (rings - tempB.top()))
					{
						cout << " ";
						space++;
					}

					for (int j = 1; j <= tempB.top(); j++)
					{
						cout << "\xFE";
					}

					cout << tempB.top();

					for (int j = 1; j <= tempB.top(); j++)
					{
						cout << "\xFE";
					}

					space = 0;

					while (space < (rings - tempB.top()))
					{
						cout << " ";
						space++;
					}

					if (rings == 3)
					{
						cout << string(1, char(' '));
					}
					else
					{
						cout << string(5, char(' '));
					}

					tempB.pop();
				}
				else
				{
					cout << right << setw(rings + 1) << "\xBA";

					if (rings == 3)
					{
						cout << string(rings + 1, char(' '));
					}
					else
					{
						cout << string(rings + 5, char(' '));
					}

				}


				if (i <= tempC.size() && !tempC.empty())
				{
					int space = 0;

					while (space < (rings - tempC.top()))
					{
						cout << " ";
						space++;
					}

					for (int j = 1; j <= tempC.top(); j++)
					{
						cout << "\xFE";
					}

					cout << tempC.top();

					for (int j = 1; j <= tempC.top(); j++)
					{
						cout << "\xFE";
					}

					space = 0;

					while (space < (rings - tempC.top()))
					{
						cout << " ";
						space++;
					}

					if (rings == 3)
					{
						cout << string(1, char(' '));
					}
					else
					{
						cout << string(5, char(' '));
					}

					tempC.pop();
				}
				else
				{
					cout << right << setw(rings + 1) << "\xBA";

					if (rings == 3)
					{
						cout << string(rings + 1, char(' '));
					}
					else
					{
						cout << string(rings + 5, char(' '));
					}
				}

				cout << "\n";
			}
		}else
		{
			
			for (int i = rings; i > 0; i--)
			{
				cout << "\t";

				if (i <= tempA.size() && !tempA.empty())
				{
					cout << "   " << setw(4) << left << tempA.top();

					tempA.pop();
				}
				else
				{
					cout << "   " << setw(4) << left << "\xBA";
				}

				if (i <= tempB.size() && !tempB.empty())
				{
					cout << "    " << setw(4) << left << tempB.top();

					tempB.pop();
				}
				else
				{
					cout << "    " << setw(4) << left << "\xBA";
				}

				if (i <= tempC.size() && !tempC.empty())
				{
					cout << "    " << setw(4) << left << tempC.top();

					tempC.pop();
				}
				else
				{
					cout << "    " << setw(4) << left << "\xBA";
				}
				
				cout << "\n";
			}
		}

		int standLength = rings;

		if (standLength > 9)
		{
			standLength = 3;
		}

		cout << "\t";
		for (int i = 0; i < 3; i++)
		{
			for (int i = 0; i < standLength; i++)
			{
				cout << "\xCD";
			}

			cout << "\xCA";

			for (int i = 0; i < standLength; i++)
			{
				cout << "\xCD";
			}

			if (standLength == 3)
			{
				cout << string(1, char(' '));
			}
			else
			{
				cout << string(5, char(' '));
			}
			
		}

		cout << "\n\t";

		for (int i = 0; i < 3; i++)
		{
			for (int i = 0; i < standLength; i++)
			{
				cout << " ";
			}

			cout << char(65 + i);

			for (int i = 0; i < standLength; i++)
			{
				cout << " ";
			}

			if (standLength == 3)
			{
				cout << string(1, char(' '));
			}
			else
			{
				cout << string(5, char(' '));
			}
		}
	}
			
	

	// Precondition: Towers A and B must both be initialized. Tower A must have at least one disk.
	// Postcondition: Move the top disk from Tower A to Tower B if the move is valid according to the rules.
	void moveAtoB()
	{
		if (!towerA.empty() && !towerB.empty())
		{
			if (towerA.top() < towerB.top())
			{
				towerB.push(towerA.top());
				towerA.pop();
				cout << "\n\tTop disk from peg-A has moved to peg-B.";
				totalMoves++;
			}
			else
				cout << "\n\tERROR: Cannot make the move. Top disk (" << towerA.top() << ") of peg-A, is larger than top disk (" << towerB.top() << ") of peg-B.\n\t       Please choose again.";
		}
		else if (!towerA.empty())
		{
			towerB.push(towerA.top());
			towerA.pop();
			cout << "\n\tTop disk from peg-A has moved to peg-B.";
			totalMoves++;
		}
		else
		{
			cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-A.\n\t       Please choose again";
		}
	}

	// Precondition: Towers B and A must both be initialized. Tower B must have at least one disk.
	// Postcondition: Move the top disk from Tower B to Tower A if the move is valid according to the rules.
	void moveBtoA()
	{
		if (!towerB.empty() && !towerA.empty())
		{
			if (towerB.top() < towerA.top())
			{
				towerA.push(towerB.top());
				towerB.pop();
				cout << "\n\tTop disk from peg-B has moved to peg-A.";
				totalMoves++;
			}
			else
				cout << "\n\tERROR: Cannot make the move. Top disk (" << towerB.top() << ") of peg-B, is larger than top disk (" << towerA.top() << ") of peg-A.\n\t       Please choose again.";
		}
		else if (!towerB.empty())
		{
			towerA.push(towerB.top());
			towerB.pop();
			cout << "\n\tTop disk from peg-B has moved to peg-A.";
			totalMoves++;
		}
		else
		{
			cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-B.\n\t       Please choose again";
		}
	}

	// Precondition: Towers A and C must both be initialized. Tower A must have at least one disk.
	// Postcondition: Move the top disk from Tower A to Tower C if the move is valid according to the rules.
	void moveAtoC()
	{
		if (!towerA.empty() && !towerC.empty())
		{
			if (towerA.top() < towerC.top())
			{
				towerC.push(towerA.top());
				towerA.pop();
				cout << "\n\tTop disk from peg-A has moved to peg-C.";
				totalMoves++;
			}
			else
				cout << "\n\tERROR: Cannot make the move. Top disk (" << towerA.top() << ") of peg-A, is larger than top disk (" << towerC.top() << ") of peg-C.\n\t       Please choose again.";
		}
		else if(!towerA.empty())
		{
			towerC.push(towerA.top());
			towerA.pop();
			cout << "\n\tTop disk from peg-A has moved to peg-C.";
			totalMoves++;
		}
		else
		{
			cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-A.\n\t       Please choose again";
		}
	}


	// Precondition: Towers C and A must both be initialized. Tower C must have at least one disk.
	// Postcondition: Move the top disk from Tower C to Tower A if the move is valid according to the rules.
	void moveCtoA()
	{
		if (!towerC.empty() && !towerA.empty())
		{
			if (towerC.top() < towerA.top())
			{
				towerA.push(towerC.top());
				towerC.pop();
				cout << "\n\tTop disk from peg-C has moved to peg-A.";
				totalMoves++;
			}
			else
				cout << "\n\tERROR: Cannot make the move. Top disk (" << towerC.top() << ") of peg-C, is larger than top disk (" << towerA.top() << ") of peg-A.\n\t       Please choose again.";
		}
		else if (!towerC.empty())
		{
			towerA.push(towerC.top());
			towerC.pop();
			cout << "\n\tTop disk from peg-C has moved to peg-A.";
			totalMoves++;
		}
		else
		{
			cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-C.\n\t       Please choose again";
		}
	}

	// Precondition: Towers B and C must both be initialized. Tower B must have at least one disk.
	// Postcondition: Move the top disk from Tower B to Tower C if the move is valid according to the rules.
	void moveBtoC()
	{
		if (!towerB.empty() && !towerC.empty())
		{
			if (towerB.top() < towerC.top())
			{
				towerC.push(towerB.top());
				towerB.pop();

				cout << "\n\tTop disk from peg-B has moved to peg-C.";
				totalMoves++;
			}
			else
				cout << "\n\tERROR: Cannot make the move. Top disk (" << towerB.top() << ") of peg-B, is larger than top disk (" << towerC.top() << ") of peg-C.\n\t       Please choose again.";
		}
		else if (!towerB.empty())
		{
			towerC.push(towerB.top());
			towerB.pop();
			cout << "\n\tTop disk from peg-B has moved to peg-C.";
			totalMoves++;
		}
		else
			cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-B.\n\t       Please choose again";
	}

	// Precondition: Towers C and B must both be initialized. Tower C must have at least one disk.
	// Postcondition: Move the top disk from Tower C to Tower B if the move is valid according to the rules.
	void moveCtoB()
	{
		if (!towerC.empty() && !towerB.empty())
		{
			if (towerC.top() < towerB.top())
			{
				towerB.push(towerC.top());
				towerC.pop();

				cout << "\n\tTop disk from peg-C has moved to peg-B.";
				totalMoves++;
			}
			else
				cout << "\n\tERROR: Cannot make the move. Top disk (" << towerC.top() << ") of peg-C, is larger than top disk (" << towerB.top() << ") of peg-B.\n\t       Please choose again.";
		}
		else if (!towerC.empty())
		{
			towerB.push(towerC.top());
			towerC.pop();
			cout << "\n\tTop disk from peg-C has moved to peg-B.";
		}
		else
		{
			cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-C.\n\t       Please choose again";
		}
	}

	// Precondition: None.
	// Postcondition: Returns true if both Towers A and B are empty (the player wins); otherwise, return false.
	bool checkWin()
	{
		if (towerA.empty() && towerB.empty())
		{
			
			return true;
		}
		else
			return false;
	}

	// Precondition: None.
	// Postcondition: Resets all towers and ring count to their default values.
	void restartGame()
	{
		rings = 0;
		stack <int> newTower;

		towerA = newTower;
		towerB = newTower;
		towerC = newTower;
		
	}


	// Precondition: None.
	// Postcondition: Returns the total number of moves.
	int getCurrentMoves() const
	{
		return totalMoves;
	}


	// Precondition: None.
	// Postcondition: Starts Tower of Hanoi game, allowing the player to make moves, and solve the puzzle.
	void playGame()
	{
		char option = ' ';
		bool playAgain = true;

		setRings(inputInteger("\n\tEnter the number of ring (1..64) to begin: ", 1, 64));

		do
		{
			displayTower();

			option = inputChar("\n\n\tSelect the top disk from the start peg (A, B, C, or Q-quit): ", static_cast<string>("ABCQ"));
			switch (toupper(option))
			{
			case 'A':
				option = inputChar("\tSelect the end peg (A, B, C or Q-quit) to move the selected disk: ", static_cast<string>("ABCQ"));

				switch (toupper(option))
				{
				case 'B':
					moveAtoB();
					break;
				case 'C':
					moveAtoC();
					break;
				case 'Q':
					break;
				default:
					cout << "\n\tERROR: Cannot make the move. The selected end peg cannot be the same as the selected start peg.";
					cout << "\n\tPlease choose again.";
					break;
				}
				break;
			case 'B':
				option = inputChar("\tSelect the end peg (A, B, C or Q-quit) to move the selected disk: ", static_cast<string>("ABCQ"));
				switch (toupper(option))
				{
				case 'A':
					moveBtoA();
					break;
				case 'C':
					moveBtoC();
					break;
				case 'Q':
					break;
				default:
					cout << "\n\tERROR: Cannot make the move. The selected end peg cannot be the same as the selected start peg.";
					cout << "\n\tPlease choose again.";
					break;
				}
				break;
			case 'C':
				option = inputChar("\tSelect the end peg (A, B, C or Q-quit) to move the selected disk: ", static_cast<string>("ABCQ"));
				switch (toupper(option))
				{
				case 'A':
					moveCtoA();
					break;
				case 'B':
					moveCtoB();
					break;
				case 'Q':
					break;
				default:
					cout << "\n\tERROR: Cannot make the move. The selected end peg cannot be the same as the selected start peg.";
					cout << "\n\tPlease choose again.";
					break;
				}
				break;
			case 'Q':
				return;

			default:
				
				break;

			}
			cout << "\n";

			if (checkWin())
			{
				displayTower();

				cout << "\n\n\tCongratuation! You have solved the game in " << getCurrentMoves() << " moves.";

				if (inputChar("\n\n\tPlay again? (Y-yes) or (N-no) ", static_cast<string>("YN")) == 'Y')
				{
					playAgain = true;
					restartGame();
					setRings(inputInteger("\n\tEnter the number of ring (1..64) to begin: ", 1, 64));
				}
				else
				{
					playAgain = false;
					option = 'Q';
				}
			}

		} while (option != 'Q' && playAgain);

		return;
	}

};


