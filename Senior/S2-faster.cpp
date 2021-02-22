#include<bits/stdc++.h>
using namespace std;
int main(int argl,char**argv)
{
	unsigned m,n;
	cin>>m>>n;
	unsigned k;
	cin>>k;
	vector<bool>rp(m), cp(n);
	char c;
	unsigned x;
	unsigned rpc=0,cpc=0;
	for(unsigned long i=0;i<k;i++)
	{
		cin >> c >> x;
		--x;
		if(c=='R')
		{
			if(rp[x])
			{
				--rpc;
				rp[x]=false;
			}
			else
			{
				++rpc;
				rp[x]=true;
			}
		}
		else
		{
			if(cp[x])
			{
				--cpc;
				cp[x]=false;
			}
			else
			{
				++cpc;
				cp[x]=true;
			}
		}
	}
	cout<<rpc*n+cpc*m-2*rpc*cpc<<endl;
	return 0;
}
