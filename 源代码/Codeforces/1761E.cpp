#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int t,n,du[N];
string s[N];
bool bz[N];
void dg(int x,vector<int>&d)
{
	bz[x]=1;
	d.emplace_back(x);
	for (int i=1;i<=n;i++) if (s[x][i-1]=='1' && !bz[i]) dg(i,d);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>s[i],bz[i]=0,du[i]=0;
		vector<vector<int>>d;
		for (int i=1;i<=n;i++)
		if (!bz[i])
		{
			vector<int>d1;
			dg(i,d1);
			d.emplace_back(d1);
		}
		if (d.size()==1)
		{
			cout<<"0\n";
			continue;
		}
		sort(d.begin(),d.end(),[&](vector<int>&a,vector<int>&b){
			return a.size()<b.size();
		});
		int pos=-1;
		for (auto &t:d)
		{
			int mi=1e9,mx=-1e9;
			for (auto p:t)
				for (auto q:t)
				if (s[p][q-1]=='1') du[p]++,du[q]++;
			for (auto p:t) mx=max(mx,du[p]),mi=min(mi,du[p]);
			if (mi!=mx)
			{
				for (auto p:t) if (du[p]==mi) pos=p;
			}
		}
		if (pos!=-1)
		{
			cout<<1<<'\n'<<pos<<'\n';
			continue;
		}
		if (d.size()==2 || d[0].size()==1)
		{
			cout<<d[0].size()<<'\n';
			for (auto t:d[0]) cout<<t<<' ';
			cout<<'\n';
			continue;
		}
		cout<<2<<'\n';
		cout<<d[0][0]<<' '<<d[1][0]<<'\n';
	}
	return 0;
}
/*
1
6
010000
100000
000100
001000
000001
000010
*/
