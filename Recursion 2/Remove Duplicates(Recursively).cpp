/*
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*/

/*
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
*/

#include <cstring>
void removeConsecutiveDuplicates(char *input)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given string itself.
     * No need to return or print anything
     * Taking input and printing output is handled automatically.
     */
    int l = strlen(input);
    if (input[1] != '\0')
    {
        int i;
        for (i = 1; i < l; i++)
            if (input[i] != input[0])
                break;
        for (int j = 1; j < l; j++)
            input[j] = input[j + i - 1];
        if (input[1] != '\0')
            removeConsecutiveDuplicates(input + 1);
        else
            return;
    }
    else
        return;
}