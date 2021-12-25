/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

/*
#include <iostream>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

void help(string input, string out, vector<string> &str)
{
    if (input.size() == 0)
    {
        str.push_back(out);
        return;
    }
    char c1 = (input[0] - 48) + 96;
    if (input[0] == '0')
        return;
    help(input.substr(1), out + c1, str);
    if (input.size() > 1)
    {
        int d = (input[0] - 48) * 10 + (input[1] - 48);
        if (d > 26)
            return;
        char c2 = 96 + d;
        help(input.substr(2), out + c2, str);
    }
}

void printAllPossibleCodes(string input)
{

    vector<string> str;
    string out = "";
    help(input, out, str);
    for (int i = 0; i < str.size(); i++)
        cout << str[i] << endl;
}