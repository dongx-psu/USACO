/*
TASK:hamming
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int n,b,d,now;
int ans[20];

inline int dist(int,int);
inline int lowbit(int);

int main()
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	
	scanf("%d%d%d", &n, &b, &d);
	ans[0]=0; now=1;
	bool flag;
	do
	{
		int next=ans[now-1];
		do
		{
			next++;	flag=1;
			for(int i=0; i<now; i++)
			{
				if(dist(next,ans[i])<d)
				{
					flag=0; break;
				}
			}	
		}while(!flag);	
		ans[now++]=next;
	}while(now<n);
	
	for(int i=0; i<n; i++)
	{
		if((i+1)%10==0||i==n-1) printf("%d\n", ans[i]);
		else printf("%d ", ans[i]);
	}
	
	return 0;
}

int lowbit(int x)
{
	return x&-x;
}

int dist(int x, int y)
{
	int tmp=x^y, tot=0;
	while(tmp>0)
	{
		tot++; tmp-=lowbit(tmp);	
	}
	return tot;
}
