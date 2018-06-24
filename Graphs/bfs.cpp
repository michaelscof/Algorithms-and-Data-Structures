#include <bits/stdc++.h>
using namespace std;
void dfsUtil(vector<bool> &visited,int src,vector<int> adj[])
{
    queue<int> q;
    q.push(src);
	while(!q.empty())
    {
        int k=q.front();
        q.pop();
        cout<<k<<" ";
        for(auto itr=adj[k].begin();itr!=adj[k].end();itr++)
        {
            if(!visited[*itr])
            {
                q.push(*itr);
                visited[*itr]=true;
            }
        }
    }
}
void bfs(vector<int> adj[],int n)
{
	vector<bool> visited(n+1,false);
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			bfsUtil(visited,i,adj);
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
	bfs(adj,n);
	return 0;
}