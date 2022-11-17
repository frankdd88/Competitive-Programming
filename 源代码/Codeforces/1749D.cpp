#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mo=998244353;
int n;
long long m;
bool bz[N];
vector<int>d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=2;i<=n;i++)
	{
		if (!bz[i]) d.emplace_back(i);
		for (auto j:d)
		{
			if (i*j>n) break;
			bz[i*j]=1;
			if (i%j==0) break;
		}
	}
	int ans=0;
	for (int i=1,j=m%mo;i<=n;i++,j=1ll*j*(m%mo)%mo) ans=(ans+j)%mo;
	for (long long i=1,j=1,k=1;i<=n;i++)
	{
		if (!bz[i]) j*=i;
		if (j>m) break;
		k=k*((m/j)%mo)%mo;
		ans=(ans+mo-k)%mo;
	}
	cout<<ans;
	return 0;
}


