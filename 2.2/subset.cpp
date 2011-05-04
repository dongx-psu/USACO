/*
TASK:subset
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int n,sum;
long long f[1000];

int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	
	scanf("%d", &n);
	sum=n*(n+1)/2;
	f[0]=1;
	if(sum%2!=0) printf("0\n");
	else
	{
		for(int i=1; i<=n; i++)
			for(int j=sum/2; j>=i; j--)
				f[j]+=f[j-i];
		printf("%d\n", f[sum/2]/2);
	}
	
	return 0;
}
