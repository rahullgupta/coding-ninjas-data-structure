/*
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Input format :
String S
Output format :
'true' or 'false'
Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
abb
Sample Output 1 :
true
Sample Input 2 :
abababa
Sample Output 2 :
false
*/

/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
*/

bool checkAB(char input[])
{
    // Write your code here
    static int count = 0;
    if (input[0] == 'a' && count == 0)
        count++;
    if (count == 0)
        return false;
    else
    {
        if (input[0] == 'a' && input[1] == '\0')
            return true;
        else if (input[0] == 'a' && (input[1] == 'a' || (input[1] == 'b' && input[2] == 'b')))
            return checkAB(input + 1);
        else if ((input[0] == 'b' && input[1] == 'b') && input[2] == '\0')
            return true;
        else if ((input[0] == 'b' && input[1] == 'b') && input[2] == 'a')
            return checkAB(input + 2);
        else
            return false;
    }
}