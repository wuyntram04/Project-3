using namespace std;

#pragma once
class TicTacToe
{
private:
	char player1 = 'X';
	char player2 = 'O';
	int row = 0;
	int col = 0;
	char board[3][3] = 
		{
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '} 
		};
	int totalPlaces = 9;
public:

	void displayBoard() const;
	bool setPos(char player, int, int);
	void AI();
	int checkPossibleWinMove(int, int) const;
	bool checkCurrentWin(char player);
};

bool TicTacToe::setPos(char player, int r, int c)
{
	row = r;
	col = c;

	if(row < 0 || col < 0)
	{
		return false;
	}

	if (board[r][c] != player1 && board[r][c] != player2)
	{
		board[r][c] = player;
		return true;
	}
	return false;
}

void TicTacToe::displayBoard() const
{
	cout << "\n\t" << board[0][0] << "  | " << board[0][1] << " |  " << board[0][2];
	cout << "\n\t---+---+---"; 
	cout << "\n\t" << board[1][0] << "  | " << board[1][1] << " |  " << board[1][2];
	cout << "\n\t---+---+---";
	cout << "\n\t" << board[2][0] << "  | " << board[2][1] << " |  " << board[2][2];
	cout << "\n\n";
}

void TicTacToe::AI()
{
	int mostWinMove = 0;
	int winRow = 0;
	int winCol = 0;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (board[r][c] != player1 && board[r][c] != player2)
			{
				 int currentWinMove = checkPossibleWinMove(r, c);
				 
				 if (currentWinMove > mostWinMove)
				 {
					 mostWinMove = currentWinMove;
					 winRow = r;
					 winCol = c;
				 }
			}
		}
	}
	setPos(player2, winRow, winCol);
}

int TicTacToe::checkPossibleWinMove(int r, int c) const
{
	int possibleWin = 0;
	int possibleBlockCol = 0;
	int possibleBlockRow = 0;

	for (int i = 0; i < 3; i++)
	{

		if (board[r][i] != player1)
		{
			possibleWin += 1;
		}
		
		if (board[r][i] == player2)
		{
			possibleWin += 1;
		}

		if (board[r][i] == player1)
		{
			possibleWin -= 1;
			possibleBlockRow += 1;
		}

		if (board[i][c] != player1)
		{
			possibleWin += 1;
		}
		
		if (board[i][c] == player2)
		{
			possibleWin += 1;
		}

		if (board[i][c] == player1)
		{
			possibleWin -= 1;
			possibleBlockCol += 1;
		}
	
		if(possibleBlockRow > 1 || possibleBlockCol > 1)
		{
			possibleWin += 5;
		}

	}

	int orderNumber = (r * 3) + c;

	if (orderNumber % 2 == 0)  // check diagonal
	{
		if (board[0][0] != player1 && board[1][1] != player1 && board[2][2] != player1)
		{
			possibleWin += 1;
		}

		if (board[2][0] != player1 && board[1][1] != player1 && board[0][2] != player1)
		{
			possibleWin += 1;
		}
	} 

	return possibleWin;
} 

bool TicTacToe::checkCurrentWin(char player)
{
	int rowWin = 0;
	int colWin = 0;

	for (int i = 0; i < 3; i++)
	{
		if (board[row][i] == player)
		{
			rowWin += 1;
		}

		if (board[i][col] == player)
		{
			colWin += 1;
		}
	}

	if (rowWin == 3 || colWin == 3)
	{
		return true;
	}
	int orderNumber = (row * 3) + col;

	if (orderNumber % 2 == 0)  // check diagonal
	{
		if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		{
			return true;
		}

		if (board[2][0] != player1 && board[1][1] != player1 && board[0][2] != player1)
		{
			return true;
		}
	}

	return false;
	
}