/*
TASK:checker
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int n, aim, ans;
int a[20];

void dfs(int row, int ld, int rd, int i)
{
	int p, pos;
	if(row!=aim)
	{
		pos=aim&(~(row|ld|rd));
		while(pos!=0)
		{
			p=pos&(pos^(pos-1));
			pos-=p;
			if(ans<3)
			{
				int l=1, k=p;
				while(k!=1)
				{
					k=k>>1;
					l++;
				}
				a[i]=l;
			}
			dfs(row|p,(ld|p)<<1,(rd|p)>>1,i+1);
		}
	}
	else
	{
		ans++;
		if(ans<=3)
		{
			printf("%d", a[1]);
			for(int k=2; k<=n; k++)
				printf(" %d", a[k]);
			printf("\n");	
		}
	}
}

int main()
{
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);

	scanf("%d", &n);
	aim=(1<<n)-1;
	dfs(0,0,0,1);
	printf("%d\n", ans);
	
	return 0;
}
