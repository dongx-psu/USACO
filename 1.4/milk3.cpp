/*
TASK:milk3
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int a,b,c;
bool s[21][21];

void dfs(int ma, int mc)
{
     if(s[ma][mc]) return;
     s[ma][mc]=1;
     int mb=c-ma-mc;
     dfs(ma-min(ma,b-mb),mc);
     dfs(ma-min(ma,c-mc),mc+min(ma,c-mc));
     dfs(ma+min(mb,a-ma),mc);
     dfs(ma,mc+min(mb,c-mc));
     dfs(ma+min(mc,a-ma),mc-min(mc,a-ma));
     dfs(ma,mc-min(mc,b-mb));
}

int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    scanf("%d%d%d", &a, &b, &c);
    dfs(0,c);
    int i,j;
    for(i=0; i<=c; i++)
      if(s[0][i])
      {
                printf("%d", i);
                break;
      }
    for(j=i+1; j<=c; j++)
      if(s[0][j]) printf(" %d", j);
    printf("\n");
    
    return 0;
}
