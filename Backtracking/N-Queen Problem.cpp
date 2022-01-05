/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Note: Don't print anything if there isn't any valid configuration.
Input Format:
The first line of input contains an integer, that denotes the value of N.
Output Format :
In the output, you have to print every board configuration in a new line. Every configuration will have N*N board elements printed row wise and are separated by space. The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. Please refer to sample test cases for more clarity.
Constraints :
1 <= N <= 10
Time Limit: 1 second
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
Explanation:
The first and second configuration are shown in the image below. Here, 1 denotes the placement of a queen and 0 denotes an empty cell. Please note that in both the configurations, no pair of queens can kill each other.
*/

#include <bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int col)
{
    for (int i = row - 1; i >= 0; i--)
        if (board[i][col] == 1)
            return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;
    return true;
}

void nQueenHelper(int n, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
        cout << endl;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (isPossible(n, row, j))
            {
                board[row][j] = 1;
                nQueenHelper(n, row + 1);
                board[row][j] = 0;
            }
        }
    }
}

void placeNQueens(int n)
{
    memset(board, 0, 11 * 11 * sizeof(int));
    nQueenHelper(n, 0);
}

int main()
{
    // write your code here
    int n;
    cin >> n;
    placeNQueens(n);
    return 0;
}