#include <bits/stdc++.h>
using namespace std;
#define INF 999999
typedef pair<int,int> Pair;
int prims(vector<Pair> adj[],int n,int e)
{
	priority_queue<Pair,vector<Pair >,greater<Pair  > > pq;
	vector<bool> inMst(n+1,false);
	vector<int> key(n+1,INF);
	vector<int> parent(n+1,-1);
	int src=1;
	pq.push(make_pair(0,src));
	key[src]=0;
	while(!pq.empty())
	{
		int a=pq.top().second;
		pq.pop();
		inMst[a]=true;
		for(auto itr=adj[a].begin();itr!=adj[a].end();itr++)
		{
			if(!inMst[itr->first] && key[itr->first]>itr->second)
			{
				key[itr->first]=itr->second;
				pq.push(make_pair(key[itr->first],itr->first));
				parent[itr->first]=a;
			}
		}
	}
	for(int i=2;i<=n;i++)
		cout<<parent[i]<<" "<<i<<endl;
	int mst_sum=0;
	for(int i=2;i<=n;i++)
	{
		for(auto itr=adj[i].begin();itr!=adj[i].end();itr++)
		{
			if(itr->first==parent[i])
			mst_sum+=itr->second;
		}
	}
	return mst_sum;
}
int main() {
	int n,e;
	cin>>n>>e;
	vector<pair<int,int> > adj[n+1];
	int a,b,w;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}
	int mst_sum=prims(adj,n,e);
	cout<<"Minimum Spanning Tree Length:"<<mst_sum<<endl;
	return 0;
}