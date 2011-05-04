/*
TASK:nocows
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

void init();
void solve();
void print();

int n,m;
int dp[201][101];
const int p=9901;

int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	
	init();
	solve();
	print();
	
	return 0;	
}

void init()
{
	scanf("%d%d", &n ,&m);
	for(int i=1; i<=m; i++) dp[1][i]=1;
}

void solve()
{
	for(int j=1; j<=m; j++)
		for(int i=2; i<=n; i++)
			for(int k=1; k<=i-2; k++)
			{
				dp[i][j]+=dp[k][j-1]*dp[i-k-1][j-1];
				dp[i][j]%=p;
			}
}

void print()
{
	printf("%d\n", (dp[n][m]-dp[n][m-1]+p)%p);
}
