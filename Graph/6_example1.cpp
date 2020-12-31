Question Link:: "https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/description/"

 // We can also use bfs traversal to solve this.
 
#include<bits/stdc++.h>
using namespace std;
void dfs(int src, map<int,bool> &visited,map<int,list<int>> m)
{
	visited[src]=true;
	for(auto e:m[src])
	{
		if(!visited[e])
		{
			dfs(e,visited,m);
		}
	}
	return;

}
int main(){
	int n,e;
	cin>>n>>e;
	map<int,list<int>> m;
	map<int,bool> visited;
	for(int i=1;i<=n;i++)
		visited[i]=false;
	int cnt=0;
	while(e--)
	{
		int node1,node2;
		cin>>node1>>node2;
		m[node1].push_back(node2);
		m[node2].push_back(node1);
	}
	for(auto it=visited.begin();it!=visited.end();it++)
	{
			if(it->second==false)
			{
				dfs(it->first,visited,m);
				cnt++;
			}
	}
	cout<<cnt<<endl;
}
