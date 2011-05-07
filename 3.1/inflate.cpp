/*
TASK:inflate
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

void init();
void solve();
void print();
int f[10001],c[10001],t[10001];
int n,m;

int main()
{
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	
	init();
	solve();
	print();
	
	return 0;	
}

void init()
{
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++)
		scanf("%d%d", &c[i], &t[i]);
}

void solve()
{
	for(int i=0; i<m; i++)
		for(int j=t[i]; j<=n; j++)
			f[j]=max(f[j],f[j-t[i]]+c[i]);
}

void print()
{
	printf("%d\n", f[n]);
}
