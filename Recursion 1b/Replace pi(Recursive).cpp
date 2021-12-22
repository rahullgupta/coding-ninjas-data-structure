/*
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S.
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50
*/

/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
*/

#include <cstring>
void replacePi(char input[])
{
    // Write your code here
    int l = strlen(input);
    if (input[0] == 'p' && input[1] == 'i')
    {
        for (int j = l; j > 1; j--)
            input[j + 2] = input[j];
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        replacePi(input + 4);
    }
    else if (input[1] != '\0')
        replacePi(input + 1);
    else
        return;
}