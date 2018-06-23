#include <bits/stdc++.h>
using namespace std;
stack<int> st;
void topoSortUtil(vector<int> &visited,int src,vector<int> adj[])
{
	visited[src]=true;
	for(auto itr=adj[src].begin();itr!=adj[src].end();itr++)
	{
		if(!visited[*itr])
		{
			topoSortUtil(visited,*itr,adj);
		}
	}
	st.push(src);
}
void topoSort(int n,vector<int> adj[])
{
	vector<int> visited(n+1,false);
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			topoSortUtil(visited,i,adj);
	}
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
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
	}
	cout<<"Topological sort of the graph is as follows:";
	topoSort(n,adj);
	return 0;
}