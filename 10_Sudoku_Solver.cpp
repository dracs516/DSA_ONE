#include <iostream>
using namespace std;

#define n 9

void print_board(int board[n][n])
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool is_safe(int board[n][n], int row, int col, int num)
{
    int i, j;
    // row
    for (j = 0; j < 9; j++)
        if (board[row][j] == num)
            return false;
    // col
    for (i = 0; i < 9; i++)
        if (board[i][col] == num)
            return false;
    // 3x3 block
    int blockRow = row - row % 3;
    int blockCol = col - col % 3;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[blockRow + i][blockCol + j] == num)
                return false;
    return true;
}

bool sudoku_solver(int board[n][n])
{
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;

                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
        {
            break;
        }
    }

    // isEmpty is working opposite. true means no empty spaces left
    if (isEmpty)
    {
        return true;
    }

    for (int num = 1; num <= n; num++)
    {
        if (is_safe(board, row, col, num))
        {
            board[row][col] = num;
            if (sudoku_solver(board))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

bool check_validity(int board[9][9], int row, int col)
{
    int i, j;
    // col
    for (j = 0; j < 9; j++)
    {
        if (board[row][col] != 0)
        {
            if (j == col)
                continue;
            if (board[row][col] == board[row][j])
            {
                cout << "Same in col for board[" << row << "][" << col << "]: " << board[row][col] << " with board[" << row << "][" << j << "]" << endl;
                return false;
            }
        }
    }
    // row
    for (i = 0; i < 9; i++)
    {
        if (board[row][col] != 0)
        {
            if (i == row)
                continue;
            if (board[row][col] == board[i][col])
            {
                cout << "Same in row for board[" << row << "][" << col << "]: " << board[row][col] << " with board[" << i << "][" << col << "]" << endl;
                return false;
            }
        }
    }
    // 3x3 block
    int blockRow = row - row % 3;
    int blockCol = col - col % 3;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[row][col] != 0)
            {
                if (row == blockRow + i && col == blockCol + j)
                    continue;
                if (i == row || j == col)
                    continue;
                if (board[row][col] == board[blockRow + i][blockCol + j])
                {
                    cout << "Same in 3x3 block for board[" << row << "][" << col << "]: " << board[row][col] << " with: board[" << blockRow + i << "][" << blockCol + j << "]" << endl;
                    return false;
                }
            }
        }
    }
    return true;
}

bool is_valid(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!check_validity(board, i, j))
                return false;
        }
    }
    return true;
}

int main()
{
    int board[9][9];
    cout << "Enter the board: " << endl;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    if (is_valid(board))
    {

        if (sudoku_solver(board))
            print_board(board);
        else
            cout << "No solution exists for the given board" << endl;
    }
    else
        cout << "No solution exists for the given board" << endl;
    return 0;
}