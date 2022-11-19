#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
int k,c[20][20];
long long n,m;
map<long long,int>f[60][20];
int dg(int x,int y,long long n)
{
	if (((1ll<<x+1)-1)*(k/2)*(k-k/2)<n) return 0;
	if (x==-1) return n==0;
	if (f[x][y].count(n)) return f[x][y][n];
	int ans=0;
	for (int i=0;i<=k;i++)
		for (int j=0;j<=i && j<=y;j++)
		{
			//y j*0 (y-j)*1
			//k-y (i-j)*0 (k-y-i+j)*1
			if (j<y && !(m>>x&1) || n<i*(k-i)*(1ll<<x)) continue;
			ans=(ans+1ll*c[y][j]*c[k-y][i-j]%mo*dg(x-1,y-(m>>x&1)*j,n-i*(k-i)*(1ll<<x)))%mo;
		}
	return f[x][y][n]=ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for (int i=0;i<=k;i++)
	{
		c[i][0]=1;
		for (int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
	}
	cout<<dg(50,k,n);
	return 0;
}


