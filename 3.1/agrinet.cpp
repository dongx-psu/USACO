/*
TASK:agrinet
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

void init();
void solve();
void print();

int g[101][101];
int dis[101];
bool vis[101];
int n,ans;
const int inf=10000000;

int main()
{
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	
	init();
	solve();
	print();
	
	return 0;	
}

void init()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &g[i][j]);
}

void solve()
{
	for(int i=0; i<n; i++)
		dis[i]=g[0][i];
	vis[0]=1;
	for(int i=1; i<n; i++)
	{
		int minnow=inf,minj;
		for(int j=0; j<n; j++)
			if(!vis[j] && dis[j]<minnow)
			{
				minj=j; minnow=dis[j];
			}
		ans+=minnow; vis[minj]=1;
		for(int j=0; j<n; j++)
			if(!vis[j] && dis[j]>g[minj][j])
				dis[j]=g[minj][j];
	}
}

void print()
{
	printf("%d\n", ans);
}
