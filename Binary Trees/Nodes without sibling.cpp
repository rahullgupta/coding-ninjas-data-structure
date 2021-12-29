/*
For a given Binary Tree of type integer, print all the nodes without any siblings.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the node data in a top to down fashion with reference to the root.
Node data in the left subtree will be printed first and then the right subtree.
A single space will separate them all.
 Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
9
Sample Input 2:
2 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
6 7
Explanation of Sample Input 2:
The input tree when represented in a two-dimensional plane, it would look like this:

In respect to the root, node data in the left subtree that satisfy the condition of not having a sibling would be 6, taken in a top-down sequence. Similarly, for the right subtree, 7 is the node data without any sibling.

Since we print the siblings in the left-subtree first and then the siblings from the right subtree, taken in a top-down fashion, we print 6 7.
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
    printNodesWithoutSibling(root);
}
*/

void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;
    if (root->left != NULL && root->right == NULL)
        cout << root->left->data << " ";
    else if (root->left == NULL && root->right != NULL)
        cout << root->right->data << " ";
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}