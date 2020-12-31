// If the graph is unweighted then only we can use BFS algorithm
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    //Adjacency List
    map<int, list<int>> m;
public:
    void addEdge(int x, int y)
    {
        // These two lines repesents that graph is bidirectional
        m[x].push_back(y);
        m[y].push_back(x);
    }
    void shortestPath(int src,int dest)
    {
        map<int,int> dist;
        // Initialising the distance of nodes from src node as infinite
        for(auto it=m.begin();it!=m.end();it++)
        {
            dist[it->first]=INT_MAX;
        }
        // But we know that src node is at a dist of 0 from itself
        dist[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node= q.front();
            q.pop();
            for(auto e:m[node])
            {
                if(dist[e]==INT_MAX)
                {
                    q.push(e);
                    dist[e]=dist[node]+1;
                }
            }
        }
        cout<<"Distance of "<<dest<<" from "<<src<<" is "<<dist[dest]<<endl;
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
    g.shortestPath(6,1);
    
}
