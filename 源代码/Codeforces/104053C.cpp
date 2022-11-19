#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<LL,LL>
using namespace std;
const int N=2e5+50;
int T,n,m,d[N],dis[N],vis[N],q[N],l,r,a[N],f[N],cnt,num[N];
vector<int>v[N],iv[N],vv[N];
// void dfs(int x){
// 	vis[x]=1;
// 	for(int i=0;i<v[x].size();i++){
// 		int y=v[x][i];
// 		if(!vis[y])dfs(y);
// 	}
// }
// void dfs2(int x){
// 	vis[x]|=2;
// 	for(int i=0;i<iv[x].size();i++){
// 		int y=iv[x][i];
// 		if(~vis[y]&2)dfs2(y);
// 	}
// }
void cmax(int &x,int y){y>x?x=y:0;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void solve(){
	scanf("%d%d",&n,&m);cnt=0;
	for(int i=1;i<=n;i++)
		v[i].clear(),iv[i].clear(),d[i]=0,vis[i]=3,f[i]=i,a[i]=0,num[i]=0,
		vv[i].clear();
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].pb(y);iv[y].pb(x);
	}
	for(int i=1;i<=n;i++)
		for(int j=0,pre=0;j<iv[i].size();j++){
			int y=iv[i][j];
			if(pre){
				int x=find(pre),z=find(y);
				f[z]=x;
			}
			pre=y;
		}
	// dfs(1);dfs2(n);
	// for(int i=1;i<=n;i++){
	// 	// if(vis[i]!=3)continue;
	// 	for(int j=0;j<v[i].size();j++)
	// 		d[v[i][j]]++;
	// }
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			int y=v[i][j];
			vv[find(i)].pb(find(y));d[find(y)]++;
		}
	}
	q[l=r=1]=1;
	while(l<=r){
		int x=q[l++];
		dis[x]=++cnt;
		for(int i=0;i<vv[x].size();i++){
			int y=vv[x][i];
			// if(vis[y]!=3)continue;
			if(!--d[y])q[++r]=y;
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<dis[i]<<" ";puts("");
	a[1]=dis[1];bool fl=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			int y=v[i][j];
			if(!a[y])a[y]=dis[find(y)]-dis[find(i)];
			else if(dis[find(y)]!=dis[find(i)]+a[y])fl=1;
		}
	}
	// for(int i=1;i<=n;i++)printf("%d ",a[i]?a[i]:1);
	// 	puts("");
	for(int i=1;i<=n;i++)
		if(a[i]<=0)fl=1;
	if(fl)puts("No");
	else{
		puts("Yes");
		for(int i=1;i<=n;i++)printf("%d ",a[i]?a[i]:1);
		puts("");
	}
}
int main(){
	#ifdef local
	freopen("in.txt","r",stdin);
	#endif
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
