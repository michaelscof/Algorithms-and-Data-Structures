#include <bits/stdc++.h>
using namespace std;
void dfsUtil(vector<bool> &visited,int src,vector<int> adj[])
{
	visited[src]=true;
	cout<<src<<" ";
	for(auto itr=adj[src].begin();itr!=adj[src].end();itr++)
	{
		if(!visited[*itr])
			dfsUtil(visited,*itr,adj);
	}
}
void dfs(vector<int> adj[],int n)
{
	vector<bool> visited(n+1,false);
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			dfsUtil(visited,i,adj);
	}
}
int main() {
	int n,e,a,b;
	cin>>n>>e;
	vector<int> adj[n+1];
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    cout<<"DFS of graph is as follows:";
	dfs(adj,n);
	return 0;
}