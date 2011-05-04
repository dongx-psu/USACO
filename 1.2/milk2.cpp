/*
TASK:milk2
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct ttype
{
  int s,t;
}a[5001];

bool cmp(ttype x, ttype y)
{
  return x.s<y.s;
}

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
      
    int n, i, ans1=0, ans2=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
      scanf("%d%d", &a[i].s, &a[i].t);
    sort(a, a+n, cmp);
    
    int st=a[0].s, ed=a[0].t;
    for(i=0; i<n; i++)
    {
             while(i<n && a[i].s<=ed)
             {
                       if (a[i].t>ed) ed=a[i].t;
                       i++;
             }
             if(ed-st>ans1) ans1=ed-st;
             if(i==n) break;
             if (a[i].s-ed>ans2) ans2=a[i].s-ed;
             st=a[i].s; ed=a[i].t;
    } 
    
    printf("%d %d\n", ans1, ans2);
    
    return 0;
}
