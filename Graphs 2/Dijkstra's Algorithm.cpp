/*
/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

/*
Time complexity of this code is (E+V)log V = Elog V, done using priority queue and adjacency list instead of adjacency matrix

#include <iostream>
#include <climits>
using namespace std;

class AdjacencyListNode {
public:
    long destination;
    long weight;
    AdjacencyListNode* next;
    AdjacencyListNode(long destination, long weight)
    {
        this -> destination = destination;
        this -> weight = weight;
        next = NULL;
    }
};

class AdjacencyList {
public:
    AdjacencyListNode* head;
};

class Graph {
public:
    long v;
    AdjacencyList* array;
    Graph(long v)
    {
        this -> v = v;
        this -> array = new AdjacencyList[v];
        for (long i = 0; i < v; ++i)
            array[i].head = NULL;
    }
    void addEdge(long source, long destination, long weight)
    {
        AdjacencyListNode* newNode = new AdjacencyListNode(destination, weight);
        newNode->next = array[source].head;
        array[source].head = newNode;

        newNode = new AdjacencyListNode(source, weight);
        newNode->next = array[destination].head;
        array[destination].head = newNode;
    }
};

class MinHeapNode {
public:
    long v;
    long distance;
    MinHeapNode(long v, long distance)
    {
        this -> v = v;
        this -> distance = distance;
    }
};

class MinHeap {
public:
    long size;
    long capacity;
    long* pos;
    MinHeapNode** array;
    MinHeap(long capacity)
    {
        this -> pos = new long[capacity];
        this -> size = 0;
        this -> capacity = capacity;
        this -> array = new MinHeapNode*[capacity];
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b)
    {
        MinHeapNode *t = *a;
        *a = *b;
        *b = t;
    }

    MinHeapNode* getMin()
    {
        if(isEmpty())
            return NULL;

        MinHeapNode* root = array[0];

        MinHeapNode* lastNode = array[size - 1];

        array[0] = lastNode;

        pos[root -> v] = size - 1;
        pos[lastNode -> v] = 0;

        --size;

        //Heapify
        long parentIndex = 0;
        while(parentIndex < size)
        {
            long leftChildIndex = 2 * parentIndex + 1;
            long rightChildIndex = 2 * parentIndex + 2;
            long minIndex;

            if (leftChildIndex < size && rightChildIndex < size)
                minIndex = (array[leftChildIndex]->distance <= array[rightChildIndex]->distance) ? leftChildIndex : rightChildIndex;
            else if (leftChildIndex < size)
                minIndex = leftChildIndex;
            else
                break;
            if (minIndex != parentIndex) {
                MinHeapNode* smallestNode = array[minIndex];
                MinHeapNode* parentNode = array[parentIndex];

                pos[smallestNode->v] = parentIndex;
                pos[parentNode->v] = minIndex;

                swapMinHeapNode(&array[minIndex], &array[parentIndex]);
            }
            parentIndex = minIndex;
        }
        return root;
    }
    void decreaseKey(long v, long distance)
    {
        long i = pos[v];

        array[i]->distance = distance;

        while (i && (array[i]->distance < array[(i - 1) / 2]->distance))
        {
            pos[array[i]->v] = (i - 1) / 2;
            pos[array[(i - 1) / 2]->v] = i;
            swapMinHeapNode(&array[i], &array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    bool isInMinHeap(long v)
    {
        if (pos[v] < size)
            return true;
        return false;
    }
};

int main() {
    // Write your code here
    long v, e;
    cin >> v >> e;

    Graph *graph = new Graph(v);
    for(long i = 0; i < e; i++)
    {
        long start, end, weight;
        cin >> start >> end >> weight;
        graph -> addEdge(start, end, weight);
    }

    // Dijkstra's algorithm
    long *distance = new long[v];
    MinHeap *minHeap = new MinHeap(v);
    for(long i = 0; i < v; i++)
    {
        distance[i] = INT_MAX;
        minHeap->array[i] = new MinHeapNode(i, distance[i]);
        minHeap->pos[i] = i;
    }
    distance[0] = 0;
    minHeap->array[0] = new MinHeapNode(0, distance[0]);
    minHeap->pos[0] = 0;

    minHeap->size = v;
    while (!minHeap->isEmpty()) {
        MinHeapNode* minHeapNode = minHeap->getMin();
        long vertex = minHeapNode->v;

        AdjacencyListNode* temp = graph->array[vertex].head;
        while (temp != NULL) {
            long index = temp->destination;
            if (minHeap->isInMinHeap(index) && temp->weight < distance[index] && (temp->weight + distance[vertex]) < distance[index])
            {
                distance[index] = temp->weight + distance[vertex];
                minHeap->decreaseKey(index, distance[index]);
            }
            temp = temp->next;
        }
    }

    for (long i = 0; i < v; i++)
        cout << i << " " << distance[i] << "\n";

    delete [] distance;
    return 0;
}
*/

// Time complexity of this code is V^2, better and optimized code is the above one

#include <iostream>
#include <climits>
using namespace std;

long findMinimumVertex(long *distance, bool *visited, long v)
{
    long vertex = -1;
    for (long i = 0; i < v; i++)
    {
        if (!visited[i] && (vertex == -1 || distance[i] < distance[vertex]))
            vertex = i;
    }
    return vertex;
}

int main()
{
    // Write your code here
    long v, e;
    cin >> v >> e;
    long **edges = new long *[v];
    for (long i = 0; i < v; i++)
    {
        edges[i] = new long[v];
        for (long j = 0; j < v; j++)
            edges[i][j] = 0;
    }

    for (long i = 0; i < e; i++)
    {
        long start, end, weight;
        cin >> start >> end >> weight;
        edges[start][end] = weight;
        edges[end][start] = weight;
    }

    // Dijkstra's algorithm

    bool *visited = new bool[v];
    long *distance = new long[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;

    for (long i = 0; i < v; i++)
    {
        long vertex = findMinimumVertex(distance, visited, v);
        visited[vertex] = true;
        for (long j = 0; j < v; j++)
        {
            if (edges[vertex][j] && edges[vertex][j] < distance[j] && !visited[j] && (distance[vertex] + edges[vertex][j]) < distance[j])
                distance[j] = distance[vertex] + edges[vertex][j];
        }
    }

    for (long i = 0; i < v; i++)
        cout << i << " " << distance[i] << "\n";

    for (int i = 0; i < v; i++)
        delete edges[i];
    delete[] edges;
    delete[] distance;
    delete[] visited;
    return 0;
}