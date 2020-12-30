//if it is given that edge are bi-directional and no weightage are there between two nodes


#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    map<int,list<int>> m;
    public:
        Graph(int v)
        {
            this->v=v;
        }
        void addEdge(int x,int y)
        {
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
};
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.printGraph();
}
