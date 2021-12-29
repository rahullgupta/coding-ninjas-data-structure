/*
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
The first and only line of output contains either true or false.
Constraints :
Time Limit: 1 second
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
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
    cout << (isBST(root) ? "true" : "false");
}
*/

void isBSTHelperLeft(BinaryTreeNode<int> *root, int *leftmax)
{
    if (root->left != NULL && root->left->data > *leftmax)
        *leftmax = root->left->data;
    if (root->right != NULL && root->right->data > *leftmax)
        *leftmax = root->right->data;
}
void isBSTHelperRight(BinaryTreeNode<int> *root, int *rightmin)
{
    if (root->left != NULL && root->left->data < *rightmin)
        *rightmin = root->left->data;
    if (root->right != NULL && root->right->data < *rightmin)
        *rightmin = root->right->data;
}
bool isBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return false;
    int leftmax, rightmin;
    bool val1, val2;
    if (root->left != NULL)
    {
        val1 = isBST(root->left);
        leftmax = root->left->data;
        isBSTHelperLeft(root->left, &leftmax);
    }
    if (root->right != NULL)
    {
        val2 = isBST(root->right);
        rightmin = root->right->data;
        isBSTHelperRight(root->right, &rightmin);
    }
    if (root->left == NULL && root->right == NULL)
        return true;
    else if (root->left != NULL && root->right == NULL)
    {
        if ((leftmax < root->data) && (root->left->data < root->data) && val1)
            return true;
        else
            return false;
    }
    else if (root->left == NULL && root->right != NULL)
    {
        if ((rightmin >= root->data) && (root->right->data >= root->data) && val2)
            return true;
        else
            return false;
    }
    else
    {
        if ((leftmax < root->data) && (rightmin >= root->data) && (root->left->data) < (root->data) && (root->right->data >= root->data) && val1 && val2)
            return true;
        else
            return false;
    }
}