#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pii pair<LL,LL>
using namespace std;
const int N=5e5+50;
int n,m,a[N],c[N],cnt;LL f1[N],f2[N],ans[N];
void add(int x,int y){
	for(;x<=cnt;x+=x&-x)
		f1[x]+=y,f2[x]++;
}
pii ask(int x){
	LL z1=0,z2=0;
	for(;x;x-=x&-x)
		z1+=f1[x],z2+=f2[x];
	return mp(z1,z2);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),c[i]=a[i];
	sort(c+1,c+n+1);cnt=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(c+1,c+cnt+1,a[i])-c;
	for(int i=1;i<=n;i++){
		pii x=ask(a[i]);
		ans[i]+=x.second*(c[a[i]]+1)-x.first;
		add(a[i],c[a[i]]);
	}
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	for(int i=n;i;i--){
		pii x=ask(a[i]-1);
		ans[i]+=x.second*c[a[i]]-x.first;
		add(a[i],c[a[i]]);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]<m-1?ans[i]:-1);
	return 0;
}
