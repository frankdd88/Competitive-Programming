#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t,n,k,x,s[2],bz[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	for (int tt=1;tt<=t;tt++)
	{
		cin>>n>>k;
		for (int i=1;i<=n;i++) 
		{
			cin>>x;
			bz[x]=tt;
		}
		s[0]=0;
		s[1]=1;
		while (bz[s[0]]==tt) s[0]+=2;
		while (bz[s[1]]==tt) s[1]+=2;
		while (k--)
		{
			bz[s[0]]=tt;
			bz[s[1]]=tt;
			while (bz[s[0]]==tt) s[0]+=2;
			while (bz[s[1]]==tt) s[1]+=2;
		}
		int u=min(s[0],s[1]);
		if (u&1) cout<<"Bob\n"; else cout<<"Alice\n"; 
	}
	return 0;
}


