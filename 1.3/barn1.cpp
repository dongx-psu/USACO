/*
TASK:barn1
LANG:C++
*/
#include<fstream>
#include<algorithm>
#include<cstdio>
using namespace std;

ifstream fin("barn1.in");
ofstream fout("barn1.out");
int m,s,c;
int a[201],b[201];

int main()
{
	fin >>m >>s >>c;
	for(int i=0; i<c; i++) fin >>a[i];
	sort(a,a+c);
	for(int i=0; i<c-1; i++) b[i]=a[i+1]-a[i]-1;
	sort(b,b+c-1);
	int ans=c;
	for(int i=0; i<c-m; i++) ans+=b[i];
	fout <<ans <<endl;
	
	return 0;
}
