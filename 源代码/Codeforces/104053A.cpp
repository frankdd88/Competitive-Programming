#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<LL,LL>
using namespace std;
const int N=2020;
int n,a[N],t[N],T,cnt[N];LL f[N][N][2],g[N][N],h[N][N];
vector<int>v[N];
void cmin(LL &x,LL y){y<x?x=y:0;}
void dfs(int x,int ff){//cout<<x<<endl;
	// cnt[x]=x!=1&&v[x].size()==1||!v[x].size();
	if(x!=1&&v[x].size()==1||!v[x].size()){
		cnt[x]=1;
		f[x][0][1]=0;
		g[x][1]=0;
		g[x][0]=a[x];
		return;
	}
	h[x][0]=0;
	f[x][0][0]=f[x][0][1]=0;
	g[x][0]=0;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y==ff)continue;
		dfs(y,x);
		for(int j=cnt[x];~j;j--){
			for(int k=1;k<=cnt[y];k++)
				cmin(f[x][j+k][0],f[x][j][0]+g[y][k]),
				cmin(f[x][j+k][1],min(f[x][j][1]+g[y][k],f[x][j][0]+f[y][k][1])),
				cmin(h[x][j+k],h[x][j]+f[y][k][1]),
				cmin(g[x][j+k],g[x][j]+g[y][k]);
			f[x][j][1]=min(f[x][j][1]+g[y][0],f[x][j][0]+f[y][0][1]);
			f[x][j][0]+=g[y][0];
			h[x][j]+=f[y][0][1];
			g[x][j]+=g[y][0];
		}
		cnt[x]+=cnt[y];
	}
	for(int i=0;i<=cnt[x];i++)
		cmin(f[x][i][1],h[x][i]+a[x]),
		cmin(g[x][i],h[x][i]+a[x]);
	// cout<<x<<" "<<f[x][0][1]<<endl;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),v[i].clear(),cnt[i]=0;
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	memset(h,0x3f,sizeof(h));
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].pb(y);v[y].pb(x);
	}
	dfs(1,0);
	LL ans=1e18;
	for(int i=0;i<=cnt[1];i++)
		cmin(ans,f[1][i][1]+t[i]);
	printf("%lld\n",ans);
}
int main(){
	#ifdef local
	freopen("in.txt","r",stdin);
	#endif
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
