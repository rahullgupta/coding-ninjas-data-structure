/*
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.
Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.
Illustration :
The following images depict how the deletion has been performed.
Image-I :
Alt txt

Image-II :
Alt txt

Input format :
The first line contains an Integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space.

The second line of each test case contains the integer value of 'POS'. It denotes the position in the linked list from where the node has to be deleted.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Note:
You are not required to print the output, it has already been taken care of. Just implement the function.
Constraints :
1 <= T <= 10^2
0 <= N <= 10^5
POS >= 0

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
10 20 30 40 50 60 -1
7
Sample Output 2 :
4 5 2 6 1 9
10 20 30 40 50 60
*/

/*
#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;
#include "solution.h"

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos;
        cin >> pos;
        head = deleteNode(head, pos);
        print(head);
    }

    return 0;
}
*/

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    int i = 0;
    Node *current = head;
    if (head == NULL)
        return head;
    if (pos == 0)
    {
        head = current->next;
        delete current;
        return head;
    }
    while (i < pos - 1 && current->next != NULL)
    {
        current = current->next;
        i++;
    }
    if (current->next != NULL)
    {
        Node *temp = current->next->next;
        delete current->next;
        current->next = temp;
    }
    return head;
}