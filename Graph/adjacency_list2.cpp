// if the egde of graph can be of any type(bi-directional or directed) and weightage are there between two nodes

#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<string, list<pair<string, int>>> m;

public:
    void addEdge(string c1, string c2, bool biDir, int dist)
    {
        pair<string, int> p1;
        p1.first = c2;
        p1.second = dist;
        m[c1].push_back(p1);
        if (biDir)
        {
            pair<string, int> p2;
            p2.first = c1;
            p2.second = dist;
            m[c2].push_back(p2);
        }
    }
    void printGraph()
    {
        for (auto it = m.begin(); it != m.end(); it++)
        {
            list<pair<string, int>> l = it->second;
            cout << "City " << it->first << " is connected with ";
            for (auto e : l)
            {
                cout << e.first << "(" << e.second << ")"
                     << ",";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g;
    g.addEdge("A", "B", false, 20);
    g.addEdge("A", "C", true, 5);
    g.addEdge("A", "D", false, 30);
    g.addEdge("C", "D", true, 7);
    g.addEdge("B", "D", true, 10);
    g.printGraph();
}
