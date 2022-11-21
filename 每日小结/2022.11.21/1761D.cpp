#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mo=1e9+7;
int n,k,p[N],q[N];
int ksm(int x,int y)
{
	if (y<0) return 0;
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
	if (x<y || y<0) return 0;
	return 1ll*p[x]*q[y]%mo*q[x-y]%mo; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	p[0]=q[0]=1;
	for (int i=1;i<=n;i++) p[i]=1ll*p[i-1]*i%mo;
	q[n]=ksm(p[n],mo-2);
	for (int i=n-1;i;i--) q[i]=1ll*q[i+1]*(i+1)%mo;
	if (k==0)
	{
		cout<<ksm(3,n);
		return 0;
	}
	int ans=0;
	for (int i=1;i<=k;i++)
	{
		ans=(ans+1ll*c(k-1,i-1)*c(n-k,i)%mo*ksm(3,n-2*i))%mo;
		ans=(ans+1ll*c(k-1,i-1)*c(n-k,i-1)%mo*ksm(3,n-2*i+1))%mo;
	}
	cout<<ans;
	return 0;
}
