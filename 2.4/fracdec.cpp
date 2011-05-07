/*
TASK:fracdec
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

class dtype
{
	public:
		int v,m;	
};

void init();
void solve();
void print();
int n,d;
string st;
dtype data[50001];
bool flag[100001];

int main()
{
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    
    init();
    solve();
    print();
    
    return 0;
}

void init()
{
    scanf("%d%d", &n, &d);
}

void solve()
{
    int m,top=1;
    data[top].v=n/d;
	m=n%d; data[top].m=m;
    while(m>0 && !flag[m])
    {
    	flag[m]=1;
    	top++; data[top].v=10*m/d;
    	m=(10*m)%d; data[top].m=m;
    }
   	stringstream buf;
   	buf <<data[1].v <<'.';
   	buf >>st;
	if(top==1) st=st+'0';
	else if(m==0)
	{
		for(int i=2; i<=top; i++)
			st=st+(char)(data[i].v+'0');
	}
	else if(flag[m])
	{
		if(m==data[1].m) st=st+'(';
		for(int i=2; i<top; i++)
			if(data[i].m==m) st=st+(char)(data[i].v+'0')+'(';
			else st=st+(char)(data[i].v+'0');
		st=st+(char)(data[top].v+'0')+')';
	}
}

void print()
{
	int i;
	for(i=0; i<st.length(); i++)
	{
		printf("%c", st[i]);
		if(i%76==75) printf("\n");
	}
	if(i%76!=75) printf("\n");
}
