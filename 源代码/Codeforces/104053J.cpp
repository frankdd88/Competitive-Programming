#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
const int mo=998244353;
int n,m,p[N],q[N];
int ksm(int x,int y)
{
	int t=1;
	for (;y;y>>=1)
	{
		if (y&1) t=1ll*t*x%mo;
		x=1ll*x*x%mo;
	}
	return t;
}
int c(int x,int y)
{
	return 1ll*p[x]*q[y]%mo*q[x-y]%mo;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	p[0]=q[0]=1;
	for (int i=1;i<=n;i++) p[i]=1ll*p[i-1]*i%mo;
	q[n]=ksm(p[n],mo-2);
	for (int i=n-1;i;i--) q[i]=1ll*q[i+1]*(i+1)%mo;
	m=(m+1)/2+2;
	int ans=0;
	for (int i=0;i<=n;i++)
	{
		int x=n-2*i+1,y=x/m,z=x-y*m;
		if (z<0) y++;
		if (z==0) continue;
		if (y&1) ans=(ans-c(n,i)+mo)%mo;
		else ans=(ans+c(n,i))%mo;
	}
	cout<<ans;
	return 0;
}


