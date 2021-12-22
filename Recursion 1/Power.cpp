/*
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.

Input format :

Two integers x and n (separated by space)

Output Format :

x^n (i.e. x raise to the power n)

Constraints :

1 <= x <= 30

0 <= n <= 30

Sample Input 1 :

 3 4

Sample Output 1 :

81

Sample Input 2 :

 2 5

Sample Output 2 :

32
*/

/*
#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int x, n;
    cin >> x >> n;

    cout << power(x, n) << endl;
}
*/

int power(int x, int n)
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Return output and don't print it.
       Taking input and printing output is handled automatically.
    */
    if (n == 1)
        return x;
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}