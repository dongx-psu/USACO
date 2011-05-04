/*
TASK:sort3
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int n,tot,x;
int con[4], res[4];
int a[1001];

int main()
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &x);
		con[x]++; a[++tot]=x;
	}	
	for(int i=1; i<=con[1]+con[2]; i++)
	{
		if(a[i]==3) res[3]++;
		else if(a[i]==2 && i<=con[1]) res[1]++;
		else if(a[i]==1 && i>con[1]) res[2]++;
	}
	
	printf("%d\n", res[3]+(res[1]>res[2]?res[1]:res[2]));
	
	return 0;
}
