#include<bits/stdc++.h>
using namespace std;
#define INF 12991391
int main()
{
    int n,e,a,b,w;
    cin>>n>>e;
    int adj[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(i!=j)
    		adj[i][j]=INF;
    		else
    		adj[i][j]=0;
    	}
    }
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>w;
        adj[a][b]=w;//considering directed graph in this case
    }
    //Code for algorithm begins here
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(adj[i][j]>adj[i][k]+adj[k][j])
                    adj[i][j]=adj[i][k]+adj[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
        	if(adj[i][j]!=INF)	
            cout<<adj[i][j]<<"\t";
            else
            cout<<"INF\t";
        }
        cout<<endl;
    }
    return 0;
}