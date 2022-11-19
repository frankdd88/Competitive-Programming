#include<bits/stdc++.h>
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
// #define pii pair<LL,LL>
using namespace std;
const int N=5e5+50;
int T,n,q,a[N],t;
int id[N*4],cov[N*4];
ULL c[N*4],sc[N*4],ans[N],laz1[N*4],laz2[N*4];
void up(int x){
	int L=x<<1,R=x<<1|1;
	c[x]=c[L]+c[R];
	sc[x]=sc[L]+sc[R];
	id[x]=id[L]==id[R]?id[L]:0;
}
void mdf1(int x,int d){id[x]=cov[x]=d;}
void mdf2(int x,int l,int r,ULL d1,ULL d2){
	c[x]+=(r-l+1)*d1,sc[x]+=(r-l+1)*d2;
	laz1[x]+=d1;laz2[x]+=d2;
}
void down(int x,int l,int r){
	int L=x<<1,R=x<<1|1,mid=(l+r)>>1;
	if(cov[x])mdf1(L,cov[x]),mdf1(R,cov[x]),cov[x]=0;
	if(laz1[x]||laz2[x])
		mdf2(L,l,mid,laz1[x],laz2[x]),mdf2(R,mid+1,r,laz1[x],laz2[x]),laz1[x]=0,laz2[x]=0;
}
void build(int x,int l,int r){
	if(l==r){id[x]=a[l];return;}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	up(x);
}
void change1(int x,int l,int r,int ql,int qr,int d){
	if(l>=ql&&r<=qr&&id[x]){
		ans[id[x]]+=c[x]*(t-1)-sc[x];
		ans[d]-=c[x]*(t-1)-sc[x];
		mdf1(x,d);
		return;
	}
	int mid=(l+r)>>1;down(x,l,r);
	if(ql<=mid)change1(x<<1,l,mid,ql,qr,d);
	if(qr>mid)change1(x<<1|1,mid+1,r,ql,qr,d);
	up(x);
}
void change2(int x,int l,int r,int ql,int qr,int d){
	if(l>=ql&&r<=qr){
		mdf2(x,l,r,d,1ll*d*(t-1));
		return;
	}
	int mid=(l+r)>>1;down(x,l,r);
	if(ql<=mid)change2(x<<1,l,mid,ql,qr,d);
	if(qr>mid)change2(x<<1|1,mid+1,r,ql,qr,d);
	up(x);
}
void solve(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	t=0;build(1,1,n);int op,l,r,x;
	for(t=1;t<=q;t++){
		scanf("%d%d%d%d",&op,&l,&r,&x);
		if(op==1)change1(1,1,n,l,r,x);
		else change2(1,1,n,l,r,x);
	}
	change1(1,1,n,1,n,n+1);
	for(int i=1;i<=n;i++)
		printf("%llu ",ans[i]);
}
int main(){
	#ifdef local
	freopen("in.txt","r",stdin);
	#endif
	// scanf("%d",&T);
	T=1;
	while(T--)solve();
	return 0;
}
