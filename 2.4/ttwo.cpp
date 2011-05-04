/*
TASK:ttwo
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

class sit
{
	public:
		sit(int,int,int);
		sit(){}
		int getx(){return x;}
		int gety(){return y;}
		int getd(){return dis;}
		void setx(int tx){x=tx;}
		void sety(int ty){y=ty;}
		void setd(int td){dis=td;}
	private:
		int x,y,dis;
};

sit::sit(int tx, int ty, int td)
{
	x=tx; y=ty; dis=td;
}

void init();
void solve();
void print();
void move(sit&);
char map[11][11];
int step;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
sit farmer,cows;

int main()
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	
	init();
	solve();
	print();

	return 0;
}

void init()
{
	for(int i=0; i<10; i++)
	{	
		for(int j=0; j<10; j++)
		{	
			scanf("%c", &map[i][j]);
			if(map[i][j]=='F')
			{
				sit tmp(i,j,0);
				farmer=tmp;
			}
			else if(map[i][j]=='C')
			{
				sit tmp(i,j,0);
				cows=tmp;
			}
		}
		scanf("\n");
	}
}

void solve()
{
	step=0;
	do
	{
		move(farmer); move(cows);
		step++;
	}while(step<=160000&&(!((farmer.getx()==cows.getx())&&(farmer.gety()==cows.gety()))));
}

void print()
{
	if(step>160000) step=0;
	printf("%d\n", step);
}

void move(sit &now)
{
	int tx=now.getx()+dx[now.getd()];
	int ty=now.gety()+dy[now.getd()];
	if(tx>=0&&tx<10&&ty>=0&&ty<10&&map[tx][ty]!='*')
	{
		now.setx(tx); now.sety(ty);
	}
	else now.setd((now.getd()+1)%4);
}
