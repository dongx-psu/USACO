/*
TASK:frac1
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct frac
{
	int s,t;
	double d;
}a[25600];
int n,tot;

bool cmp(frac x, frac y)
{
	return x.d<y.d;
}

bool check(int x, int y)
{
	if(y==1) return 1;
	else
	{
		for(int i=y; i>=2; i--)
			if(x%i==0 && y%i==0) return 0;
		return 1;	
	}	
}

int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	
	scanf("%d", &n);
	for(int i=n; i>=2; i--)
		for(int j=1; j<i; j++)
			if(check(i,j))
			{
				a[tot].s=j;
				a[tot].t=i;
				a[tot].d=(float)j/(float)i;
				tot++;
			}
	a[tot].s=0; a[tot].t=1; a[tot].d=0;
	a[tot+1].s=1; a[tot+1].t=1; a[tot+1].d=1;
	tot+=2;
	
	sort(a,a+tot-1,cmp);
	
	for(int i=0; i<tot; i++)
 		printf("%d/%d\n", a[i].s, a[i].t);
 	
	 return 0;	
}
