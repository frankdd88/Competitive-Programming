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
		cin>>n;
		map<int,int>mp;
		int x;
		for (int i=1;i<=n;i++) 
		{
			cin>>x;
			mp[x]++;
		}
		if (mp.size()==2) cout<<n/2+1<<'\n';
		else cout<<n<<'\n';
	}
	return 0;
}


