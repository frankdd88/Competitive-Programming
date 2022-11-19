#include <bits/stdc++.h>
#define fx first
#define fy second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e3 + 10;
const int mod = 1000000007;
int add(int x,int y){
	x += y;
	if (x >= mod) x -= mod;
	return x;
}
int sub(int x,int y){
	x -= y;
	if (x < 0) x += mod;
	return x;
}
int qpow(int x,int y){
	int res = 1;
	while (y){
		  if (y & 1) res = 1ll * x * res % mod;
		  x = 1ll * x * x % mod;y >>= 1;
	}
	return res;
}

struct Edge{
	int to , nex;
}e[N << 1]; int head[N] , ecnt;

vector <int> G[N];

void adde(int fr,int to){
	G[fr].pb(to);
	e[++ecnt] = (Edge){to , head[fr]};
	head[fr] = ecnt;
}


int f[N][N] , g[N][N];
int p[N] , q[N];
int a[N] , b[N] , c[N] , n;
int sz[N];
int tmpf[N] , tmpg[N];

int ans[N];

void dfs(int x,int pa){
	f[x][1] = p[x];
	g[x][1] = q[x];
	sz[x] = 1;
	
	
	for (int y:G[x]){
		if (y == pa) continue;
		dfs(y , x);
				
		memset(tmpf , 0 , sizeof (int) * (sz[x] + sz[y] + 1));
		memset(tmpg , 0 , sizeof (int) * (sz[x] + sz[y] + 1));
		
		
		for (int i = 1;i <= sz[x];i++){
			tmpf[i] = add(tmpf[i] , 1ll * f[x][i] * sub(1 , p[y]) % mod);
			for (int j = 1;j <= sz[y];j++){
				tmpf[i + j] = add(tmpf[i + j] , 1ll * f[x][i] * f[y][j] % mod);
			}
		}
		
		for (int i = 1;i <= sz[x];i++){
			tmpg[i] = add(tmpg[i] , 1ll * g[x][i] * sub(1 , p[y]) % mod);
			for (int j = 1;j <= sz[y];j++){
				tmpg[i + j] = add(tmpg[i + j] , 1ll * g[x][i] * f[y][j] % mod);
				tmpg[i + j] = add(tmpg[i + j] , 1ll * f[x][i] * g[y][j] % mod);
			
			}
		}
		
		memcpy(f[x] , tmpf , sizeof (int) *  (sz[x] + sz[y] + 1));
		memcpy(g[x] , tmpg , sizeof (int) *  (sz[x] + sz[y] + 1));
		
		
		sz[x] += sz[y];
	}
	
	for (int i = 1;i <= sz[x];i++){
		ans[i] = add(ans[i] , 1ll * sub(1 , p[pa]) * g[x][i] % mod);
	}
}
int main(){
	scanf("%d",&n);
	for (int i = 1;i < n;i++){
		int u , v;scanf("%d%d",&u,&v);
		adde(u , v);
		adde(v , u);
	}
	
	int suma = 0;
	for (int i = 1;i <= n;i++){
		scanf("%d%d%d",a+i,b+i,c+i);
		suma = add(suma , a[i]);
		p[i] = 1ll * b[i] * qpow(c[i] , mod - 2) % mod;
	}
	
	suma = qpow(suma , mod - 2);
	for (int i = 1;i <= n;i++){
		q[i] = 1ll * a[i] * suma % mod;
//		printf("fafa %d %d %d\n",i,p[i],q[i]);
	}
	
	dfs(1 , 0);
	
	for (int i = 1;i <= n;i++) printf("%d\n",ans[i]);
	return 0;
}

