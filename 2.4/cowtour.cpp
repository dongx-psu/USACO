/*
TASK:cowtour
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

void init();
void solve();
void print();
double dist(int,int);

const int maxn=151;
const double inf=1e9;
int x[maxn],y[maxn];
int n;
double res;
double g[maxn][maxn],c[maxn];

int main()
{
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    
    init();
    solve();
    print();
    
    return 0;
}

double dist(int i,int j)
{
    double ans=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    return ans;
}

void init()
{
    scanf("%d\n", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d\n", &x[i], &y[i]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            char ch;
            scanf("%c", &ch);
            if(ch=='0') g[i][j]=inf;
            else g[i][j]=dist(i,j);
        }
        scanf("\n");
    }
    for(int i=0; i<n; i++) g[i][i]=0;
}

void solve()
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(g[i][j]!=inf && g[i][j]>c[i]) c[i]=g[i][j];
    double res1=0;
    for(int i=0; i<n; i++)
        if(res1<c[i]) res1=c[i];
    double res2=inf;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(g[i][j]==inf && c[i]+c[j]+dist(i,j)<res2)
                res2=c[i]+c[j]+dist(i,j);  
    if(res1>res2) res=res1;
    else res=res2;  
}

void print()
{
    printf("%.6f\n", res);    
}
