#pragma once
#include<iostream>
#include"input.h"
using namespace std;

class n_Queens
{
private:
    int num = 0;
    char** board = nullptr;

    int moves = 0;
    char empty = '_';
    char queen = 'Q';
    int countQueen = 0;
    double totalGames = 0.0;
    double totalTime = 0.0;
    double fastest = 0.0;
    double fastestMoves = 0.0;
    double slowest = 0.0;
    double slowestMoves = 0.0;
    bool win = false;
    
    void allocBoard(int size) {
        num = size;
        board = new char* [num];
        for (int r = 0; r < num; ++r) {
            board[r] = new char[num];
        }
        clearBoard();
    }

    void freeBoard() {
        if (!board) return;
        for (int r = 0; r < num; ++r) delete[] board[r];
        delete[] board;
        board = nullptr;
        num = 0;
    }

    void clearBoard() {
        for (int r = 0; r < num; ++r)
            for (int c = 0; c < num; ++c)
                board[r][c] = empty;
    }

    bool canPlace(int row, int col)
    {
        // check same column
        for (int r = 0; r < num; r++)
            if (board[r][col] == queen)
            {
                cout << "\n\tERROR: conflict with queens in existing column.Try again.";
                return false;
            }

        // check same row
        for (int c = 0; c < num; c++)
            if (board[row][c] == queen)
            {
                cout << "\n\tERROR: conflict with queens in existing row.Try again.";
                return false;
            }

        // check upper-left diagonal
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
            if (board[r][c] == queen) {
                cout << "\n\tERROR: conflict with queens in existing diagnol.Try again.";
                return false;
            }

        // check upper-right diagonal
        for (int r = row, c = col; r >= 0 && c < num; r--, c++)
            if (board[r][c] == queen) {
                cout << "\n\tERROR: conflict with queens in existing diagnol.Try again.";
                return false;
            }

        // check lower-left diagonal
        for (int r = row, c = col; r < num && c >= 0; r++, c--)
            if (board[r][c] == queen) {
                cout << "\n\tERROR: conflict with queens in existing diagnol.Try again.";
                return false;
            }

        // check lower-right diagonal
        for (int r = row, c = col; r < num && c < num; r++, c++)
            if (board[r][c] == queen) {
                cout << "\n\tERROR: conflict with queens in existing diagnol.Try again.";
                return false;
            }

        return true;
    }

public:

    void reset(int size) {
        freeBoard();
        allocBoard(size);
        moves = 0;
        countQueen = 0;
        win = false;
    }

    void placeQueen()
    {
        time_t start = time(nullptr);
        int row = inputInteger("\n\tPosition a queen in the row (1.." + to_string(num) + "): ", 1, num) - 1;
        int col = inputInteger("\n\tPosition a queen in the column (1.." + to_string(num) + "): ", 1, num) - 1;
        

        if (board[row][col] == queen)
        {
            cout << "\n\tERROR: a queen has already placed in the position (row and colume). Try again.\n";
        }
        else if (!canPlace( row, col)) { }
        else
        {
            board[row][col] = queen;
            cout << "\n\tPlaced a queen at (" << row + 1 << ", " << col + 1 << ")\n";
            moves++;
            countQueen++;
        }

        if (countQueen == num)
        {
            cout << "\n\tCongratulation!You have solved " << countQueen << "-Queens in " << moves << " moves.";
            win = true;
        }
       
        cout << "\n";
        displayBoard();

        time_t end = time(nullptr);
        int duration = static_cast<int>(end - start);

       
         updateStats(duration, moves);
        
    }

    void removeQueen()
    {
        int row = inputInteger("\n\tRemove queen from row (1.." + to_string(num) + "): ", 1, num) - 1;
        int col = inputInteger("\n\tRemove queen from column (1.." + to_string(num) + "): ", 1, num) - 1;

        if (board[row][col] == queen) {
            board[row][col] = '_';
            cout << "\n\tRemoved queen at (" << row + 1 << ", " << col + 1 << ")\n";
            moves++;
            countQueen--;

        }
        else
        {
            cout << "\n\tERROR: No queen exists at this position!\n";
        }

        displayBoard();
    }

    void displayBoard() const
    {
        cout << "\n\t" << char(0xC9);
        for (int i = 0; i < num; i++) {
            cout << "\xCD\xCD\xCD";
            if (i < num - 1) cout << char(0xCB);
        }
        cout << char(0xBB);

        for (int r = 0; r < num; r++) {
            cout << "\n\t" << char(0xBA);
            for (int c = 0; c < num; c++) {
                cout << " " << board[r][c] << " ";
                if (c < num - 1) cout << char(0xBA);
            }
            cout << char(0xBA);

            if (r < num - 1) {
                cout << "\n\t" << char(0xCC);
                for (int i = 0; i < num; i++) {
                    cout << "\xCD\xCD\xCD";
                    if (i < num - 1) cout << char(0xCE);
                }
                cout << char(0xB9);
            }
        }

        cout << "\n\t" << char(0xC8);
        for (int i = 0; i < num; i++) {
            cout << "\xCD\xCD\xCD";
            if (i < num - 1) cout << char(0xCA);
        }
        cout << char(0xBC) << endl;
    }

    void updateStats(int secs, int moves) {
        totalGames++;
        totalTime += secs;

        if (fastest == 0.0 || secs < fastest)
        {
            fastest = secs;
            fastestMoves = moves;

        }
        if (secs > slowest)
        {
            slowest = secs;
            slowestMoves = moves;
        }
    }

    void printStats() {
        if (totalGames == 0) {
            cout << "\n\tNo game statistic collected.";
            return;
        }
        double avg = (fastest + slowest) / 2.0;
        cout << "\n\t" << totalGames << (totalGames == 1 ? " game" : " games") << " using Tic-Tac-Toe were played.";
        cout << "\n\t\tThe fastest time was " << fastest << " second(s) in " << fastestMoves << " moves.";
        cout << "\n\t\tThe slowest time was " << slowest << " second(s) in " << slowestMoves << " moves.";
        cout << "\n\t\tThe average time was " << avg << " second(s).";
    }

    void playGame()
    {
        char again = ' ';

        do {

            int num = inputInteger("\n\n\tEnter the board dimension nxn: ", true);
            //reset(size);
            cout << "\n\t" << num << "-Queens\n";

            reset(num);
            //cout << "\n\t" << num << "-Queens\n";
            displayBoard();

            

            // inner loop: keep showing the menu until solved or user returns
            while (!win) 
            {
                cout << "\n\tGame Options: ";
                cout << "\n\t" << string(80, char(205));
                cout << "\n\tA> Place a queen";
                cout << "\n\tB> Remove an existing queen";
                cout << "\n\t" << string(80, char(196));
                cout << "\n\t0> Return";
                cout << "\n\t" << string(80, char(205));

                switch (toupper(inputChar("\n\tOption: ", "AB0"))) {
                case 'A':
                    placeQueen();     // may set win = true
                    break;

                case 'B':
                    removeQueen();
                    break;

                case '0':
                    // abandon this round (no stats recorded)
                    return;
                }
               
            }
            again = toupper(inputChar("\n\n\tPlay again? (Y-yes or N-no): ", "YN"));

            
        } while (again == 'Y');
    }

};


