#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mo=998244353;
int t,n,m,p[N],q[N];
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	p[0]=q[0]=1;
	for (int i=1;i<N;i++) p[i]=1ll*p[i-1]*i%mo;
	q[N-1]=ksm(p[N-1],mo-2);
	for (int i=N-2;i;i--) q[i]=1ll*q[i+1]*(i+1)%mo;
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		cout<<1ll*p[n-1]*q[n-m]%mo*q[m-1]%mo*p[n]%mo<<'\n';
	}
	return 0;
}


