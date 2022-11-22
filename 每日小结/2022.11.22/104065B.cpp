#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
const int M=600;
int n,l[N],r[N],a[N],b[N],s[N];
bool bz[N];
vector<int>p[N*3];
void add(int x,int l,int r,int ll,int rr,int y)
{
	if (l>=ll && r<=rr)
	{
		p[x].emplace_back(y);
		return;
	}
	int mid=l+r>>1;
	if (ll<=mid) add(x<<1,l,mid,ll,rr,y);
	if (rr>mid) add(x<<1|1,mid+1,r,ll,rr,y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>l[i]>>r[i]>>a[i];
	vector<int>d;
	for (int i=1;i<=n;i++) if (!a[i]) bz[i]=1,d.emplace_back(i);
	for (int i=0;i<d.size();i++)
	{
		if (i%M==0)
		{
			for (int i=1;i<=n;i++) s[i]=s[i-1]+b[i];
			for (int i=1;i<=n;i++)
			if (!bz[i] && s[r[i]]-s[l[i]-1]+M>=a[i])
			{
				bz[i]=1;
				a[i]-=s[r[i]]-s[l[i]-1];
				add(1,1,1<<19,l[i],r[i],i);
			}
		}
		int x=d[i];
		b[x]=1;
		for (int j=x+(1<<19)-1;j;j>>=1)
		{
			int m=0;
			for (int k=0;k<p[j].size();k++)
			{
				int u=p[j][k];
				if (a[u])
				{
					if (!--a[u]) d.emplace_back(u);
					else p[j][m++]=u;
				}
			}
			p[j].resize(m);
		}
	}
	cout<<d.size();
	return 0;
}


