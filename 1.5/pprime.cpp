/*
TASK:pprime
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int a, b;

bool isprime(int x)
{
	if(x%2==0) return 0;
	for(int i=3; i*i<=x; i+=2) if(x%i==0) return 0;
	return 1;
}

int Modify(int x)
{
	int t=x; x/=10;
	while(x>0)
	{
		t=t*10+x%10;
		x/=10;
	}
	return t;
}

int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	
	scanf("%d%d", &a, &b);
	int i, j, k;
	if(a<=5 && 5<=b) printf("5\n");
	if(a<=7 && 7<=b) printf("7\n");
	if(a<=11 && 11<=b) printf("11\n");
	i=10;
	while(Modify(i)<a) i++;
	while(Modify(i)<=b)
	{
		k=i; j=1;
		while(k>9) {k/=10; j*=10;}
		if(k%2==0) {i+=j; continue;}
		j=Modify(i);
		if(isprime(j)) printf("%d\n", j);
		i++;
	}
	
	return 0;
}
