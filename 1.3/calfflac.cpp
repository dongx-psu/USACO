/*
TASK:calfflac
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int n=0, i;
char s[20010];
int ans=1, first=0, last=0;

bool chin(char x)
{
	return((x>='a' && x<='z')||(x>='A' && x<='Z'));
}

bool conv(char x, char y)
{
	int a,b;
	if(x>='a' && x<='z') a=x-'a'+1;
	else a=x-'A'+1;
	if(y>='a' && y<='z') b=y-'a'+1;
	else b=y-'A'+1;
	return (a==b); 
}

void check(int odd)
{
	int l=i, r=i+odd, now, ll, rr;
	if(odd)
	{
		while(r<n && !chin(s[r])) r++;
		if(r>=n || !conv(s[r],s[l])) return;
		now=0;
	}
	else now=-1;
	while(l>=0 && r<n && conv(s[l],s[r]))
	{
		ll=l; rr=r;
		now+=2; l--; r++;
		while(l>=0 && !chin(s[l])) l--;
		while(r<n && !chin(s[r])) r++;
	}
	if(now>ans)
	{
		first=ll; last=rr; ans=now;
	}

}

int main()
{
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	while(EOF!=scanf("%c", &s[n++]));
	for(i=0; i<n; i++)
	{
		if(!chin(s[i])) continue;
		check(0);
		check(1);
	}
	
	printf("%d\n", ans);
	for(i=first; i<=last; i++) printf("%c", s[i]);
	printf("\n");
	
	return 0;
}
