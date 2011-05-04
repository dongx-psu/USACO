/*
TASK:zerosum
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

void init();
void solve();
void dfs(int);
char ans[9];
int n,sum,last,counter;

int main()
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	
	init();
	solve();
	
	return 0;
}

void init()
{
	scanf("%d", &n);
}

void solve()
{
	sum=1; last=1;
	dfs(1);
}

void dfs(int step)
{
	if(step==n)
	{
		counter++;
		if(sum==0)
		{
			printf("1");
			for(int i=2; i<=n; i++)
				printf("%c%d" ,ans[i-1] ,i);
			printf("\n");
		}
		return;
	}
	int tsum=sum,tlast=last;
	ans[step]=' ';
	if(tlast>0) last=tlast*10+step+1;
	else last=tlast*10-step-1;
	sum=tsum-tlast+last;
	dfs(step+1);
	ans[step]='+';
	sum=tsum+step+1; last=step+1;
	dfs(step+1);
	ans[step]='-';
	sum=tsum-step-1; last=-step-1;
	dfs(step+1);
}
