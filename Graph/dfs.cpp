#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> m;

public:
    void addEdge(int x, int y)
    {
        // These two lines repesents that graph is bidirectional
        m[x].push_back(y);
        m[y].push_back(x);
    }
    void print_dfs(int src, map<int, bool> &visited)
    {
        cout << src << " ";
        // print and mark is visited
        visited[src] = true;
        // Traverse through the not visited neighbour one by one
        for (auto e : m[src])
        {
            if (!visited[e])
                print_dfs(e, visited);
        }
        return;
    }
    void dfs(int src)
    {
        // All the nodes are not visited at first
        map<int, bool> visited;
        // Visited will be passed call by referece so that if ones visited we can mark it true permanently
        print_dfs(src, visited);
    }
};
int main()
{
    Graph g;
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(5, 1);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.dfs(4);
}
