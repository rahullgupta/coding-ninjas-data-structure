/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1
2 3
Sample Input 2:
4 3
0 1
1 3
0 3
Sample Output 2:
0 1 3
2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> getConnectedComponents(int **edges, int n, int start, bool *visited)
{
    queue<int> vertices;
    vector<int> ans;
    vertices.push(start);
    visited[start] = true;
    // ans.push_back(start);

    while (!vertices.empty())
    {
        int current = vertices.front();
        ans.push_back(current);
        vertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edges[current][i] == 1 && i != current)
            {
                visited[i] = true;
                vertices.push(i);
                // ans.push_back(i);
            }
        }
    }
    return ans;
}

vector<vector<int>> getans(int **edges, int n)
{
    bool *visited = new bool[n];
    vector<vector<int>> components;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> ans = getConnectedComponents(edges, n, i, visited);
            components.push_back(ans);
        }
    }
    return components;
}

int main()
{

    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int start, end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    vector<vector<int>> components = getans(edges, n);
    for (int i = 0; i < components.size(); i++)
    {
        sort(components[i].begin(), components[i].end()); // sorting individual vectors
        for (int j = 0; j < components[i].size(); j++)
        {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
