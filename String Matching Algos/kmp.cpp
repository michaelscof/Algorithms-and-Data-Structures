#include <bits/stdc++.h>
using namespace std;
void computeLps(string pat,int lenp,int lps[])
{
	int j=0;
	lps[0]=0;
	int i=1;
	while(i<lenp)
	{
		if(pat[i]==pat[j])
		{
			j++;
			lps[i]=j;
			i++;
		}
		else
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
int main() {
	string text,pat;
	cin>>text>>pat;
	int lenp=pat.length();
	int lps[lenp];
	computeLps(pat,lenp,lps);
	for(int i=0;i<lenp;i++)
	{
		cout<<lps[i]<<" ";
	}
	cout<<endl;
	int i=0;
	int j=0;
	while(i<text.length())
	{
		if(text[i]==pat[j])
		{
			i++;
			j++;
		}
		if(j==lenp)
			cout<<"Pattern found at index "<<(i-j)<<endl;
		else if(i<text.length() && text[i]!=pat[j])
		{
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
	return 0;
}