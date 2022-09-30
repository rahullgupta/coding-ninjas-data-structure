/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274
*/

/*
#include <iostream>
using namespace std;

#include "solution.h"

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
}
*/

#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

int staircase(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    long long a = 1, b = 1, c = 2;

    for (int i = 0; i <= n - 3; ++i)
    {
        long long d = (a + b + c) % mod;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << staircase(n) << endl;
    }
}
