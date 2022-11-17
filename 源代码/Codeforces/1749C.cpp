#include<bits/stdc++.h>
using namespace std;
const int N=105;
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
		sort(a+1,a+n+1);
		int ans=0;
		for (int k=1;k<=n;k++)
		{
			deque<int>d(a+1,a+n+1);
			bool bz=0;
			for (int j=k;j;j--)
			{
				while (!d.empty() && d.back()>j) d.pop_back();
				if (d.empty())
				{
					bz=1;
					break;
				}
				d.pop_back();
				if (!d.empty()) d.pop_front();
			}
			if (bz) break;
			ans=k; 
		}
		cout<<ans<<'\n';
	}
	return 0;
}


