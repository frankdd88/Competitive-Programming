#include<bits/stdc++.h>
using namespace std;
const int N=155;
const int mo=1e9+9;
int t,n,a[N];
map<string,int>f[N][N][2];
int dg(int l,int r,int x,string s)
{
	if (l>r)
	{
		string t=s;
		reverse(t.begin(),t.end());
		return s==t;
	}
	if (f[l][r][x].count(s)) return f[l][r][x][s];
	int &ans=f[l][r][x][s];
	if (x==0)
	{
		for (int i=l;i<=r;i++)
		{
			string t=to_string(a[r]-a[i-1]);
			reverse(t.begin(),t.end());
			if (t.size()>s.size())
			{
				if (s==t.substr(0,s.size())) ans=(ans+dg(l,i-1,1,t.substr(s.size(),t.size()-s.size())))%mo;
			}
			else
			{
				if (t==s.substr(0,t.size())) ans=(ans+dg(l,i-1,0,s.substr(t.size(),s.size()-t.size())))%mo;
			}
		}
	}
	else
	{
		for (int i=l;i<=r;i++)
		{
			string t=to_string(a[i]-a[l-1]);
			if (t.size()>s.size())
			{
				if (s==t.substr(0,s.size())) ans=(ans+dg(i+1,r,0,t.substr(s.size(),t.size()-s.size())))%mo;
			}
			else
			{
				if (t==s.substr(0,t.size())) ans=(ans+dg(i+1,r,1,s.substr(t.size(),s.size()-t.size())))%mo;
			}
		}
	}
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
		for (int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
		for (int i=1;i<=n;i++)
			for (int j=i;j<=n;j++)
			f[i][j][0].clear(),f[i][j][1].clear();
		cout<<dg(1,n,0,"")<<'\n';
	}
	return 0;
}


