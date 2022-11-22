#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		int l=1,r=n;
		while (l<n && a[l]>=a[l+1]) l++;
		while (r>1 && a[r]>=a[r-1]) r--;
		if (l>=r) cout<<"YES\n"; else cout<<"NO\n";
	}
	return 0;
}


