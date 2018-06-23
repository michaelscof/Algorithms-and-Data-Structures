#include<bits/stdc++.h>
using namespace std;
#define MAX 100002
int parent[MAX];
int size[MAX];
int find(int x)
{
    while(x!=parent[x])
    {
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}
void union1(int a,int b)
{
    int i=find(a);
    int j=find(b);
    if(i!=j)
    {
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
}
int main()
{
    int n,e,a,b;
    cin>>n>>e;
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        union1(a,b);
    }
    cout<<"Node\tParent"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"\t\t"<<parent[i]<<endl;
    }
    return 0;
}