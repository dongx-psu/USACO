/*
TASK:maze1
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

class point
{
	public:
		point(){}
		point(int,int);
		int x,y;
};

point::point(int tx, int ty)
{
	x=tx; y=ty;
}

int min(int x, int y)
{
	return x<y?x:y;
}
int max(int x, int y)
{
	return x>y?x:y;
}
void init();
void solve();
void print();
void bfs(point,int);

int w,h,tot,res;
bool map[101][39][4];
int dis[3][101][39];
bool vis[101][39];
point blank[3],q[3801];
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int inf=10000000;

int main()
{
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	
	init();
	solve();
	print();
	
	return 0;
}

void init()
{
	scanf("%d%d\n", &w ,&h);
	for(int i=1; i<=2*h+1; i++)
	{
		string s;
		getline(cin,s);
		if(i%2==1)
		{
			for(int j=1; j<=2*w+1; j++)
			{
				if(j%2==0 && s[j-1]==' ')
				{
					if(i<2*h+1) map[(i+1)/2][j/2][0]=1;
					else
					{
						point tmp((i-1)/2,j/2);
						blank[tot++]=tmp;
					}
					if(i>1) map[(i-1)/2][j/2][2]=1;
					else
					{
						point tmp((i+1)/2,j/2);
						blank[tot++]=tmp;
					}
				}
			}
		}
		else
		{
			for(int j=1; j<=2*w+1; j++)
			{
				if(j%2==1 && s[j-1]==' ')
				{
					if(j<2*w+1) map[i/2][(j+1)/2][3]=1;
					else
					{
						point tmp(i/2,(j-1)/2);
						blank[tot++]=tmp;
					}
					if(j>1)
						map[i/2][(j-1)/2][1]=1;
					else
					{
						point tmp(i/2,(j+1)/2);
						blank[tot++]=tmp;
					}
				}
			}
		}
	}
}

void solve()
{
	for(int i=0; i<2; i++)
		for(int j=1; j<=h; j++)
			for(int k=1; k<=w; k++)
				dis[i][j][k]=inf;
	for(int i=0; i<2; i++)
		bfs(blank[i],i);
	res=0;
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			res=max(res,min(dis[0][i][j],dis[1][i][j]));
}

void bfs(point now, int num)
{
	dis[num][now.x][now.y]=1;
	memset(vis,0,sizeof(vis));
	vis[now.x][now.y]=1;
	int front=1,rear=1;
	q[front].x=now.x; q[front].y=now.y;
	while(front<=rear)
	{
		for(int i=0; i<4; i++)
			if(map[q[front].x][q[front].y][i])
			{
				int tx=q[front].x+dx[i];
				int ty=q[front].y+dy[i];
				if(tx>=1 && ty>=1 && tx<=h && ty<=w && !vis[tx][ty])
				{
					rear++;
					q[rear].x=tx; q[rear].y=ty;
					dis[num][tx][ty]=dis[num][q[front].x][q[front].y]+1;
					vis[tx][ty]=1;
				}
			}
		front++;
	}
}

void print()
{
	printf("%d\n", res);
}
