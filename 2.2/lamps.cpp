/*
TASK:lamps
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int ons[101],offs[101];
string ans[18],final[18];
int tot1,tot2,n,c,tot;
bool flag;

void init();
void solve();
void check(string);
void dfs1(string,int);
void dfs2(string,int);
void dfs3(string,int);
void dfs4(string,int);
void print();

int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	
	init();
	solve();
	print();
	
	return 0;
}

void init()
{
	scanf("%d%d", &n, &c);
	int x;
	scanf("%d", &x);
	while(x!=-1)
	{
		ons[tot1++]=x-1;
		scanf("%d", &x);
	}
	scanf("%d", &x);
	while(x!=-1)
	{
		offs[tot2++]=x-1;
		scanf("%d", &x);
	}
}

void solve()
{
	string state(n,'1');
	check(state);
	if(c>=1) dfs1(state,1);
	sort(ans,ans+tot);
	if(flag)
	{
		final[0]=ans[0];
		int newtot=1;
		for(int i=1; i<tot; i++)
			if(ans[i]!=ans[i-1]) final[newtot++]=ans[i];
		tot=newtot;
	} 
}

void print()
{
	if(!flag) printf("IMPOSSIBLE\n");
	else
	{
		for(int i=0; i<tot; i++)
			cout <<final[i] <<endl;
	}
}

void check(string state)
{
	for(int i=0; i<tot1; i++)
		if(state[ons[i]]!='1') return;
	for(int i=0; i<tot2; i++)
		if(state[offs[i]]!='0') return;
	ans[tot++]=state; flag=1;	
}

void dfs1(string state,int x)
{
	string s=state;
	dfs2(s,x);
	for(int i=0; i<n; i++)
		s[i]='0'+'1'-s[i];
	check(s);
	if(x+1<=c) dfs2(s,x+1); 
}

void dfs2(string state,int x)
{
	string s=state;
	dfs3(s,x);
	for(int i=0; i<n; i+=2)
		s[i]='0'+'1'-s[i];
	check(s);
	if(x+1<=c) dfs3(s,x+1); 
}

void dfs3(string state,int x)
{
	string s=state;
	dfs4(s,x);
	for(int i=1; i<n; i+=2)
		s[i]='0'+'1'-s[i];
	check(s);
	if(x+1<=c) dfs4(s,x+1); 
}

void dfs4(string state,int x)
{
	string s=state;
	for(int i=0; i<n; i+=3)
		s[i]='0'+'1'-s[i];
	check(s);
}
