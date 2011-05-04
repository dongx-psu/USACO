/*
TASK:money
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

void init();
void solve();
void print();

int n,m;
long long f[10001];
int w[25];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	init();
	solve();
	print();
	
	return 0;
}

void init()
{
	scanf("%d%d", &n ,&m);
	for(int i=0; i<n; i++)	scanf("%d", &w[i]);
}

void solve()
{
	f[0]=1;
	for(int i=0; i<n; i++)
		for(int j=w[i]; j<=m; j++)
			f[j]+=f[j-w[i]];
}

void print()
{
	cout <<f[m] <<endl;
}
