#include<bits/stdc++.h>
using namespace std;
const int N=105;
int t,n,b[N][N],du[N];
vector<int>p[N];
set<int>a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) p[i].clear(),a[i].clear(),du[i]=0;
		for (int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for (int j=0;j<n;j++)
			if (s[j]=='1') p[i].emplace_back(j+1),du[j+1]++;
		}
		vector<int>d;
		for (int i=1;i<=n;i++) a[i].insert(i);
		for (int i=1;i<=n;i++) if (!du[i]) d.emplace_back(i);
		for (int i=0;i<d.size();i++)
		{
			int x=d[i];
			for (auto t:p[x])
			{
				for (auto p:a[x]) a[t].insert(p);
				if (!--du[t]) d.emplace_back(t);
			}
		}
		for (int i=1;i<=n;i++) 
		{
			cout<<a[i].size()<<' ';
			for (auto t:a[i]) cout<<t<<' ';
			cout<<'\n';
		}
	}
	return 0;
}


