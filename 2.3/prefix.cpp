/*
TASK:prefix
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string s="";
bool f[200001];
string a[201];
int tot,len;


void init();
void solve();
void print();

int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	
	init();
	solve();
	print();
	
	return 0;
}

void init()
{
	string ss;
	cin >>ss;
	while(ss!=".")
	{
		a[tot++]=ss;
		cin >>ss;
	}
	while(cin >>ss) s=s+ss;
}

void solve()
{
	len=s.length(); f[0]=1;
	for(int i=0; i<len; i++)
		for(int j=0; j<tot; j++)
			if(a[j].length()<=i+1)	
				if(s.substr(i-a[j].length()+1,a[j].length())==a[j])
					if(f[i-a[j].length()+1])
					{
						f[i+1]=1; break;
					}
}

void print()
{
	for(int i=len; i>=0; i--)
		if(f[i])
		{
			printf("%d\n", i);
			break;
		}
}
