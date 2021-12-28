/*
You have been given a linked list of integers. Your task is to write a function that inserts a node at a given position, 'pos'.
Note:
Assume that the Indexing for the linked list always starts from 0.

If the given position 'pos' is greater than length of linked list, then you should return the same linked list without any change. And if position 'pos' is equal to length of input linked list, then insert the node at the last position.
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space.

The second line of each test case contains two space separated integers, that denote the value of 'pos' and the data to be inserted respectively.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format:
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.
You don't need to print explicitly, it has been taken care of.
Constraints:
1 <= t <= 20
0 <= length of linked list <= 10^4
0 <= pos, data to be inserted <= 2^31 - 1
Time Limit: 1 second
Sample Input 1:
1
3 4 5 2 6 1 9 -1
3 100
Sample Output 1:
3 4 5 100 2 6 1 9
Sample Input 2:
1
3 4 5 2 6 1 9 -1
0 20
Sample Output 2:
20 3 4 5 2 6 1 9
*/

/*
#include <iostream>

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;
#include "solution.h"

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}
*/

Node *insertNode(Node *head, int i, int data)
{
    // Write your code here
    if (head == NULL)
        return head;
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    else if (i == 1)
    {
        Node *newNode = new Node(data);
        Node *temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        return head;
    }
    else
        insertNode(head->next, i - 1, data);
    return head;
}