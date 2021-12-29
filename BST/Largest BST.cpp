/*
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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
    cout << largestBSTSubtree(root);
    delete root;
}
*/

#include <climits>
#include <cmath>
class Pair
{

public:
    int minimum;
    int maximum;
    bool bst;
    int height;
};
Pair BST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair obj;
        obj.minimum = INT_MAX;
        obj.maximum = INT_MIN;
        obj.bst = true;
        obj.height = 0;
        return obj;
    }

    Pair left = BST(root->left);
    Pair right = BST(root->right);

    int minimum = min(root->data, min(left.minimum, right.minimum));
    int maximum = max(root->data, max(left.maximum, right.maximum));
    bool isBSTfinal = (root->data > left.maximum) && (root->data < right.minimum) && left.bst && right.bst;

    Pair obj;
    obj.minimum = minimum;
    obj.maximum = maximum;
    obj.bst = isBSTfinal;
    if (isBSTfinal)
    {
        obj.height = 1 + max(left.height, right.height);
    }
    else
        obj.height = max(left.height, right.height);
    return obj;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    // Write your code here
    return BST(root).height;
}