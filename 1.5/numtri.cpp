/*
TASK:numtri
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int n;
int a[1001][1001], f[1001][1001];

int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	
	scanf("%d", &n);
	int i,j;
	for(i=0; i<n; i++)
	  for(j=0; j<=i; j++)
	    scanf("%d", &a[i][j]);
   
    for(i=0; i<n; i++)
	   	for(j=0; j<=i; j++)
	   		f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
	
	int res=0;
	for(i=0; i<n; i++) res=max(res,f[n-1][i]);
	printf("%d\n", res);
	
	return 0;
}
