#include <bits/stdc++.h>
using namespace std;
void bellman_ford(vector<pair<int,pair<int,int> > > &edges,int n,int e,int src)
{
	vector<int> dist(n+1,INT_MAX);
	dist[src]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			int a=edges[j].first;
			int b=edges[j].second.first;
			int c=edges[j].second.second;
			if(dist[a]!=INT_MAX && dist[b]>dist[a]+c)
			{
				dist[b]=dist[a]+c;
			}
		}
	}
	int flag=1;
	for(int i=0;i<e;i++)
	{
		int a=edges[i].first;
		int b=edges[i].second.first;
		int c=edges[i].second.second;
		if(dist[a]!=INT_MAX && dist[b]>dist[a]+c)
		{
			cout<<"Graph contains negative weight cycle";
			flag=0;
		}
	}
	if(flag)
	{
		cout<<"Source: "<<src<<endl;
		cout<<"Node\tDistance\n";
		for(int i=1;i<=n;i++)
		{
			if(i!=src)
			{
				cout<<i<<"\t\t"<<dist[i]<<endl;
			}
		}
	}
}
int main() {
	int n,e,a,b,w;
	cin>>n>>e;
	vector<pair<int,pair<int,int> > > edges;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		edges.push_back(make_pair(a,make_pair(b,w)));
	}
	int src;
	cin>>src;
	bellman_ford(edges,n,e,src);
	return 0;
}