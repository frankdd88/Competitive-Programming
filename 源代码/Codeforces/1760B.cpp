#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n;
		cin>>s;
		int ans=0;
		for (auto t:s) ans=max(ans,t-'a'+1);
		cout<<ans<<'\n'; 
	}
	return 0;
}


