#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,a[N],l[N],r[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		r[n+1]=0;
		for (int i=1;i<=n;i++) l[i]=max(l[i-1],a[i]);
		for (int i=n;i;i--) r[i]=max(r[i+1],a[i]);
		for (int i=1;i<=n;i++) cout<<a[i]-max(l[i-1],r[i+1])<<' ';
		cout<<'\n';
	}
	return 0;
}


