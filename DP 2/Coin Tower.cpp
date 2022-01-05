/*
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
*/

/*
#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}
*/

string findWinner(int n, int x, int y)
{
    // Write your code here
    int *dp = new int[n + 1];

    dp[0] = false;
    dp[1] = true;

    for (int i = 2; i <= n; i++)
    {
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 and !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 and !dp[i - y])
            dp[i] = true;
        else
            dp[i] = false;
    }

    if (dp[n])
        return "Beerus";
    else
        return "Whis";
}