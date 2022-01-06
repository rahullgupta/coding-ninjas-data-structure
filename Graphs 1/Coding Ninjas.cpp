/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix.
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/

/*
#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}
*/

bool checker(vector<vector<char>> &arr, int n, int m, int i, int j, string s, bool **visited)
{

    if (s.length() == 0)
    {
        return true;
    }
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return false;
    }
    int row_array[] = {i - 1, i, i + 1};
    int col_array[] = {j - 1, j, j + 1};
    for (int p = 0; p < 3; p++)
    {
        for (int q = 0; q < 3; q++)
        {
            if (row_array[p] == i && col_array[q] == j)
            {
                continue;
            }

            int row = row_array[p];
            int col = col_array[q];
            if (row < 0 || col < 0 || row >= n || col >= m)
            {
                continue;
            }
            if (arr[row][col] == s[0] && !visited[row][col])
            {
                visited[row][col] = true;
                bool checked = checker(arr, n, m, row, col, s.substr(1), visited);
                if (checked)
                {
                    return checked;
                }
                else
                {
                    visited[row][col] = false;
                }
            }
        }
    }
    return false;
}
bool hasPath(vector<vector<char>> &Graph, int n, int m)
{
    // Write your code here.
    string str = "CODINGNINJA";

    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Graph[i][j] == 'C')
            {
                if (checker(Graph, n, m, i, j, "ODINGNINJA", visited))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}