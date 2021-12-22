/*
Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
Input Format :
Integer N
Output Format :
Number of zeros in N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
0
Sample Output 1 :
1
Sample Input 2 :
00010204
Sample Output 2 :
2
Explanation for Sample Output 2 :
Even though "00010204" has 5 zeros, the output would still be 2 because when you convert it to an integer, it becomes 10204.
Sample Input 3 :
708000
Sample Output 3 :
4
*/

/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
*/

int countZeros(int n)
{
    // Write your code here
    if (n % 10 == 0 && n / 10 != 0)
        return 1 + countZeros(n / 10);
    else if (n / 10 != 0)
        return countZeros(n / 10);
    else if (n % 10 == 0 && n / 10 == 0)
        return 1;
    else
        return 0;
}