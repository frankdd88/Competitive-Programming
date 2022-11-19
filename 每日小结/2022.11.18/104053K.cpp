#include<bits/stdc++.h>
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
// #define pii pair<LL,LL>
using namespace std;
const int N=5e5+50,mod=1e9+7;
int T,n,m,d[N],cnt[N],c4,c3,ans;
vector<int>v[N],vv[N];
vector<int>st;
int read(){
	int x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x;
}
void solve(){
	scanf("%d%d",&n,&m);c3=c4=0;
	ans=1ll*m*(n+m-3)%mod;
	// cout<<ans<<endl;
	// if(n+m-3<0)ans=0;
	for(int i=1;i<=n;i++)
		v[i].clear(),vv[i].clear(),d[i]=0;
	for(int i=1,x,y;i<=m;i++){
		x=read();y=read();d[x]++,d[y]++;
		v[x].pb(y);v[y].pb(x);
	}
	for(int i=1;i<=n;i++)
		ans=(ans+1ll*d[i]*(d[i]-1)/2)%mod;
	// cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		for(int j=0;j<v[i].size();j++){
			int y=v[i][j];
			if(d[y]<d[i]||d[y]==d[i]&&y<i)
				vv[i].pb(y);
		}
	for(int i=1;i<=n;i++){
		for(int j=0;j<vv[i].size();j++){
			int x=vv[i][j];
			for(int k=0;k<v[x].size();k++){
				int y=v[x][k];
				if(d[y]<d[i]||d[y]==d[i]&&y<i){
					(c4+=cnt[y])%=mod;
					cnt[y]++;st.pb(y);
				}
			}
		}
		for(int j=0;j<st.size();j++)
			cnt[st[j]]=0;
		st.clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<vv[i].size();j++){
			int x=vv[i][j];
			for(int k=0;k<vv[x].size();k++){
				int y=vv[x][k];
				cnt[y]++;st.pb(y);
			}
		}
		for(int j=0;j<vv[i].size();j++){
			int x=vv[i][j];
			(c3+=cnt[x])%=mod;
		}
		for(int j=0;j<st.size();j++)
			cnt[st[j]]=0;
		st.clear();
	}
	// cout<<c3<<" "<<c4<<endl;
	printf("%d\n",(ans+3ll*c3+c4)%mod);
}
int main(){
	#ifdef local
	freopen("in.txt","r",stdin);
	#endif
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
