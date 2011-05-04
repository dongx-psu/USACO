/*
TASK:runround
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int n,now;

bool check(int);

int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	
	scanf("%d", &n);
	now=n;
	while(!check(++now));
	printf("%d\n", now);
	
	return 0;
}

bool check(int now)
{
	bool v[10],vis[10];
	memset(v,0,sizeof(v));
	int tot=0,x=now;
	while(x>0)
	{
		if(0==x%10) return 0;
		if(1==v[x%10]) return 0;
		v[x%10]=1; x/=10; tot++;
	}
	memset(vis,0,sizeof(vis));
	int i=1,k=0;
	do
	{
		k++; vis[i]=1; x=now;
		for(int p=1; p<=tot-i; p++) x/=10;
		int j=x%10;
		i=(i+j-1)%tot+1;
	}while(!vis[i]);
	if(i==1&&k==tot) return 1;
	else return 0;	
}
