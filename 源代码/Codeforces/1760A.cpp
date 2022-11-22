#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t,a[3];
	cin>>t;
	while (t--)
	{
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		cout<<a[1]<<'\n';
	}
	return 0;
}


