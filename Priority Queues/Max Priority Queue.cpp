/*
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.
*

/*
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }

        cin >> choice;
    }
}
*/

#include <vector>
class PriorityQueue
{
    // Declare the data members here
    vector<int> pq;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    int getSize()
    {
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }

    void insert(int element)
    {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    int getMax()
    {
        // Implement the getMax() function here
        if (isEmpty())
            return 0;
        return pq[0];
    }

    int removeMax()
    {
        // Implement the removeMax() function here
        if (isEmpty())
            return 0;
        int max = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        while (parentIndex < pq.size())
        {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int maxIndex;
            if (leftChildIndex < pq.size() && rightChildIndex < pq.size())
                maxIndex = (pq[leftChildIndex] >= pq[rightChildIndex]) ? leftChildIndex : rightChildIndex;
            else if (leftChildIndex < pq.size())
                maxIndex = leftChildIndex;
            else
                break;
            if (pq[maxIndex] > pq[parentIndex])
            {
                int temp = pq[maxIndex];
                pq[maxIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
            parentIndex = maxIndex;
        }
        return max;
    }
};