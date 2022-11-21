#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t,n,a,b;
	cin>>t;
	while (t--)
	{
		cin>>n>>a>>b;
		if (a+b+1<n || a==b && a==n) cout<<"YES\n"; else cout<<"NO\n";
	}
	return 0;
}


