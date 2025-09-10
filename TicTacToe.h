#pragma once
#include<iostream>
#include"input.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
class TicTacToe
{
private:
    static const int row = 3;
    static const int column = 3;
	char board[row][column];
    const char human = 'X';
    const char computer = 'O';
    char currentPlayer = human;
    bool isEmpty(int r, int c) const {
        return board[r][c] != 'X' && board[r][c] != 'O';
    }
public: 
    TicTacToe() {
        // initialize 
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < column; c++) {
                board[r][c] = ' ';
            }
        }
    }

    void displayBoard() {
        cout << "\n\n\t\tTic-Tac-Toe";
        // top border
        cout << "\n\t\t\xC9"; // ╔
        for (int c = 0; c < column; c++) {
            cout << "\xCD\xCD\xCD"; // ═══
            if (c < column - 1) cout << "\xCB"; // ╦ (top join)
        }
        cout << "\xBB" << endl; // ╗

        for (int r = 0; r < row; r++) {
            // content row
            cout << "\t\t\xBA"; // ║
            for (int c = 0; c < column; c++) {
                cout << " " << board[r][c] << " ";
                cout << "\xBA"; // ║
            }
            cout << endl;

            // middle or bottom separator
            if (r < row - 1) {
                cout << "\t\t\xCC"; // ╠
                for (int c = 0; c < column; c++) {
                    cout << "\xCD\xCD\xCD"; // ═══
                    if (c < column - 1) cout << "\xCE"; // ╬
                }
                cout << "\xB9" << endl; // ╣
            }
        }

        // bottom border
        cout << "\t\t\xC8"; // ╚
        for (int c = 0; c < column; c++) {
            cout << "\xCD\xCD\xCD"; // ═══
            if (c < column - 1) cout << "\xCA"; // ╩
        }
        cout << "\xBC" << endl; // ╝
    
    }

    void playGame() {
        auto start = steady_clock::now();
        int moves = 0;
        displayBoard();
        while (true) {
            displayBoard();

            if (currentPlayer == human)
            {
                cout << "\n\tHUMAN moves...";
                int r = inputInteger("\n\n\t\tEnter the board's row # (1..3) or 0 to forfeit:", 0, 3);
                if (r == 0)
                {
                    cout << "\n\tYou forfeited the game. Therefore, Dumb AI has won.";
                    break;
                }

                int c = inputInteger("\n\t\tEnter the board's column # (1..3) or 0 to forfeit:", 0, 3);
                if (c == 0 )
                {
                    cout << "\n\tYou forfeited the game. Therefore, Dumb AI has won.";
                    break;
                }

                r--;
                c--;

                if (!isEmpty(r,c)) {
                    cout << "\n\tERROR: Illegal move. The square has already owned. Please re-specify.\n";
                    continue; // same player retries
                }

                board[r][c] = human;
                moves++;
                if(endOfTurn(human, moves)) break;
                currentPlayer = computer;

            }
            else 
            {
                cout << "\n\tDumb AI moves...";

                bool placed = false;
                for (int i = 0; i < row && !placed; ++i)
                {
                    for (int j = 0; j < column && !placed; ++j)
                    {
                        if (isEmpty(i,j)) 
                        {
                            board[i][j] = computer;
                            placed = true;
                        }
                    }
                        
                }

                if (!placed) 
                { 
                    displayBoard(); 
                    cout << "\n\tIt's a draw.\n"; 
                    break; 
                }

                moves++;

                if (endOfTurn(computer, moves)) break;

                currentPlayer = human;
            }         
        }

        auto end = steady_clock::now();     // record game end time
        auto duration = duration_cast<seconds>(end - start).count();

       
        
    }

    bool checkWin(char p) 
    {
        // check row
        for (int i = 0; i < row; i++)
        {
            bool winRow = true;
            for (int j = 0; j < column; j++)
            {
                if (board[i][j] != p)
                {
                    winRow = false;
                    break;
                }
            }
            if (winRow) return true;
        }

        // check column
        for (int j = 0; j < column; j++)
        {
            bool winCol = true;
            for (int i = 0; i < row; i++)
            {
                if (board[i][j] != p) 
                {
                    winCol = false;
                    break;
                }
            }
            if (winCol) return true;
        }

        // check Diagonal 
        if (row == column) {
            bool winDiag1 = true;
            bool winDiag2 = true;
            for (int i = 0; i < row; i++)
            {
                if (board[i][i] != p)
                {
                    winDiag1 = false;
                }
                if (board[i][column - 1 - i] != p)
                {
                    winDiag2 = false;
                }
            }
            if (winDiag1 || winDiag2) return true;
        }

        return false; // no win found

        
    }

    bool endOfTurn(char played, int moves) {
        if (checkWin(played)) {
            displayBoard();
            if (played == human)
            {
                cout << "\n\tHuman wins.\n";
            }
            else if (played == computer)
            {
                cout << "\n\tDUMB AI wins.\n";
            }
            return true; // game over
        }
        if (moves == row * column) {
            displayBoard();
            cout << "\n\tIt's a draw.\n";
            return true; // game over
        }
        return false; // keep playing
    }

};

