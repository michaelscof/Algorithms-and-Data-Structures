#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int lis[n];
		fill(lis,lis+n,1);
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[i]>arr[j] && lis[i]<lis[j]+1)
					lis[i]=lis[j]+1;
			}
		}
		int max1=lis[0];
		for(int i=1;i<n;i++)
			max1=max(max1,lis[i]);
		int cmp=max1;
		cout<<"Length of LIS:"<<max1<<endl;
		vector<int> res;
		for(int i=n-1;i>=0;i--)
		{
			if(lis[i]==cmp)
			{
				res.push_back(arr[i]);
				--cmp;
			}
		}
		for(auto itr=res.rbegin();itr!=res.rend();itr++)
			cout<<*itr<<" ";
	}
	return 0;
}