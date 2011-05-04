/*
TASK:holstein
LANG:C++
*/ 
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int n,m,best;
int c[26],a[16][26],nNow[26],tmp[16],ans[16];

inline bool check();
void dfs(int,int);

int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &c[i]);
	scanf("%d", &m);
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &a[i][j]);		
	best=m+1;
	memset(nNow,0,sizeof(nNow));
	dfs(0,0);
	printf("%d", best);
	for(int i=0; i<best; i++)
		printf(" %d", ans[i]+1);
	printf("\n");
	
	return 0;	
}

bool check()
{
	for(int i=0; i<n; i++)
		if(nNow[i]<c[i]) return 0;
	return 1;
}

void dfs(int step, int now)
{
	if(step==m)
	{
		if(now<best&&check())
		{
			best=now;
			memcpy(ans,tmp,sizeof(tmp));
		}
		return;
	}
	for(int i=0; i<n; i++)
 		nNow[i]+=a[step][i];
	tmp[now]=step;
	dfs(step+1, now+1);
	tmp[now]=0;
	for(int i=0; i<n; i++)
 		nNow[i]-=a[step][i];	 
	dfs(step+1, now);
}
