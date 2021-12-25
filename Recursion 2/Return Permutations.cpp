/*
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
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
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
*/

#include <string>
using namespace std;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int permute(string a, int l, int r, string output[])
{
    int i;
    static int j = 0, count = 0;
    if (l == r)
    {
        output[j] = a;
        j++;
        count++;
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a[l]), (a[i]));
            permute(a, l + 1, r, output);
            swap((a[l]), (a[i]));
        }
    }
    return count;
}

int returnPermutations(string input, string output[])
{
    int len = input.length() - 1;
    return permute(input, 0, len, output);
}
