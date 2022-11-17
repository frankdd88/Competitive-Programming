#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		int x,y;
		for (int i=1;i<=m;i++) cin>>x>>y;
		if (n>m) cout<<"YES\n"; else cout<<"NO\n";
	}
	return 0;
}


