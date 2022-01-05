/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as :
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

/*
#include <bits/stdc++.h>
using namespace std;

#include "solution.h"

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}
*/

int minCount(int n, int *ans)
{
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n == 0 || n == 1 || n == 2 || n == 3)
        return n;
    if (ans[n] != -1)
        return ans[n];
    int val = n;
    for (int i = 1; (i * i) <= n; i++)
        ans[n] = val = min(val, 1 + minCount(n - i * i, ans));
    return ans[n];
}

int minCount(int n)
{
    // Write your code here
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
        ans[i] = -1;
    return minCount(n, ans);
}