#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,a[N];
long long calc()
{
	long long ans=0,cnt=0;
	for (int i=1;i<=n;i++) 
		if (!a[i]) ans+=cnt; else cnt++;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		long long ans=calc();
		for (int i=1;i<=n;i++)
		if (!a[i])
		{
			a[i]=1;
			ans=max(ans,calc());
			a[i]=0;
			break;
		}
		for (int i=n;i;i--)
		if (a[i])
		{
			a[i]=0;
			ans=max(ans,calc());
			a[i]=1;
			break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}


