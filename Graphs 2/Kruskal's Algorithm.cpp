/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
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
1 2 1
0 1 3
0 3 5
*/

/*
Time complexity of this code is E*log E + E*log V, done using union by rank and path compression instead of union-find

#include <iostream>
#include <algorithm>
using namespace std;

class Edges
{
public:
    long source;
    long destination;
    long weight;
};

class Subsets
{
public:
    long parent;
    long rank;
};

bool compareWeight(Edges e1, Edges e2)
{
    return (e1.weight < e2.weight);
}

long find(long v, Subsets *subset)
{
    if(v == subset[v].parent)
        return v;
    return find(subset[v].parent, subset);
}

void Union(Edges *output, Edges *input, long v, Subsets *subset)
{
    long count = 0, i = 0;
    while(count < (v - 1))
    {
        long parentSource = find(input[i].source, subset);
        long parentDestination = find(input[i].destination, subset);
        if(parentSource != parentDestination)
        {
            output[count] = input[i];
            count++;
            if(subset[parentSource].rank < subset[parentDestination].rank)
                subset[parentSource].parent = parentDestination;
            else if(subset[parentSource].rank > subset[parentDestination].rank)
                subset[parentDestination].parent = parentSource;
            else
            {
                subset[parentDestination].parent = parentSource;
                subset[parentSource].rank++;
            }
        }
        i++;
    }
}

int main() {
    // Write your code here
    long v, e;
    cin >> v >> e;
    Edges *input = new Edges[e];
    for(long i = 0; i < e; i++)
        cin >> input[i].source >> input[i].destination >> input[i].weight;

    // Kruskal's algorithm

    sort(input, input + e, compareWeight);

    Subsets *subset = new Subsets[v];
    for(long i = 0; i < v; i++)
    {
        subset[i].parent = i;
        subset[i].rank = 0;
    }

    Edges *output = new Edges[v - 1];

    Union(output, input, v, subset);

    for(long i = 0; i < (v - 1); i++)
        cout << min(output[i].source, output[i].destination) << " " << max(output[i].source, output[i].destination) << " " << output[i].weight << "\n";

    delete [] input;
    delete [] subset;
    delete [] output;
    return 0;
}
*/

// Time complexity of this code is E*log E + E*V, better and optimized code is the above one

#include <iostream>
#include <algorithm>
using namespace std;

class Edges
{
public:
    long source;
    long destination;
    long weight;
};

bool compareWeight(Edges e1, Edges e2)
{
    return (e1.weight < e2.weight);
}

long find(long v, long *parents)
{
    if (v == parents[v])
        return v;
    return find(parents[v], parents);
}

void Union(Edges *output, Edges *input, long v, long *parents)
{
    long count = 0, i = 0;
    while (count < (v - 1))
    {
        long parentSource = find(input[i].source, parents);
        long parentDestination = find(input[i].destination, parents);
        if (parentSource != parentDestination)
        {
            output[count] = input[i];
            count++;
            parents[parentSource] = parents[parentDestination];
        }
        i++;
    }
}

int main()
{
    // Write your code here
    long v, e;
    cin >> v >> e;
    Edges *input = new Edges[e];
    for (long i = 0; i < e; i++)
        cin >> input[i].source >> input[i].destination >> input[i].weight;

    // Kruskal's algorithm

    sort(input, input + e, compareWeight);

    long *parents = new long[v];
    for (long i = 0; i < v; i++)
        parents[i] = i;

    Edges *output = new Edges[v - 1];
    Union(output, input, v, parents);

    for (long i = 0; i < (v - 1); i++)
        cout << min(output[i].source, output[i].destination) << " " << max(output[i].source, output[i].destination) << " " << output[i].weight << "\n";

    delete[] input;
    delete[] parents;
    delete[] output;
    return 0;
}