/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board.
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.
Output Format :
Print true if there is a cycle in the board, else print false.
Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true
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

    cout << (hasCycle(board, n, m) ? "true" : "false");
}
*/

bool checker(vector<vector<char>> &arr, int n, int m, int i, int j, bool **visited, char current_character)
{
    int condition_up = 0;
    if (i - 1 > 0)
    {
        condition_up = (int)visited[i - 1][j];
    }
    int condition_down = 0;
    if (i + 1 < n - 1)
    {
        condition_down = (int)visited[i + 1][j];
    }
    int condition_right = 0;
    if (j < m + 1)
    {
        condition_right = (int)visited[i][j + 1];
    }
    int condition_left = 0;
    if (j > 0)
    {
        condition_left = (int)visited[i][j - 1];
    }
    int sum = condition_up + condition_down + condition_right + condition_left;
    if (sum == 2)
    {
        return true;
    }

    //////////////////////////////everything above this is a base case.
    bool check = false;
    if (i > 0 && arr[i - 1][j] == current_character && !visited[i - 1][j]) // up
    {
        visited[i - 1][j] = true;
        if (checker(arr, n, m, i - 1, j, visited, current_character))
        {
            check = true;
        }
        else
        {
            visited[i - 1][j] = false;
        }
    }

    if (j > 0 && arr[i][j - 1] == current_character && !visited[i][j - 1]) // left
    {
        visited[i][j - 1] = true;
        if (checker(arr, n, m, i, j - 1, visited, current_character))
        {
            check = true;
        }
        else
        {
            visited[i][j - 1] = false;
        }
    }

    if (i < n - 1 && arr[i + 1][j] == current_character && !visited[i + 1][j]) // down
    {
        visited[i + 1][j] = true;
        if (checker(arr, n, m, i + 1, j, visited, current_character))
        {
            check = true;
        }
        else
        {
            visited[i + 1][j] = false;
        }
    }

    if (j < m - 1 && arr[i][j + 1] == current_character && !visited[i][j + 1]) // right
    {
        visited[i][j + 1] = true;
        if (checker(arr, n, m, i, j + 1, visited, current_character))
        {
            check = true;
        }
        else
        {
            visited[i][j + 1] = false;
        }
    }
    return check;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{
    // Write your code here.
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
            if (checker(board, n, m, i, j, visited, board[i][j]))
            {
                return 1;
            }
        }
    }
    return 0;
}