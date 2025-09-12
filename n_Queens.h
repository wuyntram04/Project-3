#pragma once
#include<iostream>
#include"input.h"
#include<iomanip>
#include <map>

using namespace std;

struct Stats
{
    int totalGames = 0;
    double totalTime = 0.0;
    double fastest = 0.0;
    int fastestMoves = 0;
    double slowest = 0.0;
    int slowestMoves = 0;
};

map<int, Stats> statsBySize;

class n_Queens
{
private:
    int num = 0;
    char** board = nullptr;

    int moves = 0;
    int roundMoves = 0;
    char empty = '_';
    char queen = 'Q';
    int countQueen = 0;
   /* double totalGames = 0.0;
    double totalTime = 0.0;
    double fastest = 0.0;
    double fastestMoves = 0.0;
    double slowest = 0.0;
    double slowestMoves = 0.0;*/
    bool win = false;

    void allocBoard(int size)
    {
        num = size;
        board = new char* [num];
        for (int r = 0; r < num; ++r) 
        {
            board[r] = new char[num];
        }
        clearBoard();
    }

    void freeBoard()
    {
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

    void reset(int size) 
    {
        freeBoard();
        allocBoard(size);
        moves = 0;
        roundMoves = 0;
        countQueen = 0;
        win = false;
    }

    void placeQueen()
    {
        int row = inputInteger("\n\tPosition a queen in the row (1.." + to_string(num) + "): ", 1, num) - 1;
        int col = inputInteger("\n\tPosition a queen in the column (1.." + to_string(num) + "): ", 1, num) - 1;

        if (board[row][col] == queen)
        {
            cout << "\n\tERROR: a queen has already placed here.\n";
        }
        else if (!canPlace(row, col))
        {
            cout << "\n\tERROR: conflict with existing queen.\n";
        }
        else
        {
            board[row][col] = queen;
            cout << "\n\tPlaced a queen at (" << row + 1 << ", " << col + 1 << ")";
            moves++;
            roundMoves++;   // count this round’s step
            countQueen++;
        }

        if (countQueen == num)
        {
            cout << "\n\tCongratulations! You solved " << num
                << "-Queens in " << roundMoves << " moves.";
            win = true;
        }

        displayBoard();
    }

    void removeQueen()
    {
        int row = inputInteger("\n\tRemove queen from row (1.." + to_string(num) + "): ", 1, num) - 1;
        int col = inputInteger("\n\tRemove queen from column (1.." + to_string(num) + "): ", 1, num) - 1;

        if (board[row][col] == queen) {
            board[row][col] = empty;
            cout << "\n\tRemoved queen at (" << row + 1 << ", " << col + 1 << ")";
            moves++;
            roundMoves++;   // also count removing as a step
            countQueen--;
        }
        else {
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

    void updateStats(int size, int secs, int roundMoves)
    {
        Stats& st = statsBySize[size];
        st.totalGames++;
        st.totalTime += secs;

        if (st.fastest == 0.0 || secs < st.fastest) {
            st.fastest = secs;
            st.fastestMoves = roundMoves;
        }
        if (secs > st.slowest) {
            st.slowest = secs;
            st.slowestMoves = roundMoves;
        }
    }

    void printStats() {
        if (statsBySize.empty()) {
            cout << "\n\tNo game statistics collected.";
            return;
        }

        for (auto& entry : statsBySize)
        {
            int size = entry.first;
            const Stats& st = entry.second;

            cout << "\n\t" << st.totalGames
                << (st.totalGames == 1 ? " game" : " games")
                << " using " << size << " queens was played.";

            cout << "\n\t\tThe fastest time was " << st.fastest
                << " second(s) in " << st.fastestMoves << " moves.";
            cout << "\n\t\tThe slowest time was " << st.slowest
                << " second(s) in " << st.slowestMoves << " moves.";
            cout << "\n\t\tThe average time was "
                << fixed << setprecision(1) << (st.totalTime / st.totalGames) << " second(s).";
        }
    }

    void playGame()
    {
        statsBySize.clear();

        char again = ' ';

        do {
            int num = inputInteger("\n\n\tEnter the board dimension nxn: ", true);
            cout << "\n\t" << num << "-Queens\n";

            reset(num);
            displayBoard();

            time_t startTime = time(nullptr);

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
                case 'A': placeQueen(); break;
                case 'B': removeQueen(); break;
                case '0': return;
                }
            }

            if (win) {
                int duration = static_cast<int>(difftime(time(nullptr), startTime));
                updateStats(num, duration, roundMoves);
            }

            // prepare for next game
            win = false;

            again = toupper(inputChar("\n\n\tPlay again? (Y-yes or N-no): ", "YN"));

        } while (again == 'Y');

        printStats();
    }

};

