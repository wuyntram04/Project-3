#include <stack>
#pragma once
using namespace std;

class TowerOfHanoi
{
private:
	int rings = 0;

	stack <int> towerA;
	stack <int> towerB;
	stack <int> towerC;

public:

	void displayTower()
	{
		cout << "\n\t" << setw(rings + 1) << "\xBA" << "\n"; // ■ 

		for (int i = 1; i <= rings; i++)
		{
			cout << "\t";
			if (i <= towerA.size())
			{
				int space = 0;

				while (space < (rings - i))
				{
					cout << " ";
					space++;
				}

				for (int j = towerA.top(); j <= i; j++)
				{
					cout << "\xFE";
				}

				cout << i; 

				for (int j = towerA.top(); j <= i; j++)
				{
					cout << "\xFE";
				}

				while (space < (rings - i))
				{
					cout << " ";
					space++;
				}
			}
			else
			{
			//	cout << "\n\t" << setw(rings + 1) << "\xBA" << "\n"; // ■ 
			}


			if (i <= towerB.size())
			{
				int space = 0;

				while (space < (rings - i))
				{
					cout << " ";
					space++;
				}

				for (int j = towerB.top(); j <= i; j++)
				{
					cout << "\xFE";
				}

				cout << i;

				for (int j = towerB.top(); j <= i; j++)
				{
					cout << "\xFE";
				}

			}
			else
			{
				cout << setw(rings + 1) << "\xBA"; // ■ 
			}

			cout << "\n";

		}

		cout << "\t";
		for (int i = 0; i < rings; i++)
		{
			cout << "\xCD";
		}

		cout << "\xCA";

		for (int i = 0; i < rings; i++)
		{
			cout << "\xCD";
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

	

};

