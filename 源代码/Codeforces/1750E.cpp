#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n;
		string s;
		cin>>s;
		vector<int>a(n+1);
		for (int i=1;i<=n;i++) a[i]=a[i-1]+(s[i-1]=='('?1:-1);
		auto b=a;
		sort(a.begin(),a.end());
		long long ans=0;
		for (int i=1;i<=n;i++) ans+=1ll*a[i]*i;
		vector<int>d,l(n+1),r(n+1,n+1);
		for (int i=0;i<=n;i++) 
		{
			while (!d.empty() && b[d.back()]>b[i])
			{
				r[d.back()]=i;
				d.pop_back();
			}
			l[i]=d.empty()?-1:d.back();
			d.emplace_back(i);
		}
		for (int i=0;i<=n;i++) ans-=1ll*b[i]*(1ll*(i-l[i])*(r[i]-i)-1);
		cout<<ans<<'\n';
	}
	return 0;
}


