#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using pp=pair<int,int>;
int t,n,m,fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}},fx1[4][2]={{1,1},{-1,1},{1,-1},{-1,-1}};
string s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		for (int i=0;i<n;i++) cin>>s[i];
		vector<vector<int>>bz(n,vector<int>(m)),f(n,vector<int>(m,1e9));
		vector<vector<pp>>g(n,vector<pp>(m));
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
			if (s[i][j]=='#')
			{
				for (int k=0;k<4;k++)
				{
					int x=i+fx[k][0],y=j+fx[k][1];
					if (x<0 || x>=n || y<0 || y>=m) continue;
					bz[x][y]=1;
				}
			}
		priority_queue<pair<int,pp>>q;
		for (int i=0;i<n;i++) 
			if (!bz[i][0] || s[i][0]=='#') 
			{
				f[i][0]=s[i][0]!='#';
				q.push({-f[i][0],{i,0}});
			}
		while (!q.empty())
		{
			auto t=q.top();
			q.pop();
			int x=t.second.first,y=t.second.second;
			if (f[x][y]!=-t.first) continue;
			for (int k=0;k<4;k++)
			{
				int xx=x+fx1[k][0],yy=y+fx1[k][1];
				if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
				if (bz[xx][yy]) continue;
				if (f[x][y]+(s[xx][yy]!='#')<f[xx][yy])
				{
					f[xx][yy]=f[x][y]+(s[xx][yy]!='#');
					g[xx][yy]={x,y};
					q.push({-f[xx][yy],{xx,yy}});
				}
			}
		}
		int ans=1e9,x=-1,y=m-1;
		for (int i=0;i<n;i++) if (f[i][m-1]<ans) ans=f[i][m-1],x=i;
		if (ans>1e8) cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			s[x][y]='#';
			while (y)
			{
				auto t=g[x][y];
				x=t.first,y=t.second;
				s[x][y]='#';
			}
			for (int i=0;i<n;i++) cout<<s[i]<<'\n';
		}
	}
	return 0;
}


