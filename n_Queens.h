#pragma once
#include<iostream>
using namespace std;

class n_Queens
{
   
public:
    char queen = 'Q';
    // Place a queen (only if valid)
    void placeQueen(int num, char** board)
    {
        int row = inputInteger("\n\tPosition a queen in the row (1.." + to_string(num) + "): ", 1, num) - 1;
        int col = inputInteger("\n\tPosition a queen in the column (1.." + to_string(num) + "): ", 1, num) - 1;

        if (board[row][col] == queen)
        {
            cout << "\n\tERROR: A queen already exists at this position!\n";
        }
        else if (!canPlace(num, board, row, col)) 
        {
            cout << "\n\tERROR: Cannot place a queen at (" << row + 1 << ", " << col + 1
                << ") because it conflicts with another queen!\n";
        }
        else
        {
            board[row][col] = queen;
            cout << "\n\tPlaced a queen at (" << row + 1 << ", " << col + 1 << ")\n";
        }

        displayBoard(num, board);
    }

    // Remove a queen
    void removeQueen(int num, char** board)
    {
        int row = inputInteger("\n\tRemove queen from row (1.." + to_string(num) + "): ", 1, num) - 1;
        int col = inputInteger("\n\tRemove queen from column (1.." + to_string(num) + "): ", 1, num) - 1;

        if (board[row][col] == queen) {
            board[row][col] = '_';
            cout << "\n\tRemoved queen at (" << row + 1 << ", " << col + 1 << ")\n";
        }
        else 
        {
            cout << "\n\tERROR: No queen exists at this position!\n";
        }

        displayBoard(num, board);
    }


    // Display the board with borders
    void displayBoard(int n, char** board)
    {
        cout << "\n\t" << char(0xC9);
        for (int i = 0; i < n; i++) {
            cout << "\xCD\xCD\xCD";
            if (i < n - 1) cout << char(0xCB);
        }
        cout << char(0xBB);

        for (int r = 0; r < n; r++) {
            cout << "\n\t" << char(0xBA);
            for (int c = 0; c < n; c++) {
                cout << " " << board[r][c] << " ";
                if (c < n - 1) cout << char(0xBA);
            }
            cout << char(0xBA);

            if (r < n - 1) {
                cout << "\n\t" << char(0xCC);
                for (int i = 0; i < n; i++) {
                    cout << "\xCD\xCD\xCD";
                    if (i < n - 1) cout << char(0xCE);
                }
                cout << char(0xB9);
            }
        }

        cout << "\n\t" << char(0xC8);
        for (int i = 0; i < n; i++) {
            cout << "\xCD\xCD\xCD";
            if (i < n - 1) cout << char(0xCA);
        }
        cout << char(0xBC) << endl;
    }

    bool canPlace(int num, char** board, int row, int col)
    {
        // check same column
        for (int r = 0; r < num; r++)
            if (board[r][col] == queen) return false;

        // check same row
        for (int c = 0; c < num; c++)
            if (board[row][c] == queen) return false;

        // check upper-left diagonal
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
            if (board[r][c] == queen) return false;

        // check upper-right diagonal
        for (int r = row, c = col; r >= 0 && c < num; r--, c++)
            if (board[r][c] == queen) return false;

        // check lower-left diagonal
        for (int r = row, c = col; r < num && c >= 0; r++, c--)
            if (board[r][c] == queen) return false;

        // check lower-right diagonal
        for (int r = row, c = col; r < num && c < num; r++, c++)
            if (board[r][c] == queen) return false;

        return true; // safe spot
    }

};

