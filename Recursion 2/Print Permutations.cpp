/*
Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line
Note:
You do not need to print anything, it has already been taken care of. Just implement the function.
Constraint:
1<=length of STR<=8
Time Limit: 1sec
Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba
*/

/*
#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
*/

#include <iostream>
#include <string>
using namespace std;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(string a, int l, int r)
{
    int i;
    if (l == r)
        cout << a << endl;
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a[l]), (a[i]));
            permute(a, l + 1, r);
            swap((a[l]), (a[i]));
        }
    }
}
void printPermutations(string input)
{
    int len = input.length() - 1;
    permute(input, 0, len);
}