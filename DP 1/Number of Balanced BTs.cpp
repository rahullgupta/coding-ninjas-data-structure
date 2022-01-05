/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

/*
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
*/

#define mod 1000000007
int balancedBTs(int n, int *ans)
{
    // Write your code here
    if (n == 1 || n == 0)
        return 1;
    if (ans[n] != -1)
        return ans[n];
    int x = balancedBTs(n - 1, ans);
    int y = balancedBTs(n - 2, ans);
    int val1 = (int)(((long)x * x) % mod);
    int val2 = (int)((2 * (long)x * y) % mod);
    ans[n] = (val1 + val2) % mod;
    return ans[n];
}

int balancedBTs(int n)
{
    // Write your code here
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
        ans[i] = -1;
    return balancedBTs(n, ans);
}