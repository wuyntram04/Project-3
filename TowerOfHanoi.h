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
			
	void setRings(int r)
	{
		rings = r;

		for (int i = r; i > 0; --i)
		{
			towerA.push(i);
		}
	}

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

	bool checkWin()
	{
		if (towerA.empty() && towerB.empty())
		{
			
			return true;
		}
		else
			return false;
	}

	void restartGame()
	{
		rings = 0;
		stack <int> newTower;

		towerA = newTower;
		towerB = newTower;
		towerC = newTower;
		
	}

	~TowerOfHanoi()
	{
		rings = 0;
		stack <int> newTower;

		towerA = newTower;
		towerB = newTower;
		towerC = newTower;
	}

	int getCurrentMoves() const
	{
		return totalMoves;
	}

};

