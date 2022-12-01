#include <iostream>
using namespace std;

#define n 3

void print_board(int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool is_safe(int board[n][n], int row, int col)
{
    int i, j;
    // row
    for (j = 0; j < n; j++)
        if (board[row][j] == 1)
            return false;
    // col
    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;
    // left upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;
    // right upper diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    // // left lower diagonal
    // for (i = row, j = col; j >= 0 && i < n; i++, j--)
    //     if (board[i][j] == 1)
    //         return false;
    // // right lower diagonal
    // for (i = row, j = col; i < n && j >= 0; i++, j--)
    //     if (board[i][j] == 1)
    //         return false;

    return true;
}

bool n_queen_solver(int board[n][n], int row)
{
    if (row == n)
        return true;
    for (int col = 0; col < n; col++)
    {
        if (is_safe(board, row, col))
        {
            board[row][col] = 1;
            if (n_queen_solver(board, row + 1))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    // cout << "Enter the number of queens: ";
    // cin >> n;
    int board[n][n] = {0};
    if (n_queen_solver(board, 0) == false)
        cout << "Solution does not exist" << endl;
    else
        print_board(board);
    return 0;
}