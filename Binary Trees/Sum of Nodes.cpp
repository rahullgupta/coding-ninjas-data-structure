/*
For a given Binary Tree of integers, find and return the sum of all the nodes data.
Example:
                        10
                      /      \
                    20      30
                   /    \
                 40    50

When we sum up all the nodes data together, [10, 20, 30, 40 50] we get 150. Hence, the output will be 150.
 Input Format:
The first and the only line of input will contain the nodes data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The first and the only line of output prints the sum of all the nodes data present in the binary tree.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
2 3 4 6 -1 -1 -1 -1 -1
Sample Output 1:
 15
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
 28
*/

/*
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << getSum(root);
}
*/

int getSum(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return 0;
    int sum = 0;
    if (root->left != NULL)
        sum = sum + getSum(root->left);
    if (root->right != NULL)
        sum = sum + getSum(root->right);
    sum = sum + root->data;
    return sum;
}