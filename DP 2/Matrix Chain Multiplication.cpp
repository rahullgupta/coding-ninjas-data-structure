/*
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format:
The first line of input contains an integer, that denotes the value of n. The following line contains n+1 integers, that denote the value of elements of array p[].
Output Format:
The first and only line of output prints the minimum number of multiplication needed.
Constraints :
1 <= n <= 100
Time limit: 1 second
Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000
Sample Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000.
*/

/*
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}
*/

#include <climits>
#include <vector>
int matrixChainMultiplication(vector<vector<int>> &dp, int *p, int s, int e)
{
    if ((e - s) == 1)
        return 0;

    if (dp[s][e])
        return dp[s][e];

    int ans = INT_MAX;
    for (int k = s + 1; k < e; k++)
    {
        int temp = matrixChainMultiplication(dp, p, s, k) + matrixChainMultiplication(dp, p, k, e) + p[s] * p[k] * p[e];
        ans = min(ans, temp);
    }
    dp[s][e] = ans;
    return ans;
}
int matrixChainMultiplication(int *arr, int n)
{
    // Write your code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int ans = matrixChainMultiplication(dp, arr, 0, n);
    return ans;
}