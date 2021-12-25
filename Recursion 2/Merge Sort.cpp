/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5
*/

/*
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
*/

void merge(int input[], int size, int mid)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = mid + 1;
    int n2 = size - mid - 1;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = input[i];
    for (int j = 0; j < n2; j++)
        M[j] = input[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            input[k] = L[i];
            i++;
        }
        else
        {
            input[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        input[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        input[k] = M[j];
        j++;
        k++;
    }
}
void mergeSort(int input[], int size)
{
    // Write your code here
    int si = 0, ei = size - 1;
    int mid = (si + ei) / 2;
    if (si >= ei)
        return;
    else
    {
        mergeSort(input, mid + 1);
        mergeSort(input + mid + 1, size - mid - 1);
        merge(input, size, mid);
    }
}
