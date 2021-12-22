/*
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S.
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:
*/

/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
*/

#include <cstring>
void removeX(char input[])
{
    // Write your code here
    int l = strlen(input);
    if (input[0] == 'x')
    {
        for (int i = 0; i < l; i++)
            input[i] = input[i + 1];
        removeX(input);
    }
    else if (input[1] != '\0')
        removeX(input + 1);
    else
        return;
}