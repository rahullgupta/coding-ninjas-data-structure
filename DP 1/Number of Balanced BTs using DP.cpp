/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
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
int balancedBTs(int n)
{
    // Write your code here
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int val1 = (int)(((long)ans[i - 1] * ans[i - 1]) % mod);
        int val2 = (int)((2 * (long)ans[i - 1] * ans[i - 2]) % mod);
        ans[i] = (val1 + val2) % mod;
    }
    return ans[n];
}