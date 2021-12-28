/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
40
*/

/*
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

#include "solution.h"

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}
*/

void getSecondLargest(TreeNode<int> *root, TreeNode<int> **secondLargestNode, TreeNode<int> **largestNode)
{
    if (*largestNode == NULL)
        *largestNode = root;
    else if (*secondLargestNode == NULL && (root->data) < ((*largestNode)->data))
        *secondLargestNode = root;
    else if ((root->data) > ((*largestNode)->data))
    {
        *secondLargestNode = *largestNode;
        *largestNode = root;
    }
    else if ((root->data) < ((*largestNode)->data) && (root->data) > ((*secondLargestNode)->data))
        *secondLargestNode = root;
    for (int i = 0; i < root->children.size(); i++)
        getSecondLargest(root->children[i], secondLargestNode, largestNode);
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL || root->children.size() == 0)
        return NULL;
    TreeNode<int> *secondLargestNode = NULL;
    TreeNode<int> *largestNode = NULL;
    getSecondLargest(root, &secondLargestNode, &largestNode);
    return secondLargestNode;
}