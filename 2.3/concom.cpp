/*
TASK:concom
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void init();
void solve();
void dfs(int);
int per[101];
bool vis[101],own[101];
int g[101][101];
int n,m;


int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	
	init();
	solve();
	
	return 0;
}

void init()
{
	scanf("%d", &m);
	int x,y,w;
	for(int i=0; i<m; i++)
	{
		scanf("%d%d%d", &x, &y, &w);
		n=n<x?x:n; n=n<y?y:n;
		--x; --y; g[x][y]=w;
	}
}

void solve()
{
	for(int i=0; i<n; i++)
	{
		memset(vis,0,sizeof(vis));
		memset(per,0,sizeof(per));
		memset(own,0,sizeof(own));
		own[i]=1;
		dfs(i);
		for(int j=0; j<n; j++)
			if(i!=j && own[j])
				printf("%d %d\n", i+1, j+1);
	}
}

void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	for(int i=0; i<n; i++)
	{
		per[i]+=g[x][i];
		if(per[i]>50)
		{
			own[i]=1;
			dfs(i);
		}
	}
}
