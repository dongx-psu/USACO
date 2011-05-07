/*
TASK:comehome
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

class ntype
{
    public:
        int data,next,w;
};

void init();
void solve();
void print();
void connect(int,int,int);

ntype node[30001];
int g[101],q[100001],dis[101];
bool vis[101];
const int inf=10000000;
int tot,m;

int main()
{
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);

    init();
    solve();
    print();

    return 0;
}

void connect(int x,int y,int w)
{
    tot++; node[tot].data=y; node[tot].w=w;
    node[tot].next=g[x]; g[x]=tot;
}

void init()
{
    scanf("%d\n", &m);
    for(int i=0; i<m; i++)
    {
        char x,y;
        int w;
        scanf("%c%c%c%d\n", &x, &y, &y, &w);
        connect(x-'A',y-'A',w);
        connect(y-'A',x-'A',w);
    }
}

void solve()
{
    int front=0,rear=0;
    for(int i=0; i<='z'-'A'; i++)
        dis[i]=inf;
    q[front]='Z'-'A'; dis['Z'-'A']=0; vis['Z'-'A']=1;
    while(front<=rear)
    {
        int p=g[q[front]];
        while(p)
        {
            if(dis[node[p].data]>dis[q[front]]+node[p].w)
            {
                dis[node[p].data]=dis[q[front]]+node[p].w;
                if(!vis[node[p].data])
                {
                    rear++;
                    q[rear]=node[p].data;
                    vis[node[p].data]=1;
                }
            }
            p=node[p].next;
        }
        vis[q[front]]=0;
        front++;
    }
}

void print()
{
    int res=inf;
    char ch;
    for(int i=0; i<'Z'-'A'; i++)
        if(res>dis[i])
        {
            res=dis[i];
            ch=(char)(i+'A');
        }
    printf("%c %d\n", ch, res);
}
