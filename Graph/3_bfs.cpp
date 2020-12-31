// Level order traversal


#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int,list<int>> m;
    public:
        void addEdge(int x,int y)
        {
            // These two lines repesents that graph is bidirectional 
            m[x].push_back(y);
            m[y].push_back(x);
        }
        void printGraph()
        {
            for(auto it=m.begin();it!=m.end();it++)
            {
                list<int> l=it->second;
                cout<<it->first<<"->";
                for(auto e:l)
                    cout<<e<<" ";
                cout<<endl;
            }
        }
        // src indicates that node from which we need to start bfs 
        void bfs(int src)
        {
            queue<int> q;
            map<int,bool> visited;
            q.push(src);
            visited[src]=true;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                cout<<node<<" ";
                list<int> l=m[node];
                for(auto e:l)
                {
                    if(visited[e]==0)
                    {
                        q.push(e);
                        visited[e]=1;
                    }
                }
            }
        }
        
};
int main()
{
    Graph g;
    g.addEdge(2,1);
    g.addEdge(2,4);
    g.addEdge(5,1);
    g.addEdge(4,5);
    g.addEdge(4,6);
    // g.printGraph();
    g.bfs(6);


}
