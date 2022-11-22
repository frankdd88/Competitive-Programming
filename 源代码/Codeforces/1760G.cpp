#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
using pp=pair<int,int>;
int t,n,a,b;
bool bz;
vector<pp>p[N];
set<int>s;
void dg(int x,int y,int z)
{
	if (x==b) return;
	s.insert(z);
	for (auto t:p[x]) if (t.first!=y) dg(t.first,x,z^t.second);
}
void dg1(int x,int y,int z)
{
	if (x^b)
	{
		if (s.count(z)) bz=1;
	}
	for (auto t:p[x]) if (t.first!=y) dg1(t.first,x,z^t.second);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n>>a>>b;
		for (int i=1;i<=n;i++) p[i].clear();
		for (int i=1;i<n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			p[x].emplace_back(y,z);
			p[y].emplace_back(x,z);
		}
		bz=0;
		s.clear();
		dg(a,0,0);
		dg1(b,0,0);
		if (bz) cout<<"YES\n"; else cout<<"NO\n";
	}
	return 0;
}


