/*
TASK:sprime
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int n;

bool isprime(int x)
{
	if(x==1) return 0;
	for(int i=2; i*i<=x; i++)
		if(x%i==0) return 0;
	return 1;
}

void check(int m, int i)
{
	if(!isprime(m)) return;
	if(i<n)
		for(int t=0; t<=9; t++)
			check(m*10+t,i+1);
	if(i==n) printf("%d\n", m);
}

int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	
	scanf("%d", &n);
	for(int i=1; i<=9; i++)
		check(i,1);
	
	return 0;
}
