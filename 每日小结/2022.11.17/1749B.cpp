#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) cin>>b[i];
		sort(b+1,b+n+1);
		long long ans=accumulate(a+1,a+n+1,0ll)+accumulate(b+1,b+n+1,0ll);
		ans-=b[n];
		cout<<ans<<'\n';
	}
	return 0;
}


