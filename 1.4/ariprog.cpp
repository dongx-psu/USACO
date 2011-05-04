/*
TASK:ariprog
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int n, m, tot=0;
bool flag=false;
bool exist[125001];
int path[5001][101], list[40001], l[5001];

int main()
{
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	
	int i, j;
	scanf("%d%d", &n, &m);
	memset(exist,0, sizeof(exist));
	memset(path, -1, sizeof(path));
	for(i=0; i<=m; i++)
	  for(j=i; j<=m; j++) exist[i*i+j*j]=true;
	for(i=2*m*m; i>=0; i--)
 		if(exist[i])
 		{
		 	list[tot]=i; tot++;
		}
	for(i=0; i<tot-1; i++)
		for(j=i+1; j<tot; j++)
		{
			int ln=1, d=list[i]-list[j];
			int next=list[i]-d;
			if(list[i]-(n-1)*d<0) break;
			while(1)
			{
				ln++;
				if(ln>=n)
				{
					path[d][l[d]]=next;	l[d]++;
				}
				next-=d;
				if(next<0 || !exist[next]) break;
			}
		}
	for(int k=1; k<5001; k++)
		if(l[k]>1)
			for(i=0; i<l[k]; i++)
				for(j=i; j<l[k]; j++)
					if(path[k][i]>path[k][j])
					  swap(path[k][i],path[k][j]);
	for(i=1; i<5001; i++)
 		for(j=0; j<l[i]; j++)
 			if(path[i][j]!=path[i][j+1])
 			{
			 	flag=true;
			 	printf("%d %d\n", path[i][j], i);
			 }
	if(!flag) printf("NONE\n");
	
	return 0;
}
