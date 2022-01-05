/*
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1:
10
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897
*/

/*

*/

#include <bits/stdc++.h>
int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    // Write your code here
    unordered_map<int, int> m;
    int length = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0 && length == 0)
            length = 1;
        if (sum == 0)
            length = i + 1;
        if (m.count(sum) > 0)
            length = max(length, i - m[sum]);
        else
            m[sum] = i;
    }
    return length;
}