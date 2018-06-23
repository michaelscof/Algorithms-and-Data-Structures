#include <bits/stdc++.h>
using namespace std;
int parent[10003];
int size[10003];
int cmp(pair<int,pair<int,int> > &a,pair<int,pair<int,int> > &b)
{
	return a.first<b.first;
}
int find(int x)
{
	if(x!=parent[x])
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}
void Union(int a,int b)
{
	int i=find(a);
	int j=find(b);
	if(size[i]>size[j])
	{
		parent[j]=i;
		size[i]+=size[j];
	}
	else
	{
		parent[i]=j;
		size[j]+=size[i];
	}
}
int main() {
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		size[i]=1;
	}
	vector<pair<int,pair<int,int> > > v(e);
	int a,b,w;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		v[i].first=w;
		v[i].second.first=a;
		v[i].second.second=b;
	}
	sort(v.begin(),v.end(),cmp);
	int mst_sum=0,c=0;
	for(auto itr=v.begin();itr!=v.end();itr++)
	{
		int a=find(itr->second.first);
		int b=find(itr->second.second);
		if(a!=b)
		{
			mst_sum+=itr->first;
			Union(a,b);
			c++;
			cout<<itr->second.first<<" "<<itr->second.second<<endl;
		}
		if(c==n-1)
			break;
	}
	cout<<"Minimum Spanning Tree Length:"<<mst_sum<<endl;
	return 0;
}