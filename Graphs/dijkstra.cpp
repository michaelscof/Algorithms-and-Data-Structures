#include<bits/stdc++.h>
using namespace std;
#define INF 999999
typedef pair<int,int> Pair;
void dijk(vector<Pair> adj[],int n,int src)
{
    priority_queue<Pair,vector<Pair>,greater<Pair> > pq;
    vector<int> dist(n+1,INF); 
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int a=pq.top().second;
        pq.pop();
        for(auto itr=adj[a].begin();itr!=adj[a].end();itr++)
        {
            if(dist[itr->first]>dist[a]+itr->second)
            {
                dist[itr->first]=dist[a]+itr->second;
                pq.push(make_pair(dist[itr->first],itr->first));
            }
        }
    }
    cout<<"Distance of each vertex from source:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }
}
int main()
{
    int n,e,a,b,w;
    cin>>n>>e;
    vector<Pair> adj[n+1];
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    int src;
    cin>>src;
    dijk(adj,n,src);
    return 0;
}