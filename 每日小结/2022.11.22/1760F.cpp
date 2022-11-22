#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,d,a[N];
long long c,s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n>>c>>d;
		for (int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		if (1ll*a[1]*d<c) 
		{
			cout<<"Impossible\n";
			continue;
		}
		if (s[min(n,d)]>=c)
		{
			cout<<"Infinity\n";
			continue;
		}
		int l=0,r=d,mid,ans;
		while (l<=r)
		{
			mid=l+r>>1;
			long long sum=(d/(mid+1))*s[min(n,mid+1)]+s[min(n,d%(mid+1))];
			if (sum>=c) ans=mid,l=mid+1; else r=mid-1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}


