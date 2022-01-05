/*
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
Input format:
The first and only line of input contains a string, that denotes the value of S.
Output format :
The first and only line of output contains the updated string, as described in the task.
Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

/*
#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
*/

#include <unordered_map>
string uniqueChar(string str)
{
    // Write your code here
    string s;
    unordered_map<char, int> m;
    for (int i = 0; i < str.length(); i++)
    {
        if (m.count(str[i]) == 0)
        {
            m[str[i]]++;
            s += str[i];
        }
    }
    return s;
}