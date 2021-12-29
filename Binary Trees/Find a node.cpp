/*
For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.
 Input Format:
The first line of each test case contains elements of the first tree in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

The second line of each test case contains the node value you have to find.


For example, the input for the tree depicted in the below image would be:

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1
Explanation:
Level 1:
The root node of the tree is 1

Level 2:
Left child of 1 = 2
Right child of 1 = 3

Level 3:
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4:
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5:
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.
The input ends when all nodes at the last level are null(-1).
Note:
The above format was just to provide clarity on how the input is formed for a given tree.
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format:
The only line of output prints 'true' or 'false'.

The output of each test case should be printed in a separate line.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^5

Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec.
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7
Sample Output 1:
true
Explanation For Output 1:
Clearly, we can see that 7 is present in the tree. So, the output will be true.
Sample Input 2:
2 3 4 -1 -1 -1 -1
10
Sample Output 2:
false
*/

/*
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << ((isNodePresent(root, x)) ? "true" : "false");
}
*/

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    // Write your code here
    if (root == NULL)
        return false;
    if (root->left != NULL)
    {
        bool val = isNodePresent(root->left, x);
        if (val == true)
            return true;
    }
    if (root->right != NULL)
    {
        bool val = isNodePresent(root->right, x);
        if (val == true)
            return true;
    }
    if (root->data == x)
        return true;
    else
        return false;
}