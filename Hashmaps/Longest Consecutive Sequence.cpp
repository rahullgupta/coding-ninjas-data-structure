/*
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of longest consecutive sequence, then just print the starting element.
Constraints :
0 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6
Sample Output 1 :
8 12
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16
*/

/*
#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
*/

#include <unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here
    unordered_map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < n; i++)
        m[arr[i]] = i;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        // Find the starting point for the increasing sequence
        if (m.count(arr[i] - 1) == 0)
        {
            temp.push_back(arr[i]);
            int t = 1;
            while (m.count(arr[i] + t))
            {
                temp.push_back(arr[i] + t);
                t++;
            }
            if (temp.size() > ans.size())
                ans = temp;
        }
    }
    int n1 = ans[0];
    int n2 = ans[ans.size() - 1];
    ans.clear();
    ans.push_back(n1);
    ans.push_back(n2);
    return ans;
}