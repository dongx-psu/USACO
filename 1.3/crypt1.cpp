/*
TASK:crypt1
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int n, a[11];

bool check(int x)
{
     while(x>0)
     {
               if(!a[x%10]) return 0;
               x/=10;
     }
     return 1;
}

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    
    int x;
    scanf("%d", &n);
    memset(a,0,sizeof(a));
    for(int i=0; i<n; i++) scanf("%d", &x), a[x]=1;
    
    int ans=0;
    for(int i=100; i<1000; i++)
      for(int j=10; j<100; j++)
        {
              if(i*(j/10)>999 || i*(j%10)>999) continue;
              if(check(i) && check(j) && check(i*j)
              && check(i*(j/10)) && check(i*(j%10))) ans++;
        }
    printf("%d\n", ans);
    
    return 0;
}
